#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> computeLPS(const string &pat) {
    int m = pat.length();
    vector<int> lps(m, 0);
    
    int len = 0;
    int i = 1;
    
    while (i < m) {
        if (pat[i] == pat[len]) {
            lps[i++] = ++len;
        } else {
            if (len > 0) {
                len = lps[len - 1];
            } else {
                lps[i++] = 0;
            }
        }
    }
    
    return lps;
}

bool isSubstring(const string &s, const string &pat, int start) {
    int n = s.length();
    int m = pat.length();
    vector<int> lps = computeLPS(pat);
    
    int i = start;
    int j = 0;
    
    while (i < n) {
        if (s[i] == pat[j]) {
            ++i, ++j;
            
            if (j == m) {
                return true;
            }
        } else {
            if (j > 0) {
                j = lps[j - 1];
            } else {
                ++i;
            }
        }
    }
    
    return false;
}

int main() {
    string s;
    int k, l = 0;
    int n;
    
    getline(cin, s);
    n = s.length();
    
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j <= n; ++j) {
            if (isSubstring(s, s.substr(i, j - i), i + 1) && j - i > l) {
                k = i;
                l = j - i;
            }
        }
    }
    
    if (l > 0) {
        cout << "A leghosszabb ismetlodo szelet: " << s.substr(k, l) << endl;
    } else {
        cout << "A megadott sztring nem tartalmaz ismetlodo szeletet." << endl;
    }
    
    return 0;
}
