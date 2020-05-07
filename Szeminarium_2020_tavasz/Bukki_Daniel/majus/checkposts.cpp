#include <iostream>
#include <vector>
using namespace std;


typedef unsigned long long ulong;

enum state
{
    initial,
    top_ordered,
    traversed,
};

struct node
{
    int cost;
    state state;
    vector<node*> nodes_fw, nodes_bw;
};


// traverse to create topological order
node** nodes_to;
int nodes_to_pos;
void top_order(node* root)
{
    // traverse edges forward
    root->state = state::top_ordered;
    for (node* n : root->nodes_fw)
        if (n->state == state::initial)
            top_order(n);

    // record in topological order
    nodes_to[--nodes_to_pos] = root;
}

// traverse component
int mincost;
int mincostcount;
void trav_comp(node* root)
{
    // traverse edges backward
    root->state = state::traversed;
    for (node* n : root->nodes_bw)
        if (n->state == state::top_ordered)
            trav_comp(n);

    // process node of current component
    if (root->cost == mincost)
        ++mincostcount;
    if (root->cost < mincost)
    {
        mincost = root->cost;
        mincostcount = 1;
    }
}


int main()
{
    // load nodes
    int n;
    cin >> n;
    node* nodes = new node[n];
    for (int i = 0; i < n; ++i)
    {
        int cost;
        cin >> cost;
        nodes[i] = { cost, state::initial, vector<node*>(), vector<node*>() };
    }

    // load edges
    int e;
    cin >> e;
    for (int i = 0; i < e; ++i)
    {
        int start, end;
        cin >> start >> end;
        --start; --end;
        nodes[start].nodes_fw.push_back(&nodes[end]);
        nodes[end].nodes_bw.push_back(&nodes[start]);
    }

    // create topological order
    nodes_to = new node*[n];
    nodes_to_pos = n;
    for (int i = 0; i < n; ++i)
        if (nodes[i].state == state::initial)
            top_order(&nodes[i]);

    // enumerate strongly connected components
    ulong minsum = 0;
    ulong variations = 1;
    for (int i = 0; i < n; ++i)
    {
        node* root = nodes_to[i];
        if (root->state == state::top_ordered)
        {
            // process new component containing root
            mincost = INT_MAX;
            mincostcount = 0;
            trav_comp(root);

            // adjust results
            minsum += mincost;
            variations = (variations * mincostcount) % 1000000007;
        }
    }

    // print results
    cout << minsum << " " << variations << endl;
    return 0;
}
