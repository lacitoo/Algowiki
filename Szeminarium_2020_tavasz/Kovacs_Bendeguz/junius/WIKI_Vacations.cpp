using namespace std;
#include <iostream>
#include <algorithm>
#include <vector>

int main()
{
	vector<int> napok;
	vector<vector<int>> dp;

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		napok.push_back(a);
	}

	dp.resize(n, vector<int>(3, 200));

	dp[0][0] = 1;
	if (napok[0] == 1 || napok[0] == 3) { dp[0][1] = 0; }
	if (napok[0] == 2 || napok[0] == 3) { dp[0][2] = 0; }

	for (int i = 1; i < n; i++) {
		dp[i][0] = 1 + min(dp[i - 1][0], min(dp[i - 1][1], dp[i - 1][2]));

		if (napok[i] == 1 || napok[i] == 3) {
			dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]);
		}
		if (napok[i] == 2 || napok[i] == 3) {
			dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]);
		}
	}

	cout << min(dp[n - 1][0], min(dp[n - 1][1], dp[n - 1][2])) << endl;
}