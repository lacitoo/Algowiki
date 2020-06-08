/*#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

//vector < vector<int> > g, gr; // g az eredeti gráf, gr a transzponáltja
vector<bool> used; // bejártuk-e már az adott csúcsot
vector<int> order, component; // order: az első fázis eredményeként kapott sorrend (itt növekvő sorrendben)
                                  // component: ide gyűjtjük az aktuálisan bejárt komponens csúcsait (2. fázisban)

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

    void dfs1(int v) { // első fázis, topologikus sor felállítása
        used[v] = true;
        cout << v;
        for(int i : g[v].edges)
            if(!used[g[v].edges[i]])
                dfs1(g[v].edges[i]);
        order.push_back(v);
    }

    void dfs2(int v) { // második fázis, 'v' komponensének bejárása
        used[v] = true;
        component.push_back(v);
        for(int i : gr[v].edges)
            if(!used[gr[v].edges[i]])
                dfs2(gr[v].edges[i]);
    }
    vector<Vertex> g, gr;
    
private:
    int n;
};

int main() {
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);

    int N, m;
    cin >> N >> m;

    Graph_EL graph(N+1);
    for(int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        graph.addEdge(a, b);
    }
    cout << N << endl;
    cout << N << endl;
    for(int i=1; i<N+1; ++i){
        cout<<"a" << endl;
        if(!graph.g[i].visited)
            graph.dfs1(i);
    }
    cout << order[0] << " " << order[N-1] << endl;
    /*used.assign (N, false);
    for (int i=0; i<N; ++i) {
        int v = order[N-1-i];
        if (!used[v]) {
            dfs2 (v);
            ... kiírjuk az aktuális komponenst: 'component' tartalmát ...
            component.clear();
        }
    }/
}*/

#include <vector>
#include <iostream>

using namespace std;

vector < vector<int> > g, gr; // g az eredeti gráf, gr a transzponáltja
vector<bool> used; // bejártuk-e már az adott csúcsot
vector<int> order, component; // order: az első fázis eredményeként kapott sorrend (itt növekvő sorrendben)
                                // component: ide gyűjtjük az aktuálisan bejárt komponens csúcsait (2. fázisban)

void dfs1 (int v) { // első fázis, topologikus sor felállítása
    used[v] = true;
    for (size_t i=0; i<g[v].size(); ++i)
        if (!used[ g[v][i] ])
            dfs1 (g[v][i]);
    order.push_back (v);
}

void dfs2 (int v) { // második fázis, 'v' komponensének bejárása
    used[v] = true;
    component.push_back (v);
    for (size_t i=0; i<gr[v].size(); ++i)
        if (!used[ gr[v][i] ])
            dfs2 (gr[v][i]);
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i<m; ++i) {
        int a, b;
        ... következő él (a,b) beolvasása ...
        g[a].push_back (b);
        gr[b].push_back (a);
    }

    used.assign (n, false);
    for (int i=0; i<n; ++i)
        if (!used[i])
            dfs1 (i);
    used.assign (n, false);
    for (int i=0; i<n; ++i) {
        int v = order[n-1-i];
        if (!used[v]) {
            dfs2 (v);
            ... kiírjuk az aktuális komponenst: 'component' tartalmát ...
            component.clear();
        }
    }
}