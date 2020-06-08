#include <iostream>
#include <algorithm>
#include <vector>
#include <limits>

using namespace std;

void kiiras(int a[],int s);

int main()
{
    int n,min_price,min_sumprice;
    cin>>n;
    int s[n];
    int c[n];

    for(int i=0;i < n;i++)
    {
        cin>>s[i];
    }
    for(int i=0;i < n;i++)
    {
        cin>>c[i];
    }
    min_price=*min_element(c,c+n);
    min_sumprice=std::numeric_limits<int>::max();
    for(int i=0;i < n-2;i++)
    {
        if(c[i]+min_price*2 < min_sumprice)
        {
            for(int j=i+1;j < n-1;j++)
            {
                if(c[i]+c[j]+min_price < min_sumprice)
                {
                    for(int x=j+1;x < n;x++)
                    {
                        bool a=c[i]+c[j]+c[x] < min_sumprice;
                        bool b=s[i]<s[j] && s[j] < s[x];
                        if(a && b)
                        {
                            min_sumprice=c[i]+c[j]+c[x];
                        }
                    }
                }
            }
        }
    }
    if(min_sumprice==std::numeric_limits<int>::max())
    {
        cout<<-1;
    }else
    {
        cout<<min_sumprice;
    }
    return 0;
}
