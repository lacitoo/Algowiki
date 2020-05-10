#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> oazis;
int n,m;

vector<bool> visited;

void dfs(int v) {
    //cout<<" "<<v;
    visited[v] = true;
    for (int u : oazis[v]) {
        if (!visited[u])
            dfs(u);
    }
}

int main(){
    cin>>n>>m;
    oazis.resize(n+1);
    visited.resize(n+1);
    for (int i = 0; i < m; i++){
        int a,b;
        cin>>a>>b;
        oazis[a].push_back(b);
    }
    for (int i = 1; i < n+1; i++){
        //cout<<i<<" is visiting";
        dfs(i);
        //cout<<endl;
        bool all = true;
        //cout<<i<<" has path to";
        for (int j = 1; j < n+1; j++){
            all &= visited[j];
            //if(visited[j]){ cout<<" "<<j; }
            visited[j]=false;
        }
        //cout<<endl;
        if(all){ cout<<i<<" "; }
    }
    
}

/*
7 10
2 6
3 1
3 2
3 4
6 3
4 7
7 5
5 7
5 4
4 5


10/20 pont lassú megoldás
*/