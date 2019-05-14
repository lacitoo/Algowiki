#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> buildSuffixArray(const string &s) {
    static const int ALPHABET = 256;
    
    int n = s.length();
    vector<int> sa(n, 0);
    vector<int> tempSa(n, 0);
    vector<int> rank(2 * n, -1);
    vector<int> newRank(2 * n, -1);
    vector<int> cnt;
    int k;
    int rankCounter = ALPHABET;
    
    for (int i = 0; i < n; ++i) {
        sa[i] = i;
        rank[i] = s[i];
    }
    
    for (k = 1; k < n; k <<= 1) {
        cnt.assign(rankCounter + 1, 0);
        
        for (int i = 0; i < n; ++i) {
            ++cnt[rank[sa[i] + k] + 1];
        }
        
        for (int i = 1; i < rankCounter + 1; ++i) {
            cnt[i] += cnt[i - 1];
        }
        
        for (int i = n - 1; i >= 0; --i) {
            tempSa[--cnt[rank[sa[i] + k] + 1]] = sa[i];
        }
        
        cnt.assign(rankCounter, 0);
        
        for (int i = 0; i < n; ++i) {
            ++cnt[rank[tempSa[i]]];
        }
        
        for (int i = 1; i < rankCounter; ++i) {
            cnt[i] += cnt[i - 1];
        }
        
        for (int i = n - 1; i >= 0; --i) {
            sa[--cnt[rank[tempSa[i]]]] = tempSa[i];
        }
        
        rankCounter = 1;
        newRank[sa[0]] = 0;
        
        for (int i = 1; i < n; ++i) {
            int a = sa[i - 1], b = sa[i];
            
            if (rank[a] != rank[b] || rank[a + k] != rank[b + k]) {
                ++rankCounter;
            }
            
            newRank[sa[i]] = rankCounter - 1;
        }
        
        rank = newRank;
    }
    
    return sa;
}

int main() {
    string s;
    int k, l = 0;
    int n;
    
    getline(cin, s);
    n = s.length();
    
    vector<int> sa = buildSuffixArray(s);
    
    for (int i = 0; i < n - 1; ++i) {
        int a = sa[i], b = sa[i + 1];
        int p = 0, c = max(a, b), d = min(a, b);
        
        while (c + p < n && s[a + p] == s[b + p]) {
            ++p;
        }
        
        if (p > l || p == l && d < k) {
            k = d;
            l = p;
        }
    }
    
    if (l > 0) {
        cout << "A leghosszabb ismetlodo szelet: " << s.substr(k, l) << endl;
    } else {
        cout << "A megadott sztring nem tartalmaz ismetlodo szeletet." << endl;
    }
    
    return 0;
}
