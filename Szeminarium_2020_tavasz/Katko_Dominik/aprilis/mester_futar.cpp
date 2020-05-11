#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int> > G;
vector<bool> visited;
vector<int> tav;
vector<int> ind;
int N, K, M;

void BFS(int start){
    for(int i=1;i<=N;i++){
        visited[i] = false;
    }
    queue<int> q;
    q.push(start);
    visited[start] = true;
    tav[start] = 0;
    while(!q.empty()){
        int current = q.front();
        q.pop();
        for (int v : G[current]){
            if (!visited[v]){
                q.push(v);
                visited[v] = true;
            }
            if (tav[v] > tav[current] + 1){
                cerr<<v<<" "<<tav[v]<<" "<<tav[current]<<endl;
                tav[v] = tav[current] + 1;
            }
        }
    }
}
int main()
{
    cin>>N>>K>>M;
    G.resize(N+1);
    visited.resize(N+1);
    tav.resize(N+1);
    int x,y;
    for(int i=1;i<=N;i++){
        tav[i] = N+1;
    }
    for(int i=0; i<M; i++){
        cin>>x>>y;
        G[x].push_back(y);
        G[y].push_back(x);
    }
    while(cin>>x){
        ind.push_back(x);
    }
    for(int i : ind){
        BFS(i);
    }
    int legtavolabb=0;
    for(int i=1;i<=N;i++){
        if(tav[i]>K){
            if (tav[i]>legtavolabb) legtavolabb = tav[i];
            cout<<i<<" ";
        }
    }
    cout<<endl<<legtavolabb/K+(legtavolabb%K==0 ? 0 : 1);
    return 0;
}
