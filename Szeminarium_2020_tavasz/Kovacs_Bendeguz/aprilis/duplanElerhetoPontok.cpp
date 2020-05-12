using namespace std;
#include <iostream>
#include <vector>

int n, m, k, i;
vector<vector<int>> a;
vector<bool> visited;
vector<bool> duplanElerhetoE;

void beolvasas() {
    cin >> n >> m >> k;
    a.resize(n + 1); visited.resize(n + 1); duplanElerhetoE.resize(n + 1);

    for (i = 0; i < m; i++) {
        int seged1, seged2;
        cin >> seged1 >> seged2;
        seged1--; seged2--;

        a[seged1].push_back(seged2);
        a[seged2].push_back(seged1);
    }
    duplanElerhetoE[k - 1] = true;
}

void dfs(int p, int elozo) {
    visited[p] = true;
    for (int v : a[p]) {
        if (!visited[v]) 
        {
            dfs(v, p);
            if (duplanElerhetoE[v]) { duplanElerhetoE[p] = true; }
        }
        else 
        {
            if (duplanElerhetoE[v] && v != elozo) { duplanElerhetoE[p] = true; }
        }
    }
}

void kiiras() {
    int db = 0;
    for (i = 0; i < n; i++)
    {
        if (duplanElerhetoE[i]) { db++; }
    }
    cout << db << "\n";
    for (i = 0; i < n; i++)
    {
        if (duplanElerhetoE[i]) { cout << i + 1 << " "; }
    }
}

int main() {

    beolvasas();

    dfs(k-1, -3);

    kiiras();
    
    return 0;
}