#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<bool> melyik;
vector<vector<int>> G;
vector<bool> visited;

bool BFS(int start)
{
    queue<int> q;
    q.push(start);
    melyik[start] = true;
    visited[start] = true;
    while (!q.empty())
    {
        int current = q.front();
        q.pop();
        for (int v : G[current])
        {
            if (!visited[v])
            {
                q.push(v);
                visited[v] = true;
                melyik[v] = !melyik[current];
            }
            else
            {
                if (melyik[v] == melyik[current])
                {
                    return false;
                }
            }
        }
    }
    return true;
}

int main()
{
    ios::sync_with_stdio(0);
    int n, m, a, b;
    cin >> n >> m;
    melyik.resize(n);
    G.resize(n);
    visited.resize(n);
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        G[a - 1].push_back(b - 1);
        G[b - 1].push_back(a - 1);
    }

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            BFS(i);
        }
    }
    if (true)
    {
        for (int i = 0; i < n; i++)
        {
            if (melyik[i])
            {
                cout << i + 1 << " ";
            }
        }
        cout << "\n";
        for (int i = 0; i < n; i++)
        {
            if (!melyik[i])
            {
                cout << i + 1 << " ";
            }
        }
        cout << "\n";
    }
    else
    {
        cout << "-1\n";
    }
    return 0;
}
