#include <iostream>
#include <vector>
 
int max(const int a, const int b, const int c)
{
	int max = a;
	if (max < b)
	{
		max = b;
	}
	if (max < c)
	{
		max = c;
	}
	return max;
}
 
int main()
{
	int n;
	std::cin >> n;
	std::vector<int> data;
	for (int i = 0; i < n; i++)
	{
		int element;
		std::cin >> element;
		data.push_back(element);
	}
 
	int max_contest = 0;
	int max_sport = 0;
	int max_nothing = 0;
 
	for (int i = 0; i < n; i++)
	{
		int max_nothing_temporary = max_nothing;
		max_nothing_temporary = max(max_contest, max_sport, max_nothing_temporary);
 
		int max_contest_temporary = 0;
		if (data[i] == 1 || data[i] == 3)
		{
			max_contest_temporary = max(max_contest_temporary, max_nothing, max_sport) + 1;
		}
 
		int max_sport_temporary = 0;
		if (data[i] == 2 || data[i] == 3)
		{
			max_sport_temporary = max(max_contest, max_nothing, max_sport_temporary) + 1;
		}
 
		max_contest = max_contest_temporary;
		max_nothing = max_nothing_temporary;
		max_sport = max_sport_temporary;
 
	}
 
	std::cout << n - max(max_contest, max_nothing, max_sport) << std::endl;
}