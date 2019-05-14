#include <iostream>
#include <string>
#include <memory>

using namespace std;

struct Trie {
    bool isLeaf = false;
    unique_ptr<Trie> children[10]; // a - j
    
    bool insert(const string &s) {
        int n = s.length();
        int i = 0;
        Trie *t = this;
        
        while (i < n && t->children[s[i] - 'a']) {
            t = t->children[s[i++] - 'a'].get();
        }
        
        if (i == n || t->isLeaf) {
            return true;
        }
        
        while (i < n) {
            t->children[s[i] - 'a'] = make_unique<Trie>();
            t = t->children[s[i++] - 'a'].get();
        }
        
        t->isLeaf = true;
        return false;
    }
};

int main() {
    ios::sync_with_stdio(false);
    
    int N;
    string S;
    Trie trie;
    bool bad = false;
    
    cin >> N;
    
    for (int i = 0; !bad && i < N; ++i) {
        cin >> S;
        bad = trie.insert(S);
    }
    
    if (bad) {
        cout << "BAD SET" << endl << S << endl;
    } else {
        cout << "GOOD SET" << endl;
    }
    
    return 0;
}
