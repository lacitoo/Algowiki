#include <iostream>
#include <vector>

using namespace std;

vector< vector<int> > nodes;
vector< vector<int> > bridges;
vector<bool> visited;
vector<int> ids;
vector<int> low;
vector<int> finals;
bool solved;
int id,m,n,k,finalcount;

void dfs2(int at, int parent){
    visited[at] = true;
    finals.push_back(at+1);
    ++finalcount;
    for(int to:nodes[at]){
        if(to==parent){
            continue;
        }
        if(!visited[to]){
            dfs2(to,at);
        }
    }
}

void dfs(int at, int parent){
    vector<int> buffer;
    buffer.push_back(0);
    buffer.push_back(0);
    visited[at] = true;
    low[at] = ++id;
    ids[at] = id;
    for(int to : nodes[at]){
        if(to==parent){
            continue;
        }
        if(!visited[to]){
            dfs(to,at);
            low[at]=min(low[at],low[to]);
            if(ids[at]<low[to]){
                buffer[0]=at;
                buffer[1]=to;
                bridges.push_back(buffer);
            }
        }else{
            low[at]=min(low[at],ids[to]);
        }
    }

}

void findBridges(){
    if(!solved){
        for(int i=0;i<n;++i){
            if(!visited[i]){
                dfs(i,-1);
            }
        }
        solved=true;
    }
}

int main()
{
    cin>>n>>m>>k;
    --k;
    nodes.resize(n);
    for(int i=0;i<n;++i){
        nodes[i].clear();
    }
    visited.resize(n);
    ids.resize(n);
    low.resize(n);
    int a,b;
    for(int i=0;i<m;++i){
        cin>>a>>b;
        nodes[a-1].push_back(b-1);
        nodes[b-1].push_back(a-1);
    }
    findBridges();

    //burn bridges
    for(vector<int> bridge:bridges){
        for(int i=0;i<nodes[bridge[0]].size();++i){
            if(nodes[bridge[0]][i]==bridge[1]){
                nodes[bridge[0]].erase(nodes[bridge[0]].begin()+i);
            }
        }
        for(int i=0;i<nodes[bridge[1]].size();++i){
            if(nodes[bridge[1]][i]==bridge[0]){
                nodes[bridge[1]].erase(nodes[bridge[1]].begin()+i);
            }
        }
    }
    visited.clear();
    visited.resize(n,false);
    dfs2(k,-1);
    cout<<finalcount<<endl;
    for(int asd:finals){
        cout<<asd<<" ";
    }

    return 0;
}
