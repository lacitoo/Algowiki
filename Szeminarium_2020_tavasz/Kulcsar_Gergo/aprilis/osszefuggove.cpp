#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

vector<bool> used;
vector<int> order, component;

struct Vertex {
    Vertex(int _ind) : ind(_ind) {}

    int ind;
    bool visited = false;
    vector<int> edges;
};

class Graph_EL {

    public:
        Graph_EL(int _n) : n(_n) {
            for (int i = 0; i < n; ++i) {
                Vertex vert(i);
                Vertex ver(i);
                g.push_back(vert);
                gr.push_back(ver);
            }
        }

        void addEdge(int a, int b) {
            g[a].edges.push_back(b);
            gr[b].edges.push_back(a);
        }

        void dfs1(int v) {
            used[v] = true;
            for(int i : g[v].edges){
                if(!used[i])
                    dfs1(i);
            }
            order.push_back(v);
        }

        void dfs2(int v) {
            used[v] = true;
            component.push_back(v);
            for(int i : gr[v].edges)
                if(!used[i])
                    dfs2(i);
        }
        vector<Vertex> g, gr;
        
    private:
        int n;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, m;
    cin >> N >> m;

    Graph_EL graph(N+1);
    for(unsigned int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        graph.addEdge(a, b);
    }

    used.resize(N, false);
    for(int i = 1; i < N+1; ++i){
        if(!graph.g[i].visited)
            graph.dfs1(i);
    }

    used.assign(N, false);
    for(int i=0; i<N; ++i) {
        int v = order[N-1-i];
        if(!used[v]) {
            graph.dfs2(v);
        }
    }

    cout << component[N-1] << " " << component[0];
}