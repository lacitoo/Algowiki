using namespace std;
#include <iostream>
#include <vector>
#include <math.h>
#include <fstream>
#include "stdlib.h"

int n, k, m, c, vezetok[11], igenyek[16001] = { 0 }, hanyvezeto;

vector<int> setup(string fileName) {

	ifstream f(fileName.c_str());
	if (f.fail()) {
		cerr << "Invalid file name.\n";
		exit(1);
	}

	int e;

	vector<int> vec;
	while (f >> e) {
		vec.push_back(e);
		cout << e << " ";
	}

	cout << endl << endl;
	return vec;
}

void idoindit(int db) {
	int seged = db;
	for (int i = 1; i <= n; i++) {
		if (seged > 0 && vezetok[i] == -3) { vezetok[i] = m; seged--; }
	}
}

void idolevon() {
	for (int i = 1; i <= n; i++) {
		if (vezetok[i] != -3) {
			vezetok[i]--;
			//cout << "lefut";
			//cout << i << " " <<vezetok[i] << "\n";
			if (vezetok[i] == 0) {
				hanyvezeto++;
				vezetok[i] = -3;
			}
		}
	}
}

void beolvasas() {
	//vector<int> a = setup("input.txt");
	cin >> n >> k >> m >> c;
	for (int i = 0; i < c; i++) {
		//int b = a[i];
		int b;
		cin >> b;
		igenyek[b]++;
	}
	for (int i = 1; i <= n; i++) { vezetok[i] = -3; }
}

int main()
{
	beolvasas();

	int db = 0;

	hanyvezeto = n;

	for (int i = 0; i <= k; i++) {
		idolevon();/*
		cout << "i: " << i << " Elotte:";
		for (int j = 1; j <= n; j++) { cout << vezetok[j] << " "; }
		*/
		if (hanyvezeto != 0 && igenyek[i] != 0 ) {
			if (hanyvezeto > igenyek[i]) {
				hanyvezeto -= igenyek[i];
				idoindit(igenyek[i]);
				db = db + igenyek[i];
			}
			else {
				idoindit(hanyvezeto);
				db = db + hanyvezeto;
				hanyvezeto = 0;

			}
		}
		/*cout << " Utana: ";
		for (int j = 1; j <= n; j++) { cout << vezetok[j] << " "; }
		cout << "\n";*/
	}

	cout << db << endl;
}
// 10 20000 9 10000
// 2 10 4 6 1 2 2 5 6 7