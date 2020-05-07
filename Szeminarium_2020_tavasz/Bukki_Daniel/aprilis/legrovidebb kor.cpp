#include <iostream>
#include <vector>
#include <queue>
using namespace std;


struct node
{
	int id = 0;
	int distance = -1;
	node* target = nullptr;
	node* branch = nullptr;
	vector<node*> nodes;
};

struct nodepair
{
	node* first;
	node* last;
	int length;
};


nodepair getCycleEnds(node* root)
{
	root->distance = 0;
	queue<node*> q;
	for (node* b : root->nodes)
	{
		b->branch = b;
		b->distance = 1;
		b->target = root;
		q.push(b);
	}
	nodepair pair = { nullptr, nullptr, 0 };
	int level = 2;
	while (!q.empty())
	{
		node* n = q.front();
		q.pop();
		int d = n->distance + 1;
		if (level != d)
		{
			if (pair.first != nullptr)
				return pair;
			else level = d;
		}
		for (node* c : n->nodes)
		{
			if (c != n->target)
			{
				if (c->distance == -1)
				{
					c->target = n;
					c->branch = n->branch;
					c->distance = d;
					q.push(c);
				}
				else if (c->branch != n->branch)
				{
					int l = c->distance + n->distance;
					if (pair.first == nullptr || l < pair.length)
						pair = { n, c, l };
				}
			}
		}
	}
	return pair;
}

int main()
{
	int n, e, p;
	cin >> n >> e >> p;
	node* nodes = new node[n];
	for (int i = 0; i < n; ++i)
		nodes[i].id = i;
	for (int i = 0; i < e; ++i)
	{
		int vs, ve;
		cin >> vs >> ve;
		--vs; --ve;
		nodes[vs].nodes.push_back(&nodes[ve]);
		nodes[ve].nodes.push_back(&nodes[vs]);
	}

	// find cycle
	node* root = &nodes[p - 1];
	nodepair ends = getCycleEnds(root);
	if (ends.first == nullptr)
		cout << -1 << endl;
	else
	{
		// print length
		cout << ends.length + 1 << endl;

		// reverse last part
		node* next = ends.first;
		node* nd = ends.last;
		while (nd != nullptr)
		{
			node* t = nd->target;
			nd->target = next;
			next = nd;
			nd = t;
		}

		// print cycle
		nd = root;
		do
		{
			cout << nd->id + 1 << " ";
			nd = nd->target;
		}
		while (nd != root);
		cout << endl;
	}
	return 0;
}
