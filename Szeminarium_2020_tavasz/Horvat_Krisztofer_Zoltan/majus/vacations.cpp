//https://codeforces.com/problemset/problem/698/A
#include <iostream>
#include <vector>

using namespace std;


// Globals
int n;
vector<int> conf;


// Help functions
bool canGym(int a) {
    return a > 1;
}

bool canCode(int a) {
    return a % 2 == 1;
}

int min(int a, int b) {
    if (a == -1) {
        return b;
    }
    if (b == -1) {
        return a;
    }
    return (a < b) ? a : b;
}

int min(int a, int b, int c) {
    if (a == -1) {
        return min(b ,c);
    }
    if (b == -1) {
        return min(a, c);
    }
    if (c == -1) {
        return min(a, b);
    }
    return (a < b) ? ((a < c) ? a : c) : ((b < c) ? b : c);
}


// Solution
int solution() {
    vector<vector<int>> dp; // 0 - rest, 1 - gym, 2 - contest
    {
        vector<int> vec;
        vec.assign(3, 0);
        dp.assign(n, vec);
    }

    dp[0][0] = 1;
    dp[0][1] = canGym(conf[0]) ? 0 : -1;
    dp[0][2] = canCode(conf[0]) ? 0 : -1;

    for (int i = 1; i < n; ++i) {
        dp[i][0] = min(dp[i - 1][0], dp[i - 1][1], dp[i - 1][2]) + 1;
        dp[i][1] = canGym(conf[i]) ? min(dp[i - 1][0], dp[i - 1][2]) : -1;
        dp[i][2] = canCode(conf[i]) ? min(dp[i - 1][0], dp[i - 1][1]) : -1;
    }

    return min(dp[n - 1][0], dp[n - 1][1], dp[n - 1][2]);
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        conf.push_back(a);
    }

    cout << solution() << endl;

    return 0;
}