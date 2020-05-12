#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, K;
vector<vector<int>> graf;

vector<int> points;

vector<pair<int, int>> bridges;

vector<bool> visited;
vector<int> tin, low;
int timer;

void dfs(int v, int p = -1)
{
	visited[v] = true;
	tin[v] = low[v] = timer++;
	for (int to : graf[v])
	{
		if (to != p)
		{
			if (visited[to])
			{
				low[v] = min(low[v], tin[to]);
			}
			else
			{
				dfs(to, v);
				low[v] = min(low[v], low[to]);
				if (low[to] > tin[v])
				{
					if (to == K)
					{
						bridges.push_back(pair<int, int>(to, v));
					}
					else
					{
						bridges.push_back(pair<int, int>(v, to));
					}
				}
			}
		}
	}
}

void find_bridges()
{
	timer = 0;
	visited.assign(N + 1, false);
	tin.assign(N + 1, -1);
	low.assign(N + 1, -1);
	dfs(K);
}

int allVisited = 0;
void dfs2(int v)
{
	visited[v] = true;
	allVisited++;
	for (int item : graf[v]) {
		if (!visited[item])
		{
			dfs2(item);
		}
	}
}

int main()
{
	cin >> N >> M >> K;

	graf.resize(N + 1);

	int a, b;
	for (int i = 0; i < M; i++)
	{
		cin >> a >> b;

		graf[a].push_back(b);
		graf[b].push_back(a);
	}

	find_bridges();

	points.resize(N + 1);
	points.assign(N + 1, 1);

	vector<int>::iterator it;

	for (int i = 0; i < bridges.size(); i++)
	{
		a = bridges[i].first;
		b = bridges[i].second;
		it = find(graf[a].begin(), graf[a].end(), b);
		graf[a].erase(it);
	}

	visited.assign(N + 1, false);

	dfs2(K);

	cout << allVisited << endl;
	for (int i = 1; i <= N; i++)
	{
		if (visited[i])
		{
			cout << i << " ";
		}
	}
	cout << endl;

	return 0;
}
