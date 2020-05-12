#include <iostream>
#include <vector>
 
using namespace std;
 
vector<vector<int>> graf;
vector<bool> visited;
vector<int> distances;
 
int maximum = 0;
 
void dfs(int start)
{
	if (!visited[start])
	{
		visited[start] = true;
 
		for (int item : graf[start])
		{
			if (!visited[item])
			{
				distances[item] = distances[start] + 1;
				dfs(item);
			}
		}
	}
}
 
int main()
{
	int N;
	cin >> N;
	graf.resize(N + 1);
 
	vector<int> csucsok;
 
	int a;
	for (int i = 1; i <= N; i++)
	{
		cin >> a;
		if (a != -1)
		{
			graf[a].push_back(i);
		}
		else
		{
			csucsok.push_back(i);
		}
	}
 
	for (int i = 0; i < csucsok.size(); i++)
	{
		visited.assign(N + 1, false);
		distances.assign(N + 1, 0);
		distances[csucsok[i]] = 1;
		dfs(csucsok[i]);
 
		for (int j = 0; j < distances.size(); j++)
		{
			if (distances[j] > maximum)
			{
				maximum = distances[j];
			}
		}
	}
	
	cout << maximum << endl;
 
	return 0;
}
