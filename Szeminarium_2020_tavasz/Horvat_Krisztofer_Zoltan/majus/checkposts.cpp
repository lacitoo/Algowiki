//https://codeforces.com/contest/427/problem/C
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


struct Vertex {
    Vertex(int _ind) : ind(_ind) {}

    int ind;
    long long int price;
    bool visited = false;
    vector<int> edges;
};

class Checkposts
{
public:
    Checkposts(int _n) : n(_n) {
        for (int i = 0; i < n; ++i) {
            Vertex vert(i);
            v.push_back(vert);

            vector<int> vec;
            transposed.push_back(vec);
        }
    }

    void setPrice(int ind, long long int price) {
        v[ind].price = price;
    }

    void addEdge(int a, int b) {
        v[a].edges.push_back(b);
        transposed[b].push_back(a);
    }

    long long int minPrice() {
        for (int i = 0; i < n; ++i) {
            if (!v[i].visited) {
                dfs1(i);
            }
        }
        
        reverse(order.begin(), order.end());
        clearVisited();
        for (int i = 0; i < n; ++i) {
            if (!v[order[i]].visited) {
                vector<int> vec;
                components.push_back(vec);
                dfs2(order[i]);
                ++currComp;
            }
        }

        long long int totalMin = 0;
        int i = 0;
        while (i < components.size()) {
            long long int min = v[components[i][0]].price;
            int numOfCheapests = 1;
            for (int j = 1; j < components[i].size(); ++j) {
                long long int price = v[components[i][j]].price;
                if (price < min) {
                    min = price;
                    numOfCheapests = 1;
                } else if (price == min) {
                    ++numOfCheapests;
                }
            }
            totalMin += min;
            num0fWays = (num0fWays * numOfCheapests) % 1000000007;
            ++i;
        }
        
        return totalMin;
    }

    long long int numOfWays() {
        return num0fWays;
    }

private:
    int n, currComp = 0;
    vector<Vertex> v;
    vector<vector<int>> components, transposed;
    vector<int> order;
    long long int num0fWays = 1;

    void dfs1(int from) {
        v[from].visited = true;
        for (int to : v[from].edges) {
            if (!v[to].visited) {
                dfs1(to);
            }
        }
        order.push_back(from);
    }

    void dfs2(int from) {
        v[from].visited = true;
        components[currComp].push_back(from);
        for (int to : transposed[from]) {
            if (!v[to].visited) {
                dfs2(to);
            }
        }
    }

    void clearVisited() {
        for (int i = 0; i < n; ++i) {
            v[i].visited = false;
        }
    }
};



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n;

    Checkposts cp(n);
    for (int i = 0; i < n; ++i) {
        long long int a;
        cin >> a;
        cp.setPrice(i , a);
    }

    cin >> m;
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        cp.addEdge(a - 1, b - 1);
    }

    cout << cp.minPrice() << " ";
    cout << cp.numOfWays() << endl;

    return 0;
}