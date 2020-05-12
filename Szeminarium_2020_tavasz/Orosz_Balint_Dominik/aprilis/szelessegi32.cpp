#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> edges;
vector<bool> visited;
vector<int> distances;

void dfs(int start)
{
	if (!visited[start])
	{
		visited[start] = true;
		for (int i = 0; i < edges[start].size(); i++)
		{
			int item = edges[start][i];
			if (!visited[item])
			{
				dfs(item);
			}
		}
	}
}

int main()
{
	int N, M;
	cin >> N >> M;

	edges.resize(N + 1);
	visited.resize(N + 1);
	distances.resize(N + 1);

	int a, b;
	for (int i = 0; i < M; i++)
	{
		cin >> a >> b;
		edges[a].push_back(b);
		edges[b].push_back(a);
	}

	vector<int> v;
	int counter = 0;

	for (int i = 1; i < visited.size(); i++)
	{
		if (!visited[i])
		{
			v.push_back(i);
			dfs(i);
			counter++;
		}
	}

	cout << (counter - 1) << endl;

	for (int i = 0; i < v.size() - 1; i++)
	{
		cout << v[i] << " " << v[i + 1] << endl;
	}

	return 0;
}
