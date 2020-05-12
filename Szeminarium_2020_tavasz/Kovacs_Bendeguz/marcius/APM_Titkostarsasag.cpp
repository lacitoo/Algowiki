using namespace std;
#include <iostream>
#include <vector>
#include <queue>

int main()
{
	int n, x, y;
	cin >> n >> x >> y;
	for (int i = 0; i < n - 1; i++) {

	}
	vector<vector<int>> g(n + 1);
	vector<bool> visited(n + 1);
	vector<int> first(n + 1);

	for (int i = 0; i < n-1; i++) {
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
					if (visited[v]) {
						continue;
					}
					else {
						q.push(v);
						visited[v] = true;
					}
				}

			}
		}
	}
}
