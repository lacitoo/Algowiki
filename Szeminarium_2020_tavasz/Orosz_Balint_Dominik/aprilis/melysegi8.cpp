#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> graf, gT;
vector<bool> visited;
vector<int> order, component;

vector<vector<int>> components;

void dfs1(int v)
{
    visited[v] = true;
    for(int item : graf[v])
    {
        if (!visited[item])
        {
            dfs1(item);
        }
    }
    order.push_back(v);
}

void dfs2(int v)
{
    visited[v] = true;
    component.push_back(v);
    for(int item : gT[v])
    {
        if (!visited[item])
        {
            dfs2(item);
        }
    }
}

int main() {
    int N, M;
    cin >> N >> M;
    graf.resize(N + 1); gT.resize(M + 1);

    int a, b;
    for (int i = 0; i < M; i++)
    {
        cin >> a >> b;
        graf[a].push_back(b);
        gT[b].push_back(a);
    }

    visited.assign(N + 1, false);
    for (int i = 1; i <= N; i++)
    {
        if (!visited[i])
        {
            dfs1(i);
        }
    }
    visited.assign(N + 1, false);
    for (int i = 1; i <= N; i++)
    {
        int v = order[N - i];
        if (!visited[v])
        {
            dfs2(v);
            components.push_back(component);
            component.clear();
        }
    }

    if (components.size() == 1)
    {
        cout << "0 0" << endl;
    }
    else
    {
        a = components[components.size() - 1][0];
        b = components[0][0];
        cout << a << " " << b << endl;
    }
    return 0;
}