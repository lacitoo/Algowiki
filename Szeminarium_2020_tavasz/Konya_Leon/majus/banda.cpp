// mester / NT, OKTV, IOI / IOI valogato 2019 / 5. banda szetvalasztasa

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

vector< vector<int> > adj;
int n,m,currTime,biggestComp,result,compSize,compNum,maxCompNum,minBiggestComp;
vector<bool> vis,visited,cut;
vector<int> disc,low;

void dfs2(int from){//used for counting
    visited[from]=true;
    for(int to : adj[from]){
        if(!visited[to]){
            dfs2(to);
            ++compSize;
        }
    }
}

void dfs(int u, int parent){
    vis[u] = true;
    disc[u] = low[u] = currTime+1;
    int child = 0;
    for(int v : adj[u]){
        if(v == parent) continue;
        if(!vis[v]){
            ++child;
            ++currTime;
            dfs(v, u);

            low[u] = min(low[u], low[v]);

            if((parent != -1 && low[v] >= disc[u]) || (parent == -1 && child > 1)){
                if(!cut[u]){
                    cut[u]=true;
                    visited.assign(n,false);
                    visited[u]=true;
                    biggestComp=-1;
                    compNum=0;
                    for(int from_u: adj[u]){//calculates the number of components and the size of the biggest component
                        if(!visited[from_u]){
                            compSize = 0;
                            dfs2(from_u);
                            ++compNum;
                            if(biggestComp<compSize){
                                biggestComp = compSize;
                            }
                        }
                    }
                    if((compNum==maxCompNum)&&(minBiggestComp>biggestComp)){
                        result = u;
                        minBiggestComp = biggestComp;
                    }else if(compNum>maxCompNum){
                        maxCompNum = compNum;
                        result = u;
                        minBiggestComp = biggestComp;
                    }
                }
            }
        }else{
            low[u] = min(low[u], disc[v]);
        }
    }
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n >> m;  // n = number of vertices, m = number of edges
    currTime = 0;
    vis.assign(n,false);
    disc.assign(n,0);
    low.assign(n,INT_MAX);

    adj.assign(n,vector<int>());
    cut.assign(n,false);

    int a, b;
    for(int i = 0; i < m; i++){
        cin >> a >> b;
        adj[a-1].emplace_back(b-1);
        adj[b-1].emplace_back(a-1);
    }

    result = -1;
    minBiggestComp = INT_MAX;
    maxCompNum = -1;

    dfs(1, -1);
    cout<<result+1;
    return 0;
}
