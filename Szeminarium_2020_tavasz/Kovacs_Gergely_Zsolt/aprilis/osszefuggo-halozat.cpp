#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> G; // gráf éllistás ábrázolással
vector<bool> visited; // már bejárt csúcsok tárolása

// Mélységi bejárás
void DFS(int p) {
    visited[p] = true;
    for (int v : G[p])
        if (!visited[v])
            DFS(v);
}

int main() {
    int n, m, a, b;
    
    // n - csúcsok száma, m - élek száma
    cin >> n >> m;

    G.resize(n);
    visited.resize(n, false);

    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        G[a - 1].push_back(b - 1);
        G[b - 1].push_back(a - 1);
    }

    // komponensek egy-egy csúcsának tárolása
    vector<int> komp;
    for (int j = 0; j < n; j++) {
        if (!visited[j]) {
            komp.push_back(j);
            DFS(j);
        }
    }

    cout << komp.size() - 1 << endl;
    for (int i = 1; i < komp.size(); i++)
        cout << komp[0] + 1 << " " << komp[i] + 1 << endl;

    return 0;
}