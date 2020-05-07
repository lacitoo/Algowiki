#include <iostream>
#include <vector>
using namespace std;


struct node
{
	vector<node*> children;
};


int maxlevel;
void traverse(node* n, int level)
{
	++level;
	if (level > maxlevel)
		maxlevel = level;
	for (node* c : n->children)
		traverse(c, level);
}

int main()
{
	int n;
	cin >> n;
	node* nodes = new node[n];
	vector<node*> roots;
	for (int i = 0; i < n; ++i)
	{
		int p;
		cin >> p;
		if (p == -1)
			roots.push_back(&nodes[i]);
		else nodes[--p].children.push_back(&nodes[i]);
	}

	maxlevel = 0;
	for (node* r : roots)
		traverse(r, 0);
	cout << maxlevel << endl;
	return 0;
}
