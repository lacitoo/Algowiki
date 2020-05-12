#include <iostream>
#include <vector>
using namespace std;
 
int main()
{
    vector<int> adatok;
    int n, db = 0, mennyi = 0;
    cin >> n;
    adatok.resize(n + 10);
    for (int i = 1; i <= n;i++) {
        cin >> adatok[i];
    }
    for (int i = 1; i <= n;i++){
        mennyi = 0;
        int x = adatok[i];
        while (x != -1){
            x = adatok[x];
            mennyi++;
        }
        if (db < mennyi) {
            db = mennyi;
        }
    }
    cout << db + 1;
    return 0;
}