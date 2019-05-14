#include <iostream>
#include <string>
#include <algorithm>
#include <memory>

using namespace std;

const int maxq = 100000;

struct TrieNode {
    int leafCount = 0;
    unique_ptr<TrieNode> children[26];
};

struct Trie {
    string contents[maxq];
    TrieNode root;
    
    void insert(int x, const string &s) {
        contents[x] = s;
        int n = s.length();
        int i = 0;
        TrieNode *t = &root;
        
        while (i < n && t->children[s[i] - 'a']) {
            ++t->leafCount;
            t = t->children[s[i++] - 'a'].get();
        }
        
        while (i < n) {
            ++t->leafCount;
            t->children[s[i] - 'a'] = make_unique<TrieNode>();
            t = t->children[s[i++] - 'a'].get();
        }
    }
    
    bool query(int k, int l) {
        return queryRec(k, l, &root);
    }
    
    bool queryRec(int k, int l, TrieNode *t) {
        if (l == 0 || t->leafCount == 0) {
            return t->leafCount >= k;
        }
        
        for (int i = 0; i < 26; ++i) {
            if (t->children[i] && queryRec(k, l - 1, t->children[i].get())) {
                return true;
            }
        }
        
        return false;
    }
    
    void remove(int x) {
        if (contents[x].length() > 0) {
            string s = contents[x];
            contents[x] = "";
            int n = s.length();
            int i = 0;
            TrieNode *t = &root;
            TrieNode *p = nullptr;
            
            while (i < n && t->leafCount > 1) {
                --t->leafCount;
                p = t;
                t = t->children[s[i++] - 'a'].get();
            }
            
            if (i < n) {
                if (p == nullptr) {
                    root.leafCount = 0;
                    root.children[s[0] - 'a'].reset();
                } else {
                    p->children[s[i - 1] - 'a'].reset();
                }
            }
        }
    }
};
    
int q;
Trie t;

int main() {
    ios::sync_with_stdio(false);
    cin >> q;
    
    int op, k, l, x;
    string s;
    
    for (int i = 0; i < q; ++i) {
        cin >> op;
        
        switch (op) {
        case 1:
            cin >> s;
            reverse(s.begin(), s.end());
            t.insert(i, s);
            break;
        case 2:
            cin >> k >> l;
            cout << (t.query(k, l) ? "YES" : "NO") << endl;
            break;
        case 3:
            cin >> x;
            t.remove(x - 1);
        }
    }
    
    return 0;
}
