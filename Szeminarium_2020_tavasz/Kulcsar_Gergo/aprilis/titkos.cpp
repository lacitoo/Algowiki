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