#include <iostream>
#include <vector>
#include <sstream>
#include <queue>

using namespace std;

int N, M;
vector<vector<int>> graf;
vector<bool> visited;
vector<int> distances;

void bfs(int start)
{
	queue<int> q;
	q.push(start);
	visited[start] = true;
	distances[start] = 0;

	while (!q.empty())
	{
		int current = q.front();
		q.pop();
		for (int item : graf[current])
		{
			if (!visited[item])
			{
				q.push(item);
				visited[item] = true;
				distances[item] = distances[current] + 1;
			}
		}
	}
}

int main()
{
	cin >> N >> M;

	graf.resize(N + 1);
	visited.resize(N + 1);
	distances.resize(N + 1);

	int a, b;
	for (int i = 0; i < M; i++)
	{
		cin >> a >> b;
		graf[a].push_back(b);
		graf[b].push_back(a);
	}

	for (int i = 1; i <= N; i++)
	{
		if (!visited[i])
		{
			bfs(i);
		}
	}



	ostringstream g1, g2;

	for (int i = 1; i <= N; i++)
	{
		if (distances[i] % 2 == 0)
		{
			g1 << i << " ";
		}
		else
		{
			g2 << i << " ";
		}
	}

	cout << g1.str() << endl << g2.str() << endl;

	return 0;
}
