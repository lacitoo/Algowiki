#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
vector<vector<int>> graf;
vector<vector<int>> graf_T;
 
vector<bool> visited;
vector<int> order;
vector<int> component;
 
long long int N, M;
vector<unsigned long long int> costs;
 
 
void dfs(int start) {
	visited[start] = true;
	for (int item : graf[start])
	{
		if (!visited[item])
		{
			dfs(item);
		}
	}
	order.push_back(start);
}
 
 
void dfs2(int start)
{
	visited[start] = true;
	component.push_back(start);
	for (int item : graf_T[start])
	{
		if (!visited[item])
		{
			dfs2(item);
		}
	}
}
 
 
 
int main()
{
	cin >> N;
 
	graf.resize(N + 1);
	graf_T.resize(N + 1);
	
	visited.resize(N + 1);
 
	costs.resize(N + 1, 0);
 
	for (int i = 0; i < N; i++)
	{
		cin >> costs[i + 1];
	}
 
	cin >> M;
 
	int a, b;
	for (int i = 0; i < M; i++)
	{
		cin >> a >> b;
 
		graf[a].push_back(b);
		graf_T[b].push_back(a);
	}
 
 
	for (int i = 1; i <= N; i++)
	{
		if (!visited[i])
		{
			dfs(i);
		}
	}
 
	reverse(order.begin(), order.end());
 
	visited.assign(N + 1, false);
 
 
	long long int cost = 0, all = 1;
	for (int i = 1; i <= N; i++)
	{
		int item = order[i - 1];
		if (!visited[item])
		{
			dfs2(item);
 
			int minimum = INT_MAX;
			for (int j = 0; j < component.size(); j++)
			{
				if (costs[component[j]] < minimum)
				{
					minimum = costs[component[j]];
				}
			}
			cost += minimum;
 
			int counter = 0;
			for (int j = 0; j < component.size(); j++)
			{
				if (costs[component[j]] == minimum)
				{
					counter++;
				}
			}
			all *= counter;
 
			component.clear();
		}
	}
 
	long long int modulo = 1000000007;
 
	cout << cost << " " << (all % modulo) << endl;
 
	return 0;
}