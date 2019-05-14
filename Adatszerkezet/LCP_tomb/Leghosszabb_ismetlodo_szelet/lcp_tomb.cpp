#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct LCP {
    vector<int> value;
    vector<int> sa;
};

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

LCP buildLCPArray(const string &s) {
    int n = s.length();
    vector<int> sa = buildSuffixArray(s);
    vector<int> rank(n, 0);
    vector<int> lcp(n, 0);
    int k = 0;
    
    for (int i = 0; i < n; ++i) {
        rank[sa[i]] = i;
    }
    
    for (int i = 0; i < n; ++i) {
        if (rank[i] == n - 1) {
            k = 0;
            continue;
        }
        
        int j = sa[rank[i] + 1];
        
        while (i + k < n && j + k < n && s[i + k] == s[j + k]) {
            ++k;
        }
        
        lcp[rank[i]] = k;
        k = max(0,  k - 1);
    }
    
    return { lcp, sa };
}

int main() {
    string s;
    int k, l = 0;
    int n;
    
    getline(cin, s);
    n = s.length();
    
    LCP lcp = buildLCPArray(s);
    
    for (int i = 0; i < n - 1; ++i) {
        int p = lcp.value[i];
        int a = min(lcp.sa[i], lcp.sa[i + 1]);
        
        if (p > l || p == l && a < k) {
            k = a;
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
