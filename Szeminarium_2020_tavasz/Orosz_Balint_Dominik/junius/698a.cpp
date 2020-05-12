#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
int main()
{
	int N;
	cin >> N;
	vector<int> days;
	days.resize(N);
	for (int i = 0; i < N; i++)
	{
		cin >> days[i];
	}
 
	vector<vector<int>> dp(N);
	for (int i = 0; i < N; i++)
	{
		dp[i].assign(3, INT_MAX);
	}
 
	dp[0][0] = 1;
	if (days[0] == 1 || days[0] == 3)
	{
		dp[0][1] = 0;
	}
	if (days[0] == 2 || days[0] == 3)
	{
		dp[0][2] = 0;
	}
 
	for (int i = 1; i < N; i++)
	{
		dp[i][0] = 1 + min(dp[i - 1][0], min(dp[i - 1][1], dp[i - 1][2]));
		if (days[i] == 1 || days[i] == 3)
		{
			dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]);
		}
		if (days[i] == 2 || days[i] == 3)
		{
			dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]);
		}
	}
 
	int minimum = min(dp[N - 1][0], min(dp[N - 1][1], dp[N - 1][2]));
	cout << minimum << endl;
 
	return 0;
}