#include <iostream>
#include <stack>
#include <vector>

using namespace std;

void order(int v, stack<int> &Stack);
void dfs(int v);
void scc();

vector< vector<int> > g,gr;
vector<int> costs;
vector<bool> visited;
long long out1, out2;
int n,m,minval,counter;

void dfs(int v)
{
    visited[v] = true;
    if(costs[v]<minval){
        minval = costs[v];
        counter=1;
    }else if(costs[v]==minval)
        ++counter;

	for(int u : gr[v])
		if(!visited[u])
			dfs(u);
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

    visited.clear();
    visited.resize(n,false);

    for(int i = 0; i < n; i++)
        if(visited[i] == false)
            order(i, Stack);

    visited.clear();
    visited.resize(n,false);

    out1 = 0;
    out2 = 1;
    while (Stack.empty() == false)
    {
        int v = Stack.top();
        Stack.pop();

        if (visited[v] == false)
        {
            minval = INT_MAX;
            counter = 0;
            dfs(v);
            out1 = out1 + minval;
            out2 = (out2 * counter) % 1000000007;
        }
    }
}

int main()
{
    int temp,a,b;
    cin>>n;
    for(int i=0;i<n;++i){
        cin>>temp;
        costs.emplace_back(temp);
    }
    cin>>m;
    g.assign(n,vector<int>());
    gr.assign(n,vector<int>());
    visited.assign(n,false);
    for(int i=0;i<m;++i){
        cin>>a>>b;
        g[a-1].emplace_back(b-1);
        gr[b-1].emplace_back(a-1);
    }

    scc();
    cout<<out1<<" "<<out2;

    return 0;
}
