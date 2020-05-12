#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> g;
vector<bool> visited;
vector<bool> double_enter;
int double_count = 0;

/*void dfs(int v, int prev) {
    visited[v] = true;
    for (int u : g[v]) {
        if (!visited[u]){
            dfs(u,v);
            if(double_enter[u]){double_enter[v]=true;}
        }else{
            if(double_enter[u] && u!=prev){
                double_enter[v]=true;
            }
        }
    }
    if(double_enter[v]){
        double_count+=1;
    }
}*/

/*void dfs(int v, int prev) {
    visited[v] = true;
    for (int u : g[v]) {
        if(visited[u]){
            if(double_enter[u] && u!=prev){
                double_enter[v]=true;
            }
        }
    }
    for (int u : g[v]) {
        if (!visited[u]){
            dfs(u,v);
            if(double_enter[u]){double_enter[v]=true;}
        }
    }
    if(double_enter[v]){
        double_count+=1;
    }
}*/

/*void dfs(int v, int prev) {
    visited[v] = true;
    for (int u = 0; u<g[v].size();++u) {
        if (!visited[g[v][u]]){
            dfs(g[v][u],v);
            if(double_enter[g[v][u]]){double_enter[v]=true;}
        }else{
            if(double_enter[g[v][u]] && g[v][u]!=prev){
                double_enter[v]=true;
            }
        }
    }
    if(!double_enter[v]){
        for (int u = g[v].size()-1;u>-1;--u) {
            if (!visited[g[v][u]]){
                dfs(g[v][u],v);
                if(double_enter[g[v][u]]){double_enter[v]=true;}
            }else{
                if(double_enter[g[v][u]] && g[v][u]!=prev){
                    double_enter[v]=true;
                }
            }
        }
    }
    if(double_enter[v]){
        double_count+=1;
    }
}*/

int main(){
    int n,m,s;
    cin>>n>>m>>s;
    g.resize(n);
    double_enter.resize(n);
    visited.resize(n);
    for(int i=0;i<m;++i){
        int a,b;
        cin>>a>>b;
        g[a-1].push_back(b-1);
        g[b-1].push_back(a-1);
    }
    double_enter[s-1]=true;
    dfs(s-1,-1);
    cout<<"\n"<<double_count<<"\n";
    for(int i=0;i<n;++i){
        if(double_enter[i]){
            cout<<i+1<<" ";
        }
    }

    return 0;
}

/*
11 12 3
3 2
2 4
4 3
1 3
2 6
6 10
6 11
2 11
5 7
5 8
5 4
7 8

5
3 2 4 6 11
*/