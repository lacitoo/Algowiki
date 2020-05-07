#include <iostream>
#include <vector>
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
    int enter, low;
    vector<edge*> edges;
};


int iteration;
void discover(node* parent, node* n)
{
    n->low = n->enter = iteration++;
    for (edge* e : n->edges)
    {
        if (e->target->enter == -1)
        {
            // tree edge
            discover(n, e->target);
            if (e->target->low < n->low)
                n->low = e->target->low;
            if (e->target->low == e->target->enter)
            {
                // cut edge found between n and e->target
                e->open = e->other->open = false;
            }
        }
        else if (e->target != parent)
        {
            // back edge
            if (e->target->enter < n->low)
                n->low = e->target->enter;
        }
    }
}


vector<node*> avail;
void traverse(node* root)
{
    avail.push_back(root);
    root->enter = -1;
    for (edge* e : root->edges)
        if (e->open && e->target->enter != -1)
            traverse(e->target);
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, e, r;
    cin >> n >> e >> r;
    node* nodes = new node[n];
    for (int i = 0; i < n; ++i)
    {
        nodes[i].id = i + 1;
        nodes[i].enter = nodes[i].low = -1;
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

    node* root = &nodes[r - 1];
    iteration = 0;
    discover(nullptr, root);

    traverse(root);
    cout << avail.size() << endl;
    for (node* n : avail)
        cout << n->id << " ";
    cout << endl;
    return 0;
}
