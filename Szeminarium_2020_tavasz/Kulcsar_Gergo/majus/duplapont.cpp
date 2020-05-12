#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int timer;
int res = 1;
vector<int> r;

struct Vertex {
    Vertex(int _ind) : ind(_ind) {}
    int tin;
    int low;
    int ind;
    bool visited = false;
    bool visited2 = false;
    vector<int> edges;
};

class Graph_EL
{
public:
    Graph_EL(int _n) : n(_n) {
        for (int i = 0; i < n; ++i) {
            Vertex vert(i);
            v.push_back(vert);
        }
    }

    void addEdge(int a, int b) {
        v[a].edges.push_back(b);
        v[b].edges.push_back(a);
    }

    int n;
    vector<Vertex> v;

    void dfs(int from, int parent = -1) {
        v[from].visited = true;
        v[from].tin = v[from].low = timer++;
        for (int to : v[from].edges) {
            if(to == parent) continue;
            if (v[to].visited)
                v[from].low = min(v[from].low, v[to].tin);
            else{
                dfs(to, from);
                v[from].low = min(v[from].low, v[to].low);
                if(v[to].low > v[from].tin){
                    v[to].visited2 = true;
                }
            }
        }
    }

    void result(int from, int parent = -1){
        v[from].visited2 = true;
        for(int to : v[from].edges) {
            if(to == parent) continue;
            if(!v[to].visited2){
                r.push_back(to);
                ++res;
                result(to, from);
            }
        }
    }
};



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, start;
    cin >> n >> m >> start;

    Graph_EL graph(n+1);
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        graph.addEdge(a, b);
    }

    graph.dfs(start);

    r.push_back(start);
    graph.result(start);
    cout << res << endl;
    for(int i : r){
        cout << i << " ";
    }

    return 0;
}