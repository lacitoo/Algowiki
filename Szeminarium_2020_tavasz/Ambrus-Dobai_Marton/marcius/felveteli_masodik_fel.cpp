#include <iostream>
using namespace std;

struct data{
    unsigned long s;
    unsigned long c1;
    unsigned long c2;
    unsigned long c3;
};

struct data x[3000];


int main(){
    std::ios_base::sync_with_stdio (false);
    int n;
    cin>>n;
    for (int i = 0; i < n; i++){
        cin>>x[i].s;
    }
    for (int i = 0; i < n; i++){
        cin>>x[i].c1;
        x[i].c2=-1;
        x[i].c3=-1;

        if(i==1){
            if(x[0].s<x[1].s){
                x[i].c2=x[0].c1 + x[i].c1;
            }
        } else if(i>1) {

        }
    }
    long maxsum = -1;

    cout<<maxsum;
    
}