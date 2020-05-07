#include <iostream>
#include <vector>
#include <queue>
using namespace std;


vector<int>* nodes;
bool* unvis;
void traverse(int node)
{
	unvis[node] = false;
	for (int other : nodes[node])
		if (unvis[other])
			traverse(other);
}

int main()
{
	int n, m;
	cin >> n >> m;
	nodes = new vector<int>[n];
	unvis = new bool[n];
	for (int i = 0; i < n; ++i)
		unvis[i] = true;
	for (int i = 0; i < m; ++i)
	{
		int l, r;
		cin >> l >> r;
		--l; --r;
		nodes[l].push_back(r);
		nodes[r].push_back(l);
	}

	vector<int> roots;
	for (int i = 0; i < n; ++i)
	{
		if (unvis[i])
		{
			roots.push_back(i);
			traverse(i);
		}
	}

	cout << roots.size() - 1 << endl;
	if (roots.size() > 1)
	{
		int pivot = roots[0] + 1;
		for (int i = 1; i < roots.size(); ++i)
			cout << pivot << ' ' << roots[i] + 1 << endl;
	}
}