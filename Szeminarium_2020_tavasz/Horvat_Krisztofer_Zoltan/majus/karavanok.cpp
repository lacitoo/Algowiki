// Mester -> NT, OKTV, IOI válogató -> OKTV 2018/19 3. forduló -> 2.
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


struct Vertex {
    Vertex(int _ind) : ind(_ind) {}

    int ind, comp;
    bool visited = false;
    vector<int> edges;
};

class Karavanok
{
public:
    Karavanok(int _n) : n(_n) {
        for (int i = 0; i < n; ++i) {
            Vertex vert(i);
            v.push_back(vert);

            vector<int> vec;
            transposed.push_back(vec);
        }
    }

    void addEdge(int a, int b) {
        v[a].edges.push_back(b);
        transposed[b].push_back(a);
    }

    vector<int> solution() {
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

        clearVisited();
        dfs1(components[0][0]);

        for (Vertex vert : v) {
            if (!vert.visited) {
                vector<int> vec;
                return vec;
            }
        }
        
        return components[0];
    }

private:
    int n, currComp = 0;
    vector<Vertex> v;
    vector<vector<int>> components, transposed;
    vector<int> order;

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
        v[from].comp = currComp;
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
    cin >> n >> m;

    Karavanok kar(n);
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        kar.addEdge(a - 1, b - 1);
    }

    vector<int> result = kar.solution();
    if (result.size() == 0) {
        cout << -1 << endl;
    } else {
        sort(result.begin(), result.end());
        for (int vert : result) {
            cout << vert + 1 << " ";
        }
        cout << endl;
    }

    return 0;
}