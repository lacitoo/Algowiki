import argparse
import shutil
import csv
import os
import os.path
import logging
import glob
import pathlib
import subprocess

CHECKER_CPP = r"""
#include <bits/stdc++.h>

#if __has_include(<experimental/filesystem>)
#include <experimental/filesystem>

namespace std::filesystem {
        using namespace std::experimental::filesystem;
}

#endif

namespace Utility {
	
	namespace task {
		#include "task.h"
	};
	
	class OutputConverter {
		
		private:
			std::ostringstream output;
			decltype(std::cout.rdbuf()) cout_buf;
			
			std::pair<size_t, std::string> process_sv(std::string sv) {
				
				sv.push_back(';');
				
				std::vector<std::string> parts;
				
				for (auto cpos = sv.find(';'); cpos != std::string::npos; cpos = sv.find(';')) {
					parts.push_back(sv.substr(0, cpos));
					sv.erase(0, cpos+1);
				}
				
				assert(parts.size() == 4);
				
				int points = std::stoi(parts[2]);
				
				return {points, parts[3]};
			}
			
			
			void convert_and_print() {
				
				auto line = output.str();
				
				while (line.size() && line.back() == '\n')
					line.pop_back();
				
				line.push_back(':');
				
				std::vector<std::string> subtask_verdicts;
				
				for (auto cpos = line.find(':'); cpos != std::string::npos; cpos = line.find(':')) {
					subtask_verdicts.push_back(line.substr(0, cpos));
					line.erase(0, cpos+1);
				}
				
				size_t points = 0;
				std::string msg = "|";
				
				for (const auto & sv : subtask_verdicts) {
					size_t p; std::string s;
					std::tie(p, s) = process_sv(sv);
				
					points += std::min((size_t)1, p);
					msg += " " + (s == "" ? "-" : s) + " |";
				}
				
				std::cout.precision(10);
				std::cout << points / (double)task::no_subtasks << std::endl;
				
				std::cerr << msg << std::endl;
			}	
		
		public:
			OutputConverter() {
				cout_buf = std::cout.rdbuf(output.rdbuf());
			}
			
			~OutputConverter() {
				std::cout.rdbuf(cout_buf);
				this->convert_and_print();
			}
	};

	class FileRemover {
		
		private:
			std::vector<std::filesystem::path> paths;
		
		public:
			
			void add(const std::filesystem::path & p) {
				paths.push_back(p);
			}
			
			~FileRemover () {
				for (const auto & p : paths)
					std::filesystem::remove_all(p);
			}
		
	};


	OutputConverter oc;
	FileRemover fr;
}

namespace ellen {
	#include "ellen.cpp"
}


int main(int argc, char *argv[]) {
	
	assert(argc == 1 + 3);
	
	std::filesystem::path tmpdir1 = std::tmpnam(nullptr);
	assert(std::filesystem::create_directory(tmpdir1));
	
	std::filesystem::path tmpdir2 = std::tmpnam(nullptr);
	assert(std::filesystem::create_directory(tmpdir2));
	
	std::filesystem::create_symlink(
		std::filesystem::absolute(std::filesystem::path(argv[1])),
		tmpdir1 / "in.999");
	
	std::filesystem::create_symlink(
		std::filesystem::absolute(std::filesystem::path(argv[2])),
		tmpdir1 / "out.999");
	
	std::filesystem::create_symlink(
		std::filesystem::absolute(std::filesystem::path(argv[3])),
		tmpdir2 / "out.999");
	
	
	std::string tmpdir1name = tmpdir1.string(),
				tmpdir2name = tmpdir2.string();
	
	char whatever[] = "999";
	
	char *new_argv[] = {
		argv[0],
		(char*) tmpdir1name.c_str(),
		(char*) tmpdir2name.c_str(),
		whatever,
	};
	
	
	Utility::fr.add(tmpdir1);
	Utility::fr.add(tmpdir2);
	

	return ellen::main(1 + 3, new_argv);
}
"""

TASK_H_TEMPLATE = r"""
const size_t no_subtasks = {};
"""

LANGUAGES_EXT = [".cpp", ".c", ".py", ".java", ".pas", ".vb", ".cs"]

class convert_dir_error(Exception):
	pass

def convert_dir(path):

	def parse_task_data(filename):
		with open(filename) as f:
			lines = [ [ x.strip() for x in l.strip().split(';') if x.strip() ] for l in f ]
		
		return {
			"title": lines[0][0].replace("\ufeff", ""),
			"n_input": int(lines[2][0]),
			"memory_limit": int(lines[2][1]) // 1024,
			"time_limit": float(lines[2][2]),
			"no_subtasks": int(lines[2][3]),
		}
	
	def mkdirnofailifexists(*args, **kwargs):
		try:
			return os.mkdir(*args, **kwargs)
		except FileExistsError as e:
			pass
	
	j = lambda x, y: os.path.join(x, y)
	getp = lambda x: j(path, x)
	e = lambda x: os.path.exists(getp(x))
	
	
	MUST_HAVE_FILES = [
		"feladat.txt",
		"feladat.pdf",
		"minta.zip",
		"ellen.cpp",
	]
	
	for filename in MUST_HAVE_FILES:
		if not e(filename):
			raise convert_dir_error(f"'{filename}' does not exist in '{path}'")
	
	
	task_data = parse_task_data(getp("feladat.txt"))
	
	task_data["name"] = os.path.basename(path).lower()
	
	
	dirname = j(os.path.dirname(path), task_data["name"] + "__yaml")
	
	getp2 = lambda x: j(dirname, x)
	
	mkdirnofailifexists(dirname)
	
	mkdirnofailifexists(getp2("check"))
	pathlib.Path(getp2(j("check", "checker.cpp"))).write_text(CHECKER_CPP)
	pathlib.Path(getp2(j("check", "task.h"))).write_text(TASK_H_TEMPLATE.format(task_data["no_subtasks"]))
	shutil.copy(getp("ellen.cpp"), getp2("check"))
	
	try:
		subprocess.run(
			["g++",
				"-std=c++17",
				"-static",
				"-O2",
				getp2(j("check", "checker.cpp")),
				"-lstdc++fs",
				"-o", getp2(j("check", "checker"))],
			stdin=subprocess.DEVNULL,
			stdout=subprocess.DEVNULL,
			stderr=subprocess.DEVNULL)
	except subprocess.CalledProcessError as e:
		raise convert_dir_error(f"failed to compile checker for '{path}': {e}")
	
	mkdirnofailifexists(getp2("input"))
	for f in glob.glob(getp("in.*")):
		shutil.copy(f, j(getp2("input"), f"input{int(f.split('.')[-1])-1}.txt"))
	
	mkdirnofailifexists(getp2("output"))
	for f in glob.glob(getp("out.*")):
		shutil.copy(f, j(getp2("output"), f"output{int(f.split('.')[-1])-1}.txt"))
	
	mkdirnofailifexists(getp2("sol"))
	for ext in LANGUAGES_EXT:

		if e("feladat" + ext):
			shutil.copy(getp("feladat" + ext), j(getp2("sol"), "solution" + ext))
		
		if e(task_data["name"] + ext):
			shutil.copy(getp(task_data["name"] + ext), j(getp2("sol"), "solution" + ext))
	
	mkdirnofailifexists(getp2("att"))
	shutil.copy(getp("minta.zip"), getp2("att"))
	
	mkdirnofailifexists(getp2("statement"))
	shutil.copy(getp("feladat.pdf"), j(getp2("statement"), "statement.pdf"))
	
	
	pathlib.Path(getp2("task.yaml")).write_text(
		f"""
name: "{task_data["name"]}"
title: "{task_data["title"]}"
time_limit: {task_data["time_limit"]}
memory_limit: {task_data["memory_limit"]}
n_input: {task_data["n_input"]}
infile: ""
outfile: ""
primary_language: "hu"
token_mode: "disabled"
score_type: "Sum"
score_type_parameters: 1
score_mode: "max"
total_value: {task_data["no_subtasks"] * task_data["n_input"]}
"""
	)
	

def main():
	
	logging.basicConfig(level=logging.INFO)
	
	def check_and_normalize_dir(name):
		if not os.path.isdir(name):
			raise argparse.ArgumentTypeError("'{}' is not a directory".format(name))
		
		return os.path.normpath(name)


	parser = argparse.ArgumentParser(description='Convert BIRO task directory to italy_yaml task directory.')
	
	parser.add_argument('task_dir', type=check_and_normalize_dir, nargs='+', help='BIRO task directory')
	
	
	args = parser.parse_args()

	for task_dir in args.task_dir:
		try:
			convert_dir(task_dir)
			logging.info(f"'{task_dir}' has been converted")
		except convert_dir_error as e:
			logging.error(f"failed to convert '{task_dir}': {e}")
	
if __name__ == "__main__":
	main()
