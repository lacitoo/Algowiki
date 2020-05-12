#include <iostream>
#include <vector>
using namespace std;

int n,m,s;
vector<vector<int>> g;
vector<int> number;
vector<bool> visited;
int double_count = 0;
int number_count;

vector<bool*> good;

int dfs(int v, int prev) {
    visited[v] = true;
    number[v] = number_count++;
    cout<<"this: "<<v+1<<" number: "<<number[v]<<"\n";
    int min=v;
    for (int u : g[v]) {
        if (!visited[u]){
            int a = dfs(u,v);
            if(number[min]>number[a]){
                number[min]=number[a];
                good[v]=good[a];
                cout<<"\tthis: "<<u+1<<" ret: "<<a+1<<" number[a]: "<<number[a]<<" is smaller\n";
            }
        }else{
            if(u!=prev && number[min]>number[u]){
                number[min]=number[u];
                good[v]=good[u];
                cout<<"\tthis: "<<u+1<<" number[u]: "<<number[u]<<" is smaller and not v\n";
            }
        }
    }
    return min;
}

int main(){
    bool True = true;
    bool False = false;
    cin>>n>>m>>s;
    g.resize(n);
    good.resize(n,&False);
    number.resize(n);
    cout<<"Itt meg jo resize utan\n";
    visited.resize(n);
    for(int i=0;i<m;++i){
        int a,b;
        cin>>a>>b;
        g[a-1].push_back(b-1);
        g[b-1].push_back(a-1);
    }
    cout<<"Itt meg jo beolvasas utan\n";
    good[s-1] = &True;
    cout<<"Itt meg jo pointer utan\n";
    number_count=0;
    dfs(s-1,-1);
    cout<<"Itt meg jo dfs utan\n";
    for(int i=0;i<n;++i){
        if(*good[i]==true){
            ++double_count;
        }
    }
    cout<<"\n"<<double_count<<"\n";
    for(int i=0;i<n;++i){
        if(*good[i]==true){
            cout<<i+1<<" ";
        }
    }
    cout<<"\n";

    return 0;
}

/*
11 12 3
3 2
2 4
4 3
1 3
2 6
6 10
6 11
2 11
5 7
5 8
5 4
7 8

5
3 2 4 6 11

11 12 3
1 3
3 2
6 2
10 6
11 6
11 2
4 2
5 4
7 5
8 5
7 8
4 3
*/