#include <iostream>
#include <vector>
using namespace std;


struct node
{
    int id;
    int enter;
    int exit;
    vector<node*> nodes;
};


int iteration;
void traverse(node* root)
{
    cout << root->id << " ";
    root->enter = iteration++;
    for (node* n : root->nodes)
    {
        if (n->enter == -1)
        {
            traverse(n);
            cout << root->id << " ";
        }
        else if (n->exit != -1)
            cout << n->id << " " << root->id << " ";
    }
    root->exit = iteration++;
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
        nodes[i].enter = -1;
        nodes[i].exit = -1;
    }
    for (int i = 0; i < e; ++i)
    {
        int n1, n2;
        cin >> n1 >> n2;
        --n1; --n2;
        nodes[n1].nodes.push_back(&nodes[n2]);
        nodes[n2].nodes.push_back(&nodes[n1]);
    }

    iteration = 0;
    traverse(&nodes[0]);
    return 0;
}
