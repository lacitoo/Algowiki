using namespace std;
#include <vector>
#include <iostream>
#include <algorithm>

vector<int> voltak;

bool voltmar(int a)
{
    for (int i = 0; i < voltak.size(); i++) { if (voltak[i] == a) { return 1; } }
    return 0;
}

int main()
{
    int n, m;
    vector<int> szamok;
    cin >> n >> m;
    for (int i = 0; i < n; i++) { int a; cin >> a; szamok.push_back(a); }
    int db;
    vector<pair<int, int>> mik;
    cin >> db;
    for (int i = 0; i < db; i++) { int a, b; cin >> a >> b; mik.push_back(make_pair(a-1, b-1)); }

    
    for (int i = 0; i < db; i++)
    {
        int mennyi = 1;
        voltak.push_back(szamok[mik[i].first]);
        for (int j = mik[i].first; j <= mik[i].second; j++)
        {
            if (voltmar(szamok[j]) == 0) { mennyi++; voltak.push_back(szamok[j]); }
        }
        cout << mennyi << "\n";
        voltak.clear();
    }
}
