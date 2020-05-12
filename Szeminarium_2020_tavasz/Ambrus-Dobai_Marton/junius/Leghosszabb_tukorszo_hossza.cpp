//Mester / Haladó / Dinamikus programozás / 55. Leghosszabb tükörszó hossza
#include <iostream>
using namespace std;

char s[1000];
short n,dp[1000][1000],done[1000][1000];

short max(short a, short b){
    return a>b?a:b;
}

short rec(short i, short j){
    //cout<<i<<" "<<j<<endl;
    if(done[i][j]){ return dp[i][j]; }
    if(i==j){ dp[i][j]=1; done[i][j]=true; return 1; }
    if(i>j || i<0 || j<0 || i>=n || j>=n){ return 0; }
    if(s[i]==s[j]){
        dp[i][j]=2+rec(i+1, j-1);
    }else{
        dp[i][j]=max(rec(i, j-1), rec(i+1, j));
    }
    done[i][j]=true;
    return dp[i][j];
}

int main(){
    cin>>s;
    while(s[n]!=0){ ++n; }
    /*rec(0,n-1);
    cout<<endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;*/
    cout<<rec(0,n-1)<<endl;
}