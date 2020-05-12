#include <bits/stdc++.h>
#define maxN 10001
#define maxM 100001
using namespace std;
 
 
 
vector<int> G[maxN];
vector<int> Gt[maxN];
int order[maxN];
int comp[maxN];
bool sol[maxN];
int N,h;
 
void dfs(int p){
 
   comp[p]=1;
   for (int q:G[p]){
      if (comp[q]==0)
         dfs(q);
   }
 
   order[h--]=p;
}
void dfs2(int p){
 
   comp[p]=2;
   for (int q:G[p]){
      if (comp[q]==1)
         dfs2(q);
   }  
}
void dfs3(int p){
 
   comp[p]=2;
   sol[p]=true;
   for (int q:Gt[p]){
      if (comp[q]==0)
         dfs3(q);
   }
 
}
int main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  int x,y,M;
  cin>>N>>M;
  for(int i=1;i<=M;i++){
    cin>>x>>y;
    G[x].push_back(y);
    Gt[y].push_back(x);
  }  
  h=N;
  for(int i=1;i<=N;i++){
    comp[i]=0;
    sol[i]=false;
  }
  for(int i=1;i<=N;i++){
    if(comp[i]==0)
      dfs(i);
  }
  dfs2(order[1]);
  for(int i=1;i<=N;i++){
    if(comp[i]!=2){
      cout<<"\n"; return 0;
    }
    comp[i]=0;
  }
 
  dfs3(order[1]);
  for(int i=1;i<=N;i++) if(sol[i])
    cout<<i<<" ";
   cout<<endl;
return 0;
}