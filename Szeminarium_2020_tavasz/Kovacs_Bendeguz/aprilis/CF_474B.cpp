#include <iostream>
#include <vector>
using namespace std;
 
int main() {
    vector<int> piles;
    int n, i, j, m;
    cin >> n;
    
    piles.resize(1);
    for (i = 0; i < n; i++)
    {
        int seged;
        cin >> seged;
        for (j = 0; j < seged; j++)
        {
            piles.push_back(i + 1);
        }
    }
    cin >> m;
    for (i = 0; i < m; i++)
    {
        int seged;
        cin >> seged;
        cout << piles[seged] << "\n";
    }
}