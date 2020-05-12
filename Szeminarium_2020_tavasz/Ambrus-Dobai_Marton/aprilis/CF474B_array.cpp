#include <iostream>
#include <vector>
using namespace std;

int main(){
    long n;cin>>n;
    vector<int> g; g.push_back(0);
    for(long i=0;i<n;++i){
        int a; cin>>a;
        for(long j=0;j<a;++j){
            g.push_back(i+1);
        }
    }
    long m;cin>>m;
    while(m--){
        long a;cin>>a;
        cout<<g[a]<<"\n";
    }
}