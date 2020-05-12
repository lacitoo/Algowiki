#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int minimum, N, M, P;

int main()
{
  cin >> N >> M >> P;
  minimum = N + 1;
  vector<vector<int>> G(N + 1);
  vector<bool> visited(N + 1, false);
  vector<int> parent(N + 1);
  vector<int> start(N + 1);       //starting point of the subtree
  vector<int> dist(N + 1, N + 1); //distance from P
  int x, y;
  for (int i = 0; i < M; i++)
  {
    cin >> x >> y;
    G[x].push_back(y);
    G[y].push_back(x);
  }
  int a = -1;
  int b = -1;
  queue<int> q;
  visited[P] = true;
  dist[P] = 0;
  for (int v : G[P]) //starting point of the subtrees
  {
    q.push(v);
    visited[v] = true;
    dist[v] = 1;
    start[v] = v;
    parent[v] = P;
  }
  //dfs
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
        parent[v] = current;
        dist[v] = dist[current] + 1;
        start[v] = start[current];
      }
      else if (start[v] != start[current] && v != P) //found a circle
      {
        if (dist[v] + dist[current] + 1 < minimum) //found a smaller circle
        {
          a = v;
          b = current;
          minimum = dist[a] + dist[b] + 1;
        }
      }
    }
  }

  if (a != -1) //found circle
  {
    cout << minimum << endl;

    cout << P << ' ';
    vector<int> from_b;
    while (b != P)
    {
      from_b.push_back(b);
      b = parent[b];
    }
    for (int i = from_b.size(); i > 0; i--)
    {
      cout << from_b[i - 1] << ' ';
    }
    while (a != P)
    {
      cout << a << ' ';
      a = parent[a];
    }
    cout << endl;
  }

  else
  {
    cout << -1 << endl;
  }
  return 0;
}
