#include <iostream>
#include <vector>
#include <algorithm>

// Binárisan indexelt fa megvalósítása két művelettel
class BITree
{
public:
	BITree(std::size_t n)
		:size{ n + 1 },
		arr{ new uint64_t[n + 1] }
	{
		for (unsigned i = 0; i < size; ++i) {
			arr[i] = 0;
		}
	}

	~BITree()
	{
		delete[] arr;
	}

	uint64_t read(unsigned idx) {
		uint64_t sum = 0;
		while (idx > 0) {
			sum += arr[idx];
			idx -= lastBit(idx);
		}
		return sum;
	}

	void update(unsigned idx, uint64_t val) {
		while (idx < size) {
			arr[idx] += val;
			idx += lastBit(idx);
		}
	}

private:
	unsigned lastBit(int idx)
	{
		return idx & -idx;
	}

	std::size_t size;
	uint64_t* arr;
};


// Elemek átalakítása a sorszámukká
void numbersToOrders(std::vector<unsigned>& numbers)
{
	auto sorted = numbers;
	std::sort(sorted.begin(), sorted.end());
	std::transform(numbers.begin(), numbers.end(), numbers.begin(), [&](unsigned number) {
		return std::lower_bound(sorted.begin(), sorted.end(), number) - sorted.begin() + 1;
	});
}

// Brute force megoldás
uint64_t brute(std::vector<unsigned>& numbers)
{
	uint64_t n = numbers.size();
	uint64_t count{ 0 };
	for (unsigned i = 0; i < n; ++i)
		for (unsigned j = i + 1; j < n; ++j)
			for (unsigned k = j + 1; k < n; ++k)
				if (numbers[i] > numbers[j] && numbers[j] > numbers[k]) {
					++count;
				}
	return count;
}

// Hatékony megoldás két binárisan indexelt fával
uint64_t efficient(std::vector<unsigned>& numbers)
{
	numbersToOrders(numbers);

	auto max = *std::max_element(numbers.begin(), numbers.end());
	auto tree  = BITree{ max };
	auto tree2 = BITree{ max };
	unsigned long long ret{ 0 };
	for (auto num = numbers.rbegin(); num < numbers.rend(); ++num) {
		auto curr = tree.read(*num - 1);
		tree.update(*num, 1);
		tree2.update(*num, curr);
		ret += tree2.read(*num - 1);
	}
	return ret;
}

int main()
{
	unsigned n;
	std::cin >> n;
	std::vector<unsigned> numbers;
	unsigned current;
	numbers.reserve(n);
	while (n--) {
		std::cin >> current;
		numbers.push_back(current);
	}
	//std::cout << brute(numbers) << "\n";
	std::cout << efficient(numbers) << "\n";
}