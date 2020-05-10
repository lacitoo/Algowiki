// https://codeforces.com/contest/115/submission/74641602

#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> G;

int maxkeres(int start, int melyseg) {
    int eredm = melyseg;
    for (int c : G[start]) {
        eredm = max(maxkeres(c, melyseg+1), eredm);
    }
    return eredm;
}

int main()
{
    int db, temp;
    cin >> db;
    G.resize(db+1);
    for (int i = 0; i < db; i++)
    {
        cin >> temp;
        if (temp != -1)
            G[temp].push_back(i+1);
        else
            G[0].push_back(i+1);
    }
    cout << maxkeres(0, 0);
    return 0;
}
