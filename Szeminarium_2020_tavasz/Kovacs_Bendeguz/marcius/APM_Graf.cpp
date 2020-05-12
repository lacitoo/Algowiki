using namespace std;
#include <vector>
#include <iostream>
#include <queue>


int main()
{
	int n, m;
	cin >> n >> m;
	vector<vector<int>> g(n + 1);
	vector<bool> visited(n + 1);
	vector<int> first(n + 1);
	
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}

	for (int i = 1; i <= n; i++) {
		if (!visited[i]) {
			queue<int> q;
			q.push(i);
			visited[i] = true;
			while (!q.empty()) {
				int current = q.front();
				//cout << q.front() << " ";
				q.pop();
				for (int v : g[current]) {
					if (visited[v]) 
						continue;
					
					q.push(v);
					visited[v] = true;
					first[v] = 1 - first[current];
					
				}

			}
		}
	}

	for (int i = 1; i <= n; i++) {
		if (first[i] == 0) { cout << i << " "; }
	}
	cout << "\n";
	for (int i = 1; i <= n; i++) {
		if (first[i] == 1) { cout << i << " "; }
	}
}
/*
9 8
1 3
3 9
9 4
5 4
2 6
7 8
3 5
9 6
*/
