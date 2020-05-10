#include <iostream>
#include <vector>
using namespace std;

int bin_s(int n, vector<int> g){
    int a,l=0,r=n;
        cin>>a;
        while(l<=r){
            int m = (l+r)/2;
            //cout<<"\t"<<m<<"\n";
            /*if(a<g[m] && a>g[m-1]){
                cout<<m<<"\n";
                return m;
            }else*/ 
            if(a>g[m]){
                l=m+1;
            }else if(a<=g[m-1]){
                r=m-1;
            }else{
                cout<<m<<"\n";
                return m;
            }
        }
}

int main(){
    int n,m,last=0;
    cin>>n;
    vector<int> g(n+1);
    g[0]=0;
    for(int i=1;i<=n;++i){
        int a;
        cin>>a;
        last+=a;
        g[i]=last;
    }
    cin>>m;
    for(int i=0;i<m;++i){
        bin_s(n,g);
    }

    return 0;
}