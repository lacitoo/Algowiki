//Mester / Gráfok, szélességi bejárás / 5. Adott ponton átmenő legrövidebb kör
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> adj;
int n, s, minimal, minlast;

queue<int> q;
vector<bool> used;
vector<int> d, p, k;

int bfs(){
    q.push(s);
    used[s] = true;
    p[s] = -1;
    k[s] = -1;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int u : adj[v]) {
            if (!used[u]) {
                used[u] = true;
                q.push(u);
                d[u] = d[v] + 1;
                p[u] = v;
                k[u] = v;
            }else{
                if(u == s){
                    if(p[v] != s){
                        if(minimal > d[v]+1){
                            minimal = d[v]+1;
                            minlast = v;
                        }
                    }
                }
                if(p[u]==s){
                    if(minimal>d[v]+2){
                        minimal=d[v]+2;
                        minlast = u;
                        k[u] = v;
                    }
                }
            }
        }
    }
}

int main(){
    int m;
    cin>>n>>m>>s;
    s = s-1;
    adj.resize(n); 
    used.resize(n);
    d.resize(n);
    p.resize(n);
    k.resize(n);
    minimal=n+1;
    minlast=-1;
    for(int i=0;i<m;++i){
        int a,b;
        cin>>a>>b;
        adj[a-1].push_back(b-1);
        adj[b-1].push_back(a-1);
    }
    bfs();
    cout<<minimal<<"\n"<<s+1;
    int i = minlast;
    while(i!=s){
        cout<<" "<<i+1;
        i = k[i];
    }
}

/*
8 10 2
1 3
3 6
3 2
2 4
2 5
6 7
6 8
1 8
5 3
7 4
*/