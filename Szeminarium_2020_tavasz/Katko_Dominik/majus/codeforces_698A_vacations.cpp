#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
 
using namespace std;
int n;
vector<bool> sport;
vector<bool> contest;
 
vector<int> rests[3];
 
int main(){
    cin>>n;
    sport.resize(n);
    contest.resize(n);
    rests[0].assign(n, 100);
    rests[1].assign(n, 100);
    rests[2].assign(n, 100);
    int e;
    for(int i=0; i<n; i++){
        cin>>e;
        if(e==0){
            sport[i] = false;
            contest[i] = false;
        }else if(e==1){
            sport[i] = false;
            contest[i] = true;
        }else if(e==2){
            sport[i] = true;
            contest[i] = false;
        }else if(e==3){
            sport[i] = true;
            contest[i] = true;
        }
        if(i==0){
            rests[0][0] = 1;
            if(sport[0]){rests[1][0]=0;}
            if(contest[0]){rests[2][0]=0;}
        }else{
            if(sport[i]){
                rests[1][i]=min(rests[2][i-1],rests[0][i-1]);
            }
            if(contest[i]){
                rests[2][i]=min(rests[1][i-1],rests[0][i-1]);
            }
            rests[0][i]=min(rests[1][i-1],(min(rests[2][i-1],rests[0][i-1])))+1;
        }
    }
    cout<<min(rests[1][n-1],(min(rests[2][n-1],rests[0][n-1])));
    return 0;
}