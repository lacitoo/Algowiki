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

string s;
bool found;
int index;

int main() {
    cin >> s;
    
    int n = s.length();
    vector<int> z = computeZArray(s);
    found = false;
    int maxZ = z[0];
    
    for (int i = 1; !found && i < n; ++i) {
        if (z[i] == n - i && maxZ >= n - i) {
            found = true;
            index = i;
        }
        
        maxZ = max(maxZ, z[i]);
    }
    
    cout << (found ? s.substr(index) : "Just a legend") << endl;
    return 0;
}
