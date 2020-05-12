#include <bits/stdc++.h>

using namespace std;

int n,p,sum,maxinterv,/*j,*/x[100000],s[100000],interv;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>p;
	
	maxinterv = 0;
	sum = 0;
	interv = 0;
	for(int i=0;i<n;++i){
        cin>>x[i];
        sum+=x[i];
        ++interv;
        if(sum<=p&&interv>maxinterv){
            maxinterv = interv;
        }else{
            sum-=x[i-(--interv)];
        }

	}
	cout<<maxinterv<<endl;

	return 0;
}
