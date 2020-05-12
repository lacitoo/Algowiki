#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Node
{
public:
	int fonok;
	vector<int> beosztott;
};

vector<vector<int>> edges;
vector<bool> visited;

vector<int> distances;

vector<Node> nodes;

vector<vector<int>> uj;

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
				distances[item] = distances[start] + 1;
				dfs(item);
			}
		}
	}
}

bool mindTrue()
{
	for (int i = 1; i < visited.size(); i++)
	{
		if (!visited[i])
		{
			return false;
		}
	}

	return true;
}

int tav = 0;

void method(int start, int end)
{
	uj[0].push_back(start);
	visited[start] = true;

	int current = 1;

	while (!mindTrue())
	{
		for (int item : uj[current - 1])
		{
			for (int elem : edges[item])
			{
				if (!visited[elem])
				{
					uj[current].push_back(elem);
					visited[elem] = true;
					if (elem == end)
					{
						tav = current;
					}
				}
			}
		}
		current++;
	}
}

bool XtoY(int node, int elem)
{
	for (int item : nodes[node].beosztott)
	{
		if (item == elem)
		{
			return true;
		}
		else
		{
			return XtoY(item, elem);
		}
	}

	return false;
}

int beosztottak(int elem)
{
	int sum = nodes[elem].beosztott.size();
	for (int item : nodes[elem].beosztott)
	{
		sum += beosztottak(item);
	}
	return sum;
}


int main()
{
	int N, X, Y;
	cin >> N >> X >> Y;

	edges.resize(N + 1);
	visited.resize(N + 1);

	nodes.resize(N + 1);

	int a;
	for (int i = 2; i <= N; i++)
	{
		cin >> a;
		edges[i].push_back(a);
		edges[a].push_back(i);

		nodes[i].fonok = a;
		nodes[a].beosztott.push_back(i);
	}

	//1.feladat
	bool felt1 = XtoY(X, Y);
	bool felt2 = XtoY(Y, X);

	if (felt1)
	{
		cout << "1\n";
	}
	else if (felt2)
	{
		cout << "2\n";
	}
	else
	{
		cout << "3\n";
	}

	//2.feladat
	visited.resize(N + 1);
	distances.resize(N + 1);
	distances.resize(N + 1);
	dfs(X);
	cout << distances[Y] << endl;

	//3.feladat
	cout << beosztottak(X) << " " << beosztottak(Y) << endl;


	return 0;
}
