#include <iostream>
#include <vector>
using namespace std;


struct node
{
    int id;
    int enter, low;
    bool safe;
    vector<node*> nodes;
};


int cvcount;
int iteration;
void discover(node* parent, node* root)
{
    root->low = root->enter = iteration++;
    int te_children = 0;
    for (node* n : root->nodes)
    {
        if (n->enter == -1)
        {
            // tree edge
            discover(root, n);
            if (n->low < root->low)
                root->low = n->low;
            if (n->low >= root->enter && parent != nullptr)
            {
                // cut point root found
                if (root->safe)
                {
                    root->safe = false;
                    ++cvcount;
                }
            }
            ++te_children;
        }
        else if (n != parent)
        {
            // back edge
            if (n->enter < root->low)
                root->low = n->enter;
        }
    }
    // check root
    if (parent == nullptr && te_children > 1 && root->safe)
    {
        root->safe = false;
        ++cvcount;
    }
}


int main()
{
    int n, e;
    cin >> n >> e;
    while (n != 0 || e != 0)
    {
        node* nodes = new node[n];
        for (int i = 0; i < n; ++i)
        {
            nodes[i].id = i + 1;
            nodes[i].enter = nodes[i].low = -1;
            nodes[i].safe = true;
        }
        for (int i = 0; i < e; ++i)
        {
            int n1, n2;
            cin >> n1 >> n2;
            --n1; --n2;
            nodes[n1].nodes.push_back(&nodes[n2]);
            nodes[n2].nodes.push_back(&nodes[n1]);
        }

        node* root = &nodes[0];
        iteration = 0;
        cvcount = 0;
        discover(nullptr, root);
        cout << cvcount << endl;

        delete[] nodes;
        cin >> n >> e;
    }
    return 0;
}
