#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> computeZArray(const string &s) {
    int n = s.length();
    vector<int> z(n);
    int l = 0, r = 0;
    
    for (int i = 1; i < n; ++i) {
        if (i <= r) {
            z[i] = min(z[i - l], r - i + 1);
        }
        
        while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
            ++z[i];
        }
        
        if (i + z[i] - 1 > r) {
            l = i;
            r = i + z[i] - 1;
        }
    }
    
    return z;
}

int N;
string s;
int k;

int main() {
    ios::sync_with_stdio(false);
    
    cin >> N;
    
    for (int t = 1; t <= N; ++t) {
        cin >> s;
        int n = s.length();
        vector<int> z = computeZArray(s);
        bool found = false;
        
        for (int i = 1; !found && i <= n / 2; ++i) {
            if (n % i == 0 && i + z[i] == n) {
                found = true;
                k = i;
            }
        }
        
        if (!found) {
            k = n;
        }
        
        cout << k << endl;
        
        if (t < N) {
            cout << endl;
        }
    }
    
    return 0;
}
