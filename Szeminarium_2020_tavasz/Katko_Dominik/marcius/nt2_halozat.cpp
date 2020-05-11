#include <iostream>
#include <vector>

using namespace std;
vector<vector<int>> g;
int N,M,K;
int main(){
    cin>>N>>M>>K;
    int a,b;
    g.resize(M+1);
    for (int i=0;i<M;i++){
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    int deleted=0;
    for (int i=1;i<=M;i++){
        if(g[i].size()<K){
            for(int j=1;j<=N;j++){
                for (int k=0;k<g[j].size();){
                    if(g[j][k] == i){
                        g[j].erase(g[j].begin() + k);
                    }else{k++;}
                }
            }
            g[i].clear();
        }
    }
    int db=0;
    cout<<g.size()<<endl;
    vector<int> indexes;
    for(int i=1;i<=N;i++){
        if(g[i].size()>=K){
            db++;
            indexes.push_back(i);
        }
    }
    cout<<db<<endl;
    for(int i=0;i<indexes.size();i++){
        cout<<indexes[i]<<" ";
    }

    return 0;
}
