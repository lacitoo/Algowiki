#include <bits/stdc++.h>

using namespace std;

class Graph{
public:
    int N;
    vector< vector<int> > graph;
    vector<int> inviteNum;
    vector<bool> visited;

    Graph(int N){
        this->N = N;
        inviteNum.resize(N,0);
        graph.resize(N,vector<int>());
        visited.resize(N,false);
    }
    void addEdge(int to,int from){
        graph[to].emplace_back(from);
        inviteNum[from]+=1;
    }

    bool dfs(int v,int k){
        this->visited[v]=true;
        for(int i : this->graph[v]){
            if(this->inviteNum[v]<k){
                this->inviteNum[i]-=1;
            }
            if(!this->visited[i]){
                if(this->dfs(i,k)) this->inviteNum[v]-=1;
            }
        }
        return this->inviteNum[v]<k;
    }

    vector<int> getKCores(int k){
        this->dfs(0,k);
        for(int i=0;i<this->N;++i){
            if(!this->visited[i]){
                this->dfs(i,k);
            }
        }
        vector<int> solutions;
        for(int i=0;i<this->N;++i)
            if(this->inviteNum[i]>=k)
                solutions.emplace_back(i);
        return solutions;
    }
};

int n, a, b;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	cin>>n;
	Graph g(n);
    for(int i=0;i<n;++i){
        cin>>a>>b;
        g.addEdge(i,a-1);
        g.addEdge(i,b-1);
    }

    vector<int> solutions = g.getKCores(2);
    cout<<solutions.size()<<endl;
    for(int solution : solutions) cout<<solution+1<<" ";


	return 0;
}

