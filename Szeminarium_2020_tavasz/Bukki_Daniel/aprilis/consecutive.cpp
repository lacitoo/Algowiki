#include <iostream>
#include <vector>
#include <queue>
using namespace std;


int main()
{
    int n, lim;
    cin >> n >> lim;
    vector<int>* nodes = new vector<int>[n];
    int* parents = new int[n];
    int* blocks = new int[n];
    int* tblocks = new int[n];
    for (int i = 0; i < n; ++i)
    {
        cin >> blocks[i];
        parents[i] = -1;
    }
    for (int i = 1; i < n; ++i)
    {
        int x, y;
        cin >> x >> y;
        --x; --y;
        nodes[x].push_back(y);
        nodes[y].push_back(x);
    }

    int count = 0;
    queue<int> q;
    q.push(0);
    tblocks[0] = blocks[0];
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        if (tblocks[node] <= lim)
        {
            bool leaf = true;
            for (int other : nodes[node])
            {
                if (other != parents[node])
                {
                    leaf = false;
                    parents[other] = node;
                    q.push(other);
                    if (blocks[other] != 0)
                        tblocks[other] = tblocks[node] + blocks[other];
                    else tblocks[other] = 0;
                }
            }
            if (leaf) ++count;
        }
    }
    cout << count << endl;
}