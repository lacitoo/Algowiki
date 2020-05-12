#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

vector<vector<int>> graf;

int minimum = INT_MAX;
int last = 0;

vector<int> vertices;

int N, M, P;

void shortest(int p)
{
	vector<int> vertices;

	vector<int> distances(N + 1, INT_MAX);

	vector<int> parent(N + 1);

	distances[p] = 0;

	queue<int> q;
	q.push(p);

	while (!q.empty())
	{
		int current = q.front();
		q.pop();

		for (int child : graf[current])
		{
			if (distances[child] == INT_MAX)
			{
				distances[child] = distances[current] + 1;
				parent[child] = current;
				q.push(child);
			}
			else if (parent[current] != child && parent[child] != current)
			{
				minimum = min(minimum, distances[current] + distances[child] + 1);
				vertices.push_back(current);
			}
		}
	}

	if (minimum == INT_MAX)
	{
		cout << -1 << endl;
	}
	else
	{
		cout << minimum << endl;
	}
}

int start = 0;
int all_length = 0;

void abc(vector<int> v, int a)
{
	vector<int> vektor;
	for (int x : v)
	{
		vektor.push_back(x);
	}
	vektor.push_back(a);
	if (vektor.size() == all_length && vektor[vektor.size() - 1] == start)
	{
		vertices = vektor;
		return;
	}
	if (vektor.size() == all_length && vektor[vektor.size() - 1] != start)
	{
		return;
	}
	else
	{
		for (int item : graf[a])
		{
			abc(vektor, item);
		}
	}
}

int main()
{
	cin >> N >> M >> P;

	graf.resize(N + 1);

	int a, b;
	for (int i = 0; i < M; i++)
	{
		cin >> a >> b;

		graf[a].push_back(b);
		graf[b].push_back(a);
	}

	shortest(P);


	start = P;
	all_length = minimum + 1;

	vector<int> vek;
	vek.push_back(P);
	for (int v : graf[P])
	{
		abc(vek, v);
	}

	for (int i = 0; i < vertices.size()-1; i++)
	{
		cout << vertices[i] << " ";
	}
	cout << endl;

	return 0;
}
