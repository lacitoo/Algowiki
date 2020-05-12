#include <iostream>
#include <vector>
using namespace std;
 
#define MAX 10005
 
int n;
 
vector <int> adj[MAX];
bool visited[MAX];
int tin[MAX],low[MAX];
int timer,artp;
bool art[MAX];  
void IS_CUTPOINT(int v);
 
 
 
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
             if(p == -1 && children > 1){
                art[v]=true;
            }
            if (low[to] >= tin[v] && p!=-1)
                art[v]=true;
            ++children;
        }
    }
    if(p == -1 && children > 1)
        art[v]=true;
}
 
void IS_CUTPOINT(int v){
    art[v]=true;
}
 
void find_cutpoints() {
    timer = 0;
    for (int i = 0; i < n; ++i) {
        if (!visited[i])
            dfs (i);
    }
}
 
int main(){
        int n, m, u, v;
   
    while(cin>>n>>m && m != 0 && n!= 0){
        artp = 0;
        for(int i= 1; i<=n; i++){
            visited[i]= false;
            tin[i]=-1;
            low[i]=-1;
            adj[i].clear();
            art[i]= false;
        }
       
        while(m--){
            cin>>u>>v;
 
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
       
        dfs(1);
       
 
       
        for(int i= 1; i<= n; i++){
            if(art[i]) artp++;
        }
       
        cout<< artp <<endl;
    }
 
    return 0;
}