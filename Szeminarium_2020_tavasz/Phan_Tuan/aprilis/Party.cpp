    #include <iostream>
    #include <vector>
     
    using namespace std;
     
    vector<vector<int> > G;
    vector <bool> visited;
    int mx=1;
     
    void addEdge(int a, int b){
        G[a].push_back(b);
    }
     
     
    void DFS(int p,int counter){
        mx=max(mx,counter);
        visited[p]=true;
        for(int v:G[p]){
            if(!visited[v]){
                DFS(v,counter+1);
            }
        }
    }
     
     
    int main()
    {
        int n,M,temp;
        cin >> n;
        G.resize(n+1);
        visited.resize(n+1);
        int m[n+1]={0};
        for (int i=1;i<=n;i++){    
            cin >> temp;
            if (temp==-1){
                m[i]=-1;
            }else{
            addEdge(temp,i);
            }
        }
        for (int i=1;i<n+1;i++){
            if (m[i]==-1 &&!visited[i]){
                DFS(i,1);
            }
        }
        cout <<mx<<"\n";
        
        
        return 0;
    }