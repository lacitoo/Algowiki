using namespace std;
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

int n, i;
vector<vector<int>> a;
vector<bool> visited;
vector<int> megoldas;

void beolvasas() {
	cin >> n;
	a.resize(n + 1);
	visited.resize(n + 1);

	for (i = 0; i < n-1; i++)
	{
		int seged1, seged2;
		cin >> seged1 >> seged2;
		a[seged1].push_back(seged2);
		a[seged2].push_back(seged1);
	}
}

bool nincseboltmellette(int x) {
	for (int i = 0; i < a[x].size(); i++)
	{
		if (find(megoldas.begin(), megoldas.end(), a[x][i]) != megoldas.end()) {
			return false;
		}
	}
	return true;
}

int main()
{
	beolvasas();

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
			if (nincseboltmellette(v)) { megoldas.push_back(v); }
		}
	}

	cout << megoldas.size() << "\n";
	for (int i : megoldas) {
		cout << i << " ";
	}

}

/*
10
1 2
3 4
4 5
4 2
2 6
6 7
6 8
8 9
10 8
*/