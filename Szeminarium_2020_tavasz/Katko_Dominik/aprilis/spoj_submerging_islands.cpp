#include <iostream>
#include <vector>
using namespace std;

int n; // number of nodes
vector<vector<int> > adj; // adjacency list of graph

vector<bool> visited;
vector<bool> cutpoint;
vector<int> tin, low;
int timer;

void dfs(int v, int p = -1) {
    visited[v] = true;
    tin[v] = low[v] = timer++;
    int children=0;
    for (int to : adj[v]) {
        if (to == p) continue;
        if (visited[to]) {
            low[v] = min(low[v], tin[to]);
        } else {
            dfs(to, v);
            low[v] = min(low[v], low[to]);
            if (low[to] >= tin[v] && p!=-1)
                cutpoint[v] = true;
            ++children;
        }
    }
    if(p == -1 && children > 1)
        cutpoint[v] = true;
}

int find_cutpoints() {
    timer = 0;
    visited.assign(n, false);
    tin.assign(n, -1);
    low.assign(n, -1);
    cutpoint.assign(n, false);
    for (int i = 0; i < n; ++i) {
        if (!visited[i])
            dfs (i);
    }
    int cutpoints = 0;
    for (int i = 0; i < n; ++i) {
        if(cutpoint[i]) {cutpoints++;}
    }
    return cutpoints;
}
int main()
{
    int m;
    int u,v;
    while(true){
        cin>>n>>m;
        adj.resize(n+1);
        if(n==0 && m==0){
            return 0;
        }
        for(int i=0;i<m;i++){
            cin>>u>>v;
            adj[u-1].push_back(v-1);
            adj[v-1].push_back(u-1);
        }
        int a = find_cutpoints();
        cout<<a<<endl;
        adj.clear();
    }

    return 0;
}
