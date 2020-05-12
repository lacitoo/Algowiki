using namespace std;
#include <iostream>
#include <vector>

vector<vector <int>> graf;
vector<bool> visited;
int n, m, mennyi = -1;
vector<int> vege;

void dfs(int p) {
	visited[p] = true;
	for (int v : graf[p]) {
		if (!visited[v]) {
			dfs(v);
		}
	}
}

int main()
{
	cin >> n >> m;
	graf.resize(m + n);
	visited.resize(m + n);
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		graf[x].push_back(y);
		graf[y].push_back(x);
	}

	for (int i = 1; i <= n; i++) {
		if (!visited[i]) {
			dfs(i);
			mennyi++;
			vege.push_back(i);
		}
	}
	cout << mennyi;
	for (int i = 1; i <= mennyi; i++) {
		cout << "\n" << 1 << " " << vege[i];
	}
}

/*
9 10
1 3
2 7
6 8
8 3
1 6
4 9
4 2
4 7
7 9
2 9
*/