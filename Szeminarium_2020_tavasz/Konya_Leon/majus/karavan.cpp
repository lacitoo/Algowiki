#include <iostream>
#include <stack>
#include <vector>

using namespace std;

void order(int v, stack<int> &Stack);
void dfs(int v);
void dfs2(int v, bool greenLight);
void scc();
void insertValue(vector<int> &vec, int val);

vector< vector<int> > g,gr;
vector<bool> visited,visited_task;
vector<int> solutions;
int n,m;
int nodesUnvisited;//dfs is using this

void insertValue(vector<int> &vec, int val){
    if(vec.size()==0){
        vec.insert(vec.begin(),val);
        return;
    }
    for(unsigned int i=0;i<vec.size();++i){
        if(val<=vec[i]){
            vec.insert(vec.begin()+i,val);
            return;
        }
    }
    vec.insert(vec.end(),val);
}

void dfs(int v){
    visited_task[v] = true;
    --nodesUnvisited;
    for(int u : g[v])
        if(!visited_task[u])
            dfs(u);
}

void dfs2(int v, bool greenLight)
{
    visited[v] = true;
    if(greenLight)
        insertValue(solutions,v+1);
    for(int u : gr[v])
        if(!visited[u])
            dfs2(u,greenLight);
}

void order(int v, stack<int> &Stack)
{
    visited[v] = true;

    for(int u : g[v])
        if(!visited[u])
            order(u,Stack);

    Stack.push(v);
}

void scc()
{
    stack<int> Stack;

    visited.assign(n,false);

    for(int i = 0; i < n; i++)
        if(!visited[i])
            order(i, Stack);

    visited.assign(n,false);
    while (!Stack.empty())
    {
        int v = Stack.top();
        Stack.pop();

        if (!visited[v])
        {
            visited_task.assign(n,false);
            nodesUnvisited = n;
            dfs(v);
            dfs2(v,nodesUnvisited==0);
        }
    }
}

int main()
{
    int a,b;
    cin>>n>>m;
    g.assign(n,vector<int>());
    gr.assign(n,vector<int>());
    for(int i=0;i<m;++i){
        cin>>a>>b;
        g[a-1].emplace_back(b-1);
        gr[b-1].emplace_back(a-1);
    }

    scc();

    if(solutions.size()==0) cout<<"-1";
    else for(int sol : solutions) cout<<sol<<" ";

    return 0;
}
