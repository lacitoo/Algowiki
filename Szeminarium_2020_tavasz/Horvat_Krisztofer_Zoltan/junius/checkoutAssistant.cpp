//https://codeforces.com/contest/19/problem/B
#include <iostream>
#include <vector>
#include <climits>

using namespace std;

//Globals
int n;
vector<int> t;
vector<unsigned long long> c;
vector<vector<unsigned long long>> dp;
const unsigned long long INF = ULLONG_MAX;


unsigned long long steal(int i, int j) {
    if (j == 2 * n) {
        return INF;
    }
    return dp[i - 1][j + 1];;
}

unsigned long long buy(int i, int j) {
    if (j - t[i - 1] < 0 || dp[i - 1][j - t[i - 1]] == INF) {
        return INF;
    }
    return dp[i - 1][j - t[i - 1]] + c[i - 1];
}

unsigned long long min(unsigned long long a, unsigned long long b) {
    return a < b ? a : b;
}

unsigned long long solution() {
    //init
    vector<unsigned long long> vec;
    vec.assign(2 * n + 1, 0);
    dp.assign(n + 1, vec);
    for (int i = n + 1; i < 2 * n + 1; ++i) {
        dp[0][i] = INF;
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 2 * n; j >= 0; --j) {
            dp[i][j] = min(steal(i, j), buy(i, j));
        }
    }

    // for (int i = 0; i < dp.size(); ++i) {
    //     for (int j = 0; j < dp[0].size(); ++j) {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    return dp[n][n];
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; ++i) {
        int ti, ci;
        cin >> ti >> ci;
        t.push_back(ti);
        c.push_back(ci);
    }

    cout << solution() << endl;

    return 0;
}