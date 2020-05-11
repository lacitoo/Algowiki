#include <unordered_map>
#include <queue>
#include <iostream>
#include <algorithm>
 
using namespace std;
 
typedef pair<string, int> node;
unordered_map<string, int> visited;
queue<node> bfs;
 
int main(){
    ios_base::sync_with_stdio(false);
    string abc = "abcdefghij";
    bfs.push(node(abc,0));
    visited.emplace(abc,0);
 
    while(!bfs.empty()){
        node n = bfs.front();
        bfs.pop();
 
        for(int i = 0; i < 9; ++i){
            for(int j = i+1; j <= 9; ++j){
                string nb = n.first;
                reverse(nb.begin()+i,nb.begin()+j+1);
                if(visited.find(nb) == visited.end()){
                    visited.emplace(nb, n.second + 1);
                    bfs.emplace(nb, n.second+1);
                }
            }
        }
    }
 
    string a, b;
    cin>>a>>b;
   
    while(a != "*"){
       
       
        string find = abc;
        for(int i = 0; i < 10; ++i){
            for(int j = 0; j < 10; ++j){
                if(i != j && a[i] == b[j])
                    find[j] = abc[i];
            }
        }
 
        cout<<visited[find]<<'\n';
 
        cin>>a>>b;
    }
   
    return 0;
}