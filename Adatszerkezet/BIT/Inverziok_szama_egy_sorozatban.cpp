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
	uint64_t ret{ 0 };
	for (unsigned i = 0; i < numbers.size(); ++i) {
		for (unsigned j = 0; j < numbers.size(); ++j) {
			if (i<j && numbers[i] > numbers[j]) {
				++ret;
			}
		}
	}
	return ret;
}

// Javíott brute force
uint64_t brute2(std::vector<unsigned>& numbers)
{
	uint64_t ret{ 0 };
	for (unsigned i = 0; i < numbers.size(); ++i) {
		for (unsigned j = i+1; j < numbers.size(); ++j) {
			if (numbers[i] > numbers[j]) {
				++ret;
			}
		}
	}
	return ret;
}

// Megoldás BIT segítségével
uint64_t efficient(std::vector<unsigned>& numbers)
{
	auto tree = BITree{ *std::max_element(numbers.begin(), numbers.end()) };
	uint64_t ret{ 0 };
	for (auto num = numbers.rbegin(); num < numbers.rend(); ++num) {
		ret += tree.read(*num-1);
		tree.update(*num, 1);
	} 
	return ret;
}

int main()
{
	unsigned t, n;
	std::cin >> t;
	while (t--) {
		std::cin >> n;
		std::vector<unsigned> numbers;
		unsigned current;
		numbers.reserve(n);
		while (n--) {
			std::cin >> current;
			numbers.push_back(current);
		}
		//std::cout << brute(numbers) << "\n";
		//std::cout << brute2(numbers) << "\n";
		std::cout << efficient(numbers) << "\n";
	}
}