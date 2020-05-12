#include <iostream>
#include <vector>
 
using namespace std;

int N, M;
 
vector< vector<int> > G;
vector< vector<int> > G2;
vector<bool> visited;
vector<int> order; //dfs elhagyasi ido - topologic
 
int target;
void dfs(int p){
    visited[p] = true;
    for(int k : G[p]){
        if(!visited[k]){
            dfs(k);
        }
    }
    order.push_back(p);
}
 
void dfs2(int p)
{
    visited[p] = true;
    for(int k : G2[p]){
        if(!visited[k]){
            dfs2(k);
        }
    }
}
 
int main()
{
 
    /* Beolv */
    cin >> N >> M;
    G.resize(N+1);
    G2.resize(N+1);
    for(int i = 1; i <= M; i++){
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G2[b].push_back(a);
    }
 
    visited.assign(N, false);
    for(int p = 1; p <= N; p++){
        if(!visited[p]) dfs(p);
    }

    visited.assign(N, false);
    dfs(*(--order.end()));
    //cerr<<"dfs visited: ";
    bool all = true;
    for(int i = 1; i<=N; i++){
        //if(visited[i]) cerr<<i<<" ";
        all = all && visited[i];
    }
    //cerr<<endl;
    if(!all) {
        cout << "-1" << endl;
        return 0;
    }
    visited.assign(N, false);
    dfs2(*(--order.end()));
    for(int i = 1; i <= N; i++){
        if(visited[i])
            cout << i << " ";
    }
 
    return 0;
}