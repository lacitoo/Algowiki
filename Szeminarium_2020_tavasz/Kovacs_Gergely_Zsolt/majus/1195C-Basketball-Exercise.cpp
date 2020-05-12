#include <iostream>
#include <vector>
#define MAX(a, b) ((a) > (b) ? (a) : (b))

using namespace std;

int main() {
    int db;
    cin >> db;
    vector<unsigned long long> fmax(db), lmax(db);
    for (auto &&i : fmax)
        cin >> i;
    for (auto &&i : lmax)
        cin >> i;
    
    for (int i = db - 2; i >= 0; i--)
    {
        fmax[i] = MAX(fmax[i] + lmax[i+1], fmax[i+1]);
        lmax[i] = MAX(lmax[i] + fmax[i+1], lmax[i+1]);
    }
    
    cout << MAX(fmax[0], lmax[0]) << endl;

    return 0;
}