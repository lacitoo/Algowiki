#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    string s;
    cin >> s;
    int n = s.length();
    vector<vector<int>> DP(n + 1, vector<int>(n, 0));

    for (int i = n - 1; i >= 0; i--) {
        DP[i][i] = 1;
        for (int j = i + 1; j < n; j++) {
            DP[i][j] = max(DP[i+1][j], DP[i][j-1]);
            if (s[i] == s[j])
                DP[i][j] = max(DP[i][j], DP[i+1][j-1] + 2);
        }
    }

    cout << DP[0][n-1] << endl;
    return 0;
}