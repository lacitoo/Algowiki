#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    string s;
    cin >> s;
    int n = s.length();
    vector<vector<int>> dp(n, vector<int>(n));

    for (int i = n-1; i >= 0; i--) {
        for (int j = i+1; j < n; j++) {
            if (s[i] == s[j]) // Az első és utoldó egyformák, elhagyásuk ugyanahhoz az eredményhez vezet.
                dp[i][j] = dp[i+1][j-1];
            else // Az eredmény az első vagy az utolsó elhagyásával kapott szóénál eggyel több, hiszen az elhagyott a túloldalra beszúrandó.
                dp[i][j] = min(dp[i+1][j], dp[i][j-1]) + 1;
        }
    }

    int i = 0, j = n-1;
    int pluslen = 0; // a már beszúrt karakterek miatti eltolódást számolja

    cout << dp[i][j] << "\n"; // A teljes szóra kaptt eredmény

    while (i != j) {
        if (s[i] == s[j]) // első, utolsó egyformák, nincs szükség beszúrásra
            i++, j--;
        else if (dp[i][j-1] == dp[i][j] - 1) // beszúrás a részsztring elejére
            cout << i + pluslen++ << " " << s[j--] << "\n";
        else // if (dp[i+1][j] == dp[i][j] - 1) // beszúrás a részsztring végére
            cout << j + pluslen+1 << " " << s[i++] << "\n";
    }

    return 0;
}