#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> G, Gr;
vector<bool> visited;
vector<int> costs, order;
int first;

void DFS(int x) {
    visited[x] = true;
    for (int &v : G[x])
        if (!visited[v])
            DFS(v);
    order[--first] = x;
}

pair<int, int> components(int x) {
    pair<int, int> mn(costs[x], 1);
    visited[x] = true;
    for (int v : Gr[x]) {
        if (!visited[v]) {
            pair<int, int> next(components(v));
            if (mn.first > next.first)
                mn = next;
            else if (mn.first == next.first)
                mn.second += next.second;
        }
    }
    return mn;
}

int main() {
    int n, m, a, b;
    vector<pair<int, int>> sectors;

    cin >> n;
    visited.resize(n, false);
    order.resize(n);
    costs.resize(n);
    first = n;

    for (int &e : costs)
        cin >> e;

    cin >> m;
    G.resize(n);
    Gr.resize(n);

    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        G[a - 1].push_back(b - 1);
        Gr[b - 1].push_back(a - 1);
    }

    for (int i = 0; i < n; i++)
        if (!visited[i])
            DFS(i);

    fill(visited.begin(), visited.end(), false);

    for (int v : order)
        if (!visited[v])
            sectors.push_back(components(v));

    unsigned long long sum = 0, mul = 1;
    for (pair<int, int> p : sectors) {
        sum += p.first;
        mul *= p.second;
        mul %= 1000000007;
    }

    cout << sum << " " << mul << endl;
    return 0;
}