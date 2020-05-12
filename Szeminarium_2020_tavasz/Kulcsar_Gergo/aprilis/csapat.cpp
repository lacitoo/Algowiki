#include <iostream>
#include <vector>

using namespace std;

void bfs(int start, int csapat, vector<vector<int>> G, int C[]){
    for(int i = 0; i < G[start].size(); i++){
        if(C[G[start[i]]] == 0){
            if(csapat == 1)
                C[G[start[i]]-1] = 2;
            else
                C[G[start[i]]-1] = 1;
            bfs(G[start[i]], C[G[start[i]]-1], G, C);
        }
    }
}

int main(){
    int n, m;
    cin >> n >> m;
    int A[m], B[m];
    for(int i=0; i<m; i++){
        cin >> A[i];
        cin >> B[i];
    }
    std::vector<std::vector<int>> G;
    for(int i=0; i<m; i++){
        G[A[i]].push_back(B[i]);
        G[B[i]].push_back(A[i]);
    }
    int C[n];
    for(int i=0; i<n; i++){
        C[i] = 0;
    }
    
    for(int i=0; i<n; i++){
        if(C[i] == 0){
            C[i] = 1;
            bfs(i, 1, G, C);
        }
    }
    for(int i=0; i<n; i++){
        if(C[i] == 1){
            cout << i << " ";
        }
    }
    cout << endl;
    for(int i=0; i<n; i++){
        if(C[i] == 2)
            cout << i << " ";
    }
}