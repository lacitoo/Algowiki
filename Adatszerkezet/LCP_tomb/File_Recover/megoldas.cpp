#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string data;
int cnt;

vector<int> buildSuffixArray(const string &);
vector<int> buildLCPArray(const string &);

int main() {
    ios::sync_with_stdio(false);
    
    while (getline(cin, data), data != "*") {
        int n = data.length();
        vector<int> lcp = buildLCPArray(data);
        cnt = lcp[0];
        
        for (int i = 1; i < n - 1; ++i) {
            cnt += max(0, lcp[i] - lcp[i - 1]);
        }
        
        cout << cnt << endl;
    }
    
    return 0;
}

vector<int> buildSuffixArray(const string &s) {
    static const int ALPHABET = 64;
    
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
        rank[i] = s[i] == ',' ? 0
                : s[i] == '.' ? 1
                : s[i] <= '9' ? s[i] - '0' + 2
                : s[i] <= 'Z' ? s[i] - 'A' + 12
                : s[i] - 'a' + 38;
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

vector<int> buildLCPArray(const string &s) {
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
        k = max(0, k - 1);
    }
    
    return lcp;
}
