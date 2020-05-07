#include <iostream>
#include <vector>
using namespace std;


struct component;
struct node
{
    int id;
    bool unordered;
    component* comp;
    vector<node*> fw;
    vector<node*> bw;
};


struct link
{
    node* value;
    link* next;
};

link* to_first;
void toporder(node* root)
{
    root->unordered = false;
    for (node* n : root->fw)
        if (n->unordered)
            toporder(n);
    link* l = new link();
    l->next = to_first;
    l->value = root;
    to_first = l;
}


struct component
{
    vector<node*> nodes;
    vector<component*> parents;
};

component* cur_comp;
void addnode(node* n)
{
    auto iter = cur_comp->nodes.begin();
    while (iter != cur_comp->nodes.end() && n->id > (*iter)->id)
        ++iter;
    cur_comp->nodes.insert(iter, n);
}
void createcomp(node* root)
{
    root->comp = cur_comp;
    addnode(root);
    for (node* n : root->bw)
        if (n->comp == nullptr)
            createcomp(n);
        else if (n->comp != cur_comp)
            cur_comp->parents.push_back(n->comp);
}



int main()
{
    // load graph
    int n, e;
    cin >> n >> e;
    node* nodes = new node[n];
    for (int i = 0; i < n; ++i)
        nodes[i] = { i + 1, true, nullptr, vector<node*>(), vector<node*>() };
    for (int i = 0; i < e; ++i)
    {
        int l, r;
        cin >> l >> r;
        --l; --r;
        nodes[l].fw.push_back(&nodes[r]);
        nodes[r].bw.push_back(&nodes[l]);
    }

    // create topological order
    to_first = nullptr;
    for (int i = 0; i < n; ++i)
        if (nodes[i].unordered)
            toporder(&nodes[i]);

    // create component graph
    vector<component*> comps;
    component* root = nullptr;
    link* l = to_first;
    while (l != nullptr)
    {
        link* next = l->next;
        if (l->value->comp == nullptr)
        {
            // discover component
            comps.push_back(cur_comp = new component());
            createcomp(l->value);
            if (cur_comp->parents.size() == 0)
            {
                // set root
                if (root == nullptr) root = cur_comp;
                else
                {
                    // multiple roots, no solution
                    root = nullptr;
                    break;
                }
            }
        }
        delete l;
        l = next;
    }

    // print result
    if (root == nullptr)
        cout << -1 << endl;
    else
    {
        for (node* node : root->nodes)
            cout << node->id << " ";
        cout << endl;
    }
    return 0;
}
