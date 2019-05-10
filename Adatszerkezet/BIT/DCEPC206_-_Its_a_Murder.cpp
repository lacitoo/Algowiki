#include <iostream>
#include <vector>
#include <algorithm>


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

void numbersToOrders(std::vector<unsigned>& numbers)
{
	auto sorted = numbers;
	std::sort(sorted.begin(), sorted.end());
	std::transform(numbers.begin(), numbers.end(), numbers.begin(), [&](unsigned number) {
		return std::lower_bound(sorted.begin(), sorted.end(), number) - sorted.begin() + 1;
	});
}

// Naiv megoldás beágyazott ciklusokkal
uint64_t solution_naive(std::vector<unsigned>& numbers)
{
	uint64_t ret{ 0 };
	for (unsigned i = 0; i < numbers.size(); ++i) {
		for (unsigned j = 0; j < i; ++j) {
			if (numbers[j] < numbers[i]) {
				ret += numbers[j];
			}
		}
	}
	return ret;
}

// Megoldás binárisan indexelt fával (max pont)
uint64_t solution(std::vector<unsigned>& numbers)
{
	uint64_t ret{ 0 };
	auto orig = numbers;
	numbersToOrders(numbers);
	auto tree = BITree{ numbers.size() };

	for (unsigned i = 0; i < numbers.size(); ++i) {
		ret += tree.read(numbers[i] - 1);
		tree.update(numbers[i], orig[i]);
	}

	return ret;
}


int main()
{
	int t, n;
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

		std::cout << solution_naive(numbers) << "\n";
	}
}