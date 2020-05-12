#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main(){
    long long int n;
    cin >> n;
    vector<unsigned long long int> t, c;
    t.resize(n+1);
    c.resize(n+1);
    for(long long int i=1; i<n+1; ++i){
        cin >> t[i] >> c[i];
        ++t[i];
    }
    vector<unsigned long long int> dp;
    dp.assign(n+1, LLONG_MAX);
    dp[0] = 0;
    for(long long int i=1; i<n+1; ++i){
        for(long long int j=n; j>=0; --j){
            if(j>=t[i])
                dp[j] = min(dp[j], dp[j-t[i]] + c[i]);
            else
                dp[j] = min(dp[j], c[i]);
        }
    }
    cout << dp[n];
}