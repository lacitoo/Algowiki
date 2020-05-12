#include <iostream>
#include <vector>
#include <queue>
 
using namespace std;
 
vector<vector<int> > G;
vector<bool> visited;
vector<int> depths;
 
void BFS(int start){
    depths[start]=1;
    queue<int> q;
    q.push(start);
    visited[start] = true;
    while(!q.empty()){
        int current = q.front();
        q.pop();
        for (int v : G[current]){
            if (!visited[v]){
                q.push(v);
                visited[v] = true;
                depths[v] = depths[current] +1;
            }
        }
    }
}
 
 
int main()
{
    int N;
    cin>>N;
    G.resize(N+1);
    visited.resize(N+1);
    depths.resize(N+1);
    vector<int> bosses;
    int x;
    for(int i=0; i<N; i++){
        visited[i] = false;
        cin>>x;
        if(x != -1){
            G[x].push_back(i+1);
        }else{
            bosses.push_back(i+1);
        }
    }
    for(int i: bosses) {
        if (!visited[i]){
            BFS(i);
        }
    }
    int max_depth = 0;
    for(int i : depths){
        //cerr<<i<<" ";
        if(i>max_depth) max_depth = i;
    }
    cout<<max_depth;
 
    return 0;
}