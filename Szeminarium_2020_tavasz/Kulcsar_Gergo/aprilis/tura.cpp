#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> children;

int subtree(int p){
    int cnt = 1;
    for(int c:children[p]){
        cnt += subtree(c);
    }
    return cnt;
}

vector<vector<int>> g;
vector<bool> vis;

void DFS(int p){
    vis[p]=true;
    for(int v:g[p]){
        if(!vis[v])
            DFS(v);
    }
}

int main(){
    int n, m;
    cin >> n >> m;
    for(int i=0; i<m; i++){
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    vector<int> seged;
    int cnt = 0;
    for(int i=0; i<n; ++i){
        if(!vis[i]){
            ++cnt;
            seged.push_back(i);
            DFS(i);
        }
    }
    cout << cnt << endl;
    for(int i=0; i<seged.size(); ++i){
        cout << 1 << " " << seged[i] << endl;
    }
}