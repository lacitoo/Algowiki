#include <iostream>
#include <algorithm>
#include <vector>
 
int n;
 
long long find_lowest(int ind, int skips, std::pair<int, int>* pairs, long long** dp)
{
	if (ind == n)
		if (skips < 0)
			return 1e15;
		else
			return 0;
	long long& ret = dp[ind][skips + n];
	if (ret != -1)
		return ret;
	return ret = std::min(find_lowest(ind + 1, std::min(skips + pairs[ind].second, n), pairs, dp) + pairs[ind].first, find_lowest(ind + 1, skips - 1, pairs, dp));
}
 
int main()
{
	std::cin >> n;
	long long** dp = new long long* [n];
	for (int i = 0; i < n; i++)
	{
		dp[i] = new long long [3 * n];
		for (int k = 0; k < 3 * n; k++)
		{
			dp[i][k] = -1;
		}
	}
	std::pair<int, int>* pairs = new std::pair<int, int> [n];
	for (int i = 0; i < n; i++)
	{
		int c, t;
		std::cin >> t >> c;
		pairs[i] = { c, t };
	}
	std::cout << find_lowest(0, 0, pairs, dp);

	for (int i = 0; i < n; i++)
	{
		delete[] dp[i];
	}
	delete[] dp;
	delete[] pairs;
}