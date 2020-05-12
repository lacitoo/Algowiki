#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N, M;
vector<vector<int>> graf;
vector<bool> visited;

void bfs(int start)
{
	queue<int> q;
	q.push(start);
	visited[start] = true;

	while (!q.empty())
	{
		long long int current = q.front();
		q.pop();

		for (int item : graf[current])
		{
			if (!visited[item])
			{
				q.push(item);
				visited[item] = true;
			}
		}
	}
}

int main()
{
	cin >> N >> M;
	graf.resize(N + 1);
	visited.resize(N + 1);
	int a, b;
	for (int i = 0; i < M; i++)
	{
		cin >> a >> b;
		graf[a].push_back(b);
		graf[b].push_back(a);
	}

	int c = 0;
	for (int i = 1; i <= N; i++)
	{
		if (!visited[i])
		{
			bfs(i);
			c++;
		}
	}

	long long int answer = pow(2, N - c);

	cout << answer << endl;

	return 0;
}
