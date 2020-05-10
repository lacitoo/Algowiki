//Mester -> Haladó -> Dinamikus programozás -> 55. Leghosszabb tükörszó hossza
#include <iostream>
#include <vector>

using namespace std;

//Globals
int n;
string str;
vector<vector<int>> dp;


int max(int a, int b, int c) {
    return (a > b) ? (a > c ? a : c) : (b > c ? b : c);
}

int solution() {
    n = str.length();
    vector<int> vec;
    vec.assign(n, 0);
    dp.assign(n, vec);

    for (int i = 0; i < n; ++i) {
        dp[i][i] = 1;
    }

    for (int i = n - 2; i >= 0; --i) {
        for (int j = i + 1; j < n; ++j) {
            dp[i][j] = max(dp[i + 1][j], dp[i][j - 1], dp[i + 1][j - 1] + (str[i] == str[j] ? 2 : 0));
        }
    }
    return dp[0][n - 1];
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> str;

    cout << solution() << endl;

    return 0;
}