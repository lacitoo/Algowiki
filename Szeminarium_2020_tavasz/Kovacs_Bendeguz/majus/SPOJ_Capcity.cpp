using namespace std;
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

int n, m, i, seged = 3;
vector<vector<int>> a;
vector<bool> visited;
vector<int> megoldas;

void beolvasas() {
	cin >> n >> m;
	a.resize(n+1);
	visited.resize(n + 1);

	for (i = 0; i < m; i++)
	{
		int seged1, seged2;
		cin >> seged1 >> seged2;
		a[seged2].push_back(seged1);
	}
}

int main()
{
	beolvasas();
	
	for (int i = 1; i <= n; i++) {
		int db = 0;
		if (!visited[i]) {
			queue<int> q;
			q.push(i);
			visited[i] = true;
			while (!q.empty()) {
				int current = q.front();
				q.pop();
				for (int v : a[current]) {
					if (visited[v])
						continue;

					q.push(v);
					visited[v] = true;
					db++;
					if ((find(megoldas.begin(), megoldas.end(), v) != megoldas.end())) {
						seged = 5;
						break;
					}
				}
				if (seged == 5) {
					megoldas.push_back(i);
					seged = 3;
					break;
				}

			}
		}
		visited.clear(); visited.resize(n + 1);
		if (db == n - 1) { megoldas.push_back(i); }
	}

	cout << megoldas.size() << "\n";
	for (int i : megoldas) {
		cout << i << "\n";
	}

}