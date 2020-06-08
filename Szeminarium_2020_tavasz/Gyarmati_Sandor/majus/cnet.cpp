#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <algorithm>

using namespace std;

int n,m;

set<int> BFS(vector<vector<int>> G, int x) {
    set<int> reachable;
    queue<int> q;
    q.push(x);
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        if (reachable.find(v) == reachable.end()) {
            reachable.insert(v);
            for(vector<int>::iterator it=G[v].begin(); it!=G[v].end(); it++) {
                if (reachable.find(*it) == reachable.end())
                    q.push(*it);
            }
        }
    }
    return reachable;
}

set<int> findDomin(vector<vector<int>> G) {
    vector<int> Dominated(n);
    set<int> D;
    for(int i=0; i<n; i++) Dominated[i] = 0;
    
    for(int i=0; i<n; i++) {
        if (Dominated[i] == 0) {
            set<int> reachable = BFS(G, i);
            for(set<int>::iterator it=reachable.begin(); it!=reachable.end(); it++) {
                Dominated[*it] = 1;
                D.erase(*it);
            }
            D.insert(i);
        }
    }

    /*for(set<int>::iterator it=D.begin(); it!=D.end(); it++) {
        cout<<" "<<*it;
    }
    cout<<endl; */
    return D;
}


int main() {
    ios::sync_with_stdio(false);
    cin>>n>>m;
    vector<vector<int>> G(n), TG(n);
    int x, y;
    for(int i=0; i<m; i++) {
        cin>>x>>y;
        G[x].push_back(y);
        TG[y].push_back(x);
    }
    
    set<int> D = findDomin(G);
    set<int> CD = findDomin(TG);
    int addNodes;
    if (D.size()==1 && CD.size()==1 && *(D.begin())== *(CD.begin())) {
        addNodes = 0;
    } else {
        addNodes = (D.size() > CD.size()) ? D.size() : CD.size();
    }
    
    cout<<D.size()<<" "<<addNodes<<endl;
    return 0;
}

/*
6 12
0 1
0 2
1 0
1 2
2 0
2 1
3 4
3 5
4 3
4 5
5 3
5 4


5 6
0 1
0 3
0 4
1 3
1 4
4 2


*/
