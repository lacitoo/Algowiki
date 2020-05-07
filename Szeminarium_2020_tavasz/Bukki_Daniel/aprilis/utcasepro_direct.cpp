#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <string>
using namespace std;


struct edge
{
	int target;
	edge* other;
	bool open;
};


vector<edge*>* nodes;
void traverse(int root)
{
	cout << root << " ";
	for (edge* e : nodes[root])
	{
		if (e->open)
		{
			e->open = false;
			e->other->open = false;
			traverse(e->target);
			cout << root << " ";
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, e;
	cin >> n >> e;
	nodes = new vector<edge*>[n + 1];
	for (int i = 0; i < e; ++i)
	{
		int n1, n2;
		cin >> n1 >> n2;
		edge* e1 = new edge({ n2, nullptr, true });
		edge* e2 = new edge({ n1, nullptr, true });
		e1->other = e2;
		e2->other = e1;
		nodes[n1].push_back(e1);
		nodes[n2].push_back(e2);
	}
	traverse(1);
	return 0;
}
