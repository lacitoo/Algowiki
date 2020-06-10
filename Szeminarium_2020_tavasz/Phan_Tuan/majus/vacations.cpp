        #include<bits/stdc++.h>
         
        using namespace std;
         
        int main()
        {
            int n;
            cin>>n;
            int a[n];
            for(int i=0;i<n;i++)
                cin>>a[i];
            int dp[3]={0,0,0},c=0;
            for(int i=0;i<n;i++)
            {
                if(a[i]==0)
                {
                    dp[0]=1;c++;
                    dp[1]=0;dp[2]=0;
                }
                if(a[i]==1)
                {
                    if(dp[1]==1)
                    {
                        dp[0]=1;dp[1]=0;c++;
                    }
                    else
                    {
                        dp[0]=0;dp[1]=1;dp[2]=0;
                    }
                }
                if(a[i]==2)
                {
                    if(dp[2]==1)
                    {
                        dp[0]=1;dp[1]=0;dp[2]=0;;c++;
                    }
                    else
                    {
                        dp[0]=0;dp[1]=0;dp[2]=1;
                    }
                }
                if(a[i]==3)
                {
                    if(dp[0]==1)
                    {
                        dp[0]=0;dp[1]=0;dp[2]=0;
                    }
                    else if(dp[1]==1)
                    {
                        dp[0]=0;dp[1]=0;dp[2]=1;
                    }
                    else if(dp[2]==1)
                    {
                        dp[0]=0;dp[1]=1;dp[2]=0;
                    }
                }
            }
            cout<<c;
        }