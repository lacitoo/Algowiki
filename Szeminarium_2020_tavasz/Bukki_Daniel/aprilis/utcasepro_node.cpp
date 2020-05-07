#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

struct node;

struct edge
{
	node* target;
	edge* other;
	bool open;
};

struct node
{
	int id;
	vector<edge*> edges;
};


void traverse(node* root)
{
	cout << root->id << " ";
	for (edge* e : root->edges)
	{
		if (e->open)
		{
			e->open = false;
			e->other->open = false;
			traverse(e->target);
			cout << root->id << " ";
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, e;
	cin >> n >> e;
	node* nodes = new node[n];
	for (int i = 0; i < n; ++i)
	{
		nodes[i].id = i + 1;
	}
	for (int i = 0; i < e; ++i)
	{
		int n1, n2;
		cin >> n1 >> n2;
		--n1; --n2;
		edge* e1 = new edge({ &nodes[n2], nullptr, true });
		edge* e2 = new edge({ &nodes[n1], nullptr, true });
		e1->other = e2;
		e2->other = e1;
		nodes[n1].edges.push_back(e1);
		nodes[n2].edges.push_back(e2);
	}
	traverse(&nodes[0]);
	return 0;
}
