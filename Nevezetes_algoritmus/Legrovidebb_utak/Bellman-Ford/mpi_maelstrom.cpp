#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

struct edge
{
    int a, b, cost;
};

void bellman_ford(const vector<edge>& edges, vector<int>& d, int n)
{
    d[0] = 0;
    for (int i=0; i<n-1; ++i)
    {
        for (edge e : edges)
        {
            if (d[e.a] < __INT_MAX__)
            {
                d[e.b] = min (d[e.b], d[e.a] + e.cost);
            }
            else if(d[e.b] < __INT_MAX__)
            {
                d[e.a] = min (d[e.a], d[e.b] + e.cost);
            }
        }
    }
}

int main()
{
    vector<edge> edges;
    int n;
    cin >> n;

    for(int i = 1, j = 0; i != n;)
    {
        string s;
        cin >> s;
        if(s != "x")
        {
            int weight = stoi(s);
            edges.push_back({i, j, weight});
            edges.push_back({j, i, weight});
        }


        if(j == i-1)
        {
            ++i;
            j = 0;
        }
        else
        {
            ++j;
        }
    }

    vector<int> d (n, __INT_MAX__);

    bellman_ford(edges, d, n);

    std::cout << *(std::max_element(d.begin(), d.end())) << std::endl;

    return 0;
}