//MESTER -> Halado -> DFS -> 47
#include <iostream>
#include <vector>
#include <queue>

//#define DEBUG_MODE;

using namespace std;


struct Vertex {
    Vertex(int _ind) : ind(_ind) {}

    int ind;
    bool visited = false;
    bool done = false;
    vector<int> edges;
};

class Utcasepro
{
public:
    Utcasepro(int _n) : n(_n) {
        for (int i = 0; i < n; ++i) {
            Vertex vert(i);
            v.push_back(vert);
        }
    }

    void addEdge(int a, int b) {
        v[a].edges.push_back(b);
        v[b].edges.push_back(a);
    }

    void solve() {
        dfs(-1, 0);
    }

    vector<int> solution() {
        return result;
    }
private:
    int n;
    vector<Vertex> v;
    vector<int> result;

    void dfs(int before, int from) {
        v[from].visited = true;
        result.push_back(from);

        for (int to : v[from].edges) {
            if (to == before || v[to].done) {
                continue;
            }
            if (!v[to].visited) {
                dfs(from, to);
            } else {
                result.push_back(to);
            }
            result.push_back(from);
        }

        v[from].done = true;
    }
};



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    Utcasepro us(n);
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        us.addEdge(a - 1, b - 1);
    }

    us.solve();
    vector<int> result = us.solution();
    for (int a : result) {
        cout << a + 1 << " ";
    }

    return 0;
}