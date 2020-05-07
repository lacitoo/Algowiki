#include <iostream>
#include <vector>
#include <queue>
using namespace std;


class node
{
public:
    int parent;
    vector<int> children;

    node(int parent) : parent(parent), children() {}
};


int n;
node** nodes;


vector<int> getPath(int node)
{
    vector<int> path;
    int i = node;
    while (i != -1)
    {
        path.push_back(i);
        i = nodes[i]->parent;
    }
    return path;
}

int getTreeSize(int node)
{
    int count = 0;
    queue<int> q;
    q.push(node);
    while (q.size() != 0)
    {
        int i = q.front();
        q.pop();
        ++count;
        for (const int& c : nodes[i]->children)
            q.push(c);
    }
    return count;
}


int main()
{
    // read data header
    int x, y;
    cin >> n >> x >> y;
    --x; --y;

    // create tree graph
    nodes = new node*[n];
    nodes[0] = new node(-1);
    for (int i = 1; i < n; ++i)
    {
        int p;
        cin >> p;
        --p;
        nodes[i] = new node(p);
        nodes[p]->children.push_back(i);
    }

    // get paths to root
    vector<int> xpath = getPath(x);
    vector<int> ypath = getPath(y);

    // get distance
    while (xpath.size() != 0 && ypath.size() != 0 && xpath.back() == ypath.back())
    {
        xpath.pop_back();
        ypath.pop_back();
    }

    // print data
    if (xpath.size() == 0)
        cout << 1 << endl;
    else if (ypath.size() == 0)
        cout << 2 << endl;
    else cout << 3 << endl;
    cout << xpath.size() + ypath.size() << endl;
    cout << getTreeSize(x) - 1 << " " << getTreeSize(y) - 1 << endl;
    return 0;
}