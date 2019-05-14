#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;
    int k, l = 0;
    int n;
    
    getline(cin, s);
    n = s.length();
    
    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            int p = 0;
            
            while (j < n && s[i + p] == s[j + p]) {
                ++p;
            }
            
            if (p > l) {
                k = i;
                l = p;
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
