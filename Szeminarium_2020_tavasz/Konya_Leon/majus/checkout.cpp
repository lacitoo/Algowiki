#include <iostream>
#include <vector>
#include <climits>

using namespace std;

vector<unsigned long long int> t,c;
vector<unsigned long long int> dp;

long int n;

int main(){
    cin>>n;
    t.assign(n+1,0);
    c.assign(n+1,0);
    dp.assign(n+1,LLONG_MAX);
    for(long int i=1;i<=n;i++){
        cin>>t[i]>>c[i];
        ++t[i];
    }
    dp[0]=0;
    for(long int i=1;i<=n;i++)
        for(long int j=n;j>=0;--j)
            if(j>=t[i])    dp[j]=min(dp[j],dp[j-t[i]]+c[i]);
            else           dp[j]=min(dp[j],c[i]);

    cout<<dp[n];
    return 0;
}
