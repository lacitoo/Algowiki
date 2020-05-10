//MESTER -> Halado -> DFS -> 5
#include <iostream>
#include <vector>

using namespace std;


struct Vertex {
    Vertex(int _ind) : ind(_ind) {}

    int ind, in = -1, low = -1;
    bool visited = false;
    vector<int> edges;
};

class DuplanElerhetoElek
{
public:
    DuplanElerhetoElek(int _n, int _center) : n(_n), center(_center) {
        for (int i = 0; i < n; ++i) {
            Vertex vert(i);
            v.push_back(vert);
        }
    }

    void addEdge(int a, int b) {
        v[a].edges.push_back(b);
        v[b].edges.push_back(a);
    }

    int solve() {
        dfs(center, -1);

        for (int i = 0; i < n; ++i) {
            v[i].visited = false;
        }
        result.push_back(center);
        collect(center);

        return result.size();
    }

    vector<int> solution() {
        return result;
    }
private:
    int n, center, timer = 0;
    vector<Vertex> v;
    vector<int> result;

    void dfs(int from, int parent) {
        v[from].visited = true;
        ++timer;
        v[from].in = timer;
        v[from].low = timer;
        for (int to : v[from].edges) {
            if (to == parent) {
                continue;
            }
            if (!v[to].visited) {
                dfs(to, from);
                v[from].low = min(v[from].low, v[to].low);
            } else {
                v[from].low = min(v[from].low, v[to].in);
            }
        }
    }

    void collect(int from) {
        v[from].visited = true;
        for (int to : v[from].edges) {
            if (!v[to].visited && v[to].low < v[to].in) {
                result.push_back(to);
                collect(to);
            }
        }
    }

    int min(int a, int b) {
        return a < b ? a : b;
    }
};



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, center;
    cin >> n >> m >> center;

    DuplanElerhetoElek dee(n, center - 1);
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        dee.addEdge(a - 1, b - 1);
    }

    cout << dee.solve() << endl;

    vector<int> result = dee.solution();
    for (int a : result) {
        cout << a + 1 << " ";
    }
    cout << endl;

    return 0;
}