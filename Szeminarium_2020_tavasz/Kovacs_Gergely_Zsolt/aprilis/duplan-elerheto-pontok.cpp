#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<bool> visited;
vector<int> tin, low, res;
vector<vector<int>> G;

int timer;

void dfs_calc(int v, int parent = -1) {
    visited[v] = true;
    tin[v] = low[v] = timer++;
    for (int x : G[v]) {
        if (x == parent)
            continue;
        if (visited[x]) {
            low[v] = min(low[v], tin[x]);
        } else {
            dfs_calc(x, v);
            low[v] = min(low[v], low[x]);
        }
    }
}

void dfs_find(int v) {
    visited[v] = true;
    for (int x : G[v]) {
        if (tin[x] != low[x] && !visited[x]) {
            res.push_back(x);
            dfs_find(x);
        }
    }
}

int main() {
    int cdb, eldb, start, a, b;
    cin >> cdb >> eldb >> start;
    G.resize(cdb);
    tin.resize(cdb);
    low.resize(cdb);
    visited.resize(cdb, false);
    for (int i = 0; i < eldb; i++) {
        cin >> a >> b;
        G[a - 1].push_back(b - 1);
        G[b - 1].push_back(a - 1);
    }
    dfs_calc(start-1);
    fill(visited.begin(), visited.end(), false);
    dfs_find(start-1);
    cout << res.size()+1 << endl << start;
    for (int x : res) {
        cout << " " << x+1;
    }
    cout << endl;
    return 0;
}
