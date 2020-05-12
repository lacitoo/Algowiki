using namespace std;
#include <iostream>
#include <vector>

vector<vector<int>> adatok;
int leghosszabb = -1;

void dfs(int x, int szint) {
    if (szint > leghosszabb) { leghosszabb = szint; }
    for (int i = 0; i < adatok[x].size(); i++) {
        dfs(adatok[x][i], szint + 1);
    }
}

int main() {
    int n, x;
    cin >> n;

    adatok.resize(n + 1);

    for (int i = 1; i <= n; i++) {
        cin >> x;

        if (x != -1)adatok[x].push_back(i);
        else adatok[0].push_back(i);
    }

    for (int i = 0; i < adatok[0].size(); i++) {
        dfs(adatok[0][i], 1);
    }

    cout << leghosszabb << endl;
    return 0;
}