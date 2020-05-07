#include <iostream>
#include <vector>
using namespace std;


struct node
{
    int id;
    int enter, low;
    bool unprocessed;
    int visited;
    vector<node*> nodes;

    node(int id) : id(id), enter(-1), low(-1), unprocessed(true), visited(0) {}
};

struct cutdata
{
    node* cutpoint;
    int comps;
    int maxcomp;

    cutdata(node* cutpoint) : cutpoint(cutpoint), comps(0), maxcomp(0) {}
};

struct link
{
    node* value;
    link* next;

    link(node* value, link* next) : value(value), next(next) {}
};


int visittoken = 0;
cutdata* bestcut = nullptr;
void analyze(node* cutpt)
{
    // gather relevant cut point data
    cutdata* data = new cutdata(cutpt);

    // traverse isolated components
    ++cutpt->visited;
    for (node* n : cutpt->nodes)
    {
        // if still unvisited
        if (n->visited == visittoken)
        {
            // then it is a separate component
            ++n->visited;

            // visit component of n with non-recursive dfs
            int size = 0;
            link* l = new link(n, nullptr);
            while (l != nullptr)
            {
                ++size;
                link* next = l->next;
                for (node* sub : l->value->nodes)
                {
                    if (sub->visited == visittoken)
                    {
                        ++sub->visited;
                        next = new link(sub, next);
                    }
                }
                delete l;
                l = next;
            }

            // update cut point data
            ++data->comps;
            if (size > data->maxcomp)
                data->maxcomp = size;
        }
    }
    ++visittoken;

    // update global best if this data is better
    if (bestcut == nullptr || (data->comps > bestcut->comps ||
        (data->comps == bestcut->comps && (data->maxcomp < bestcut->maxcomp ||
        (data->maxcomp == bestcut->maxcomp && data->cutpoint->id < bestcut->cutpoint->id)))))
    {
        if (bestcut != nullptr)
            delete bestcut;
        bestcut = data;
    }
    else delete data;
}


int iteration = 0;
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
                if (root->unprocessed)
                {
                    // root is a new cut point
                    root->unprocessed = false;
                    
                    // analyze and update if better
                    analyze(root);
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
    if (parent == nullptr && te_children > 1 && root->unprocessed)
    {
        // root is a new cut point
        root->unprocessed = false;

        // analyze and update if better
        analyze(root);
    }
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // load graph
    int n, e;
    cin >> n >> e;
    node** nodes = new node*[n];
    for (int i = 0; i < n; ++i)
        nodes[i] = new node(i + 1);
    for (int i = 0; i < e; ++i)
    {
        int n1, n2;
        cin >> n1 >> n2;
        --n1; --n2;
        nodes[n1]->nodes.push_back(nodes[n2]);
        nodes[n2]->nodes.push_back(nodes[n1]);
    }

    // find best cut point
    node* root = nodes[0];
    discover(nullptr, root);
    cout << bestcut->cutpoint->id << endl;

    // clean up
    for (int i = 0; i < n; ++i)
        delete nodes[i];
    delete[] nodes;
    return 0;
}
