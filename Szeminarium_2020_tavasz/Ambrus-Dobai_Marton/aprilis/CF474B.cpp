#include <iostream>
#include <vector>
using namespace std;

int bin_s(int a, long n, vector<long> g)
{
    int l = 0, r = n+1;
    while (l <= r)
    {
        int m = (l + r) / 2;
        cout << "\t" << m << "\n";
        /*if(a<g[m] && a>g[m-1]){
                cout<<m<<"\n";
                return m;
            }else*/
        if (a > g[m])
        {
            l = m + 1;
        }
        else if (a <= g[m - 1])
        {
            r = m - 1;
        }
        else
        {
            cout << m << "\n";
            return m;
        }
    }
}

int lin_s(int a, vector<long> g)
{
    int j=0;
    while (a > g[j])
    {
        ++j;
    }
    cout << j << "\n";
}

int main()
{
    long n, m;
    cin >> n;
    vector<long> g(n + 1);
    g[0] = 0;
    for (long i = 1; i <= n; ++i)
    {
        int a;
        cin >> a;
        g[i] = g[i - 1] + a;
    }
    cin >> m;
    for (long i = 0; i < m; ++i)
    {
        int a;
        cin >> a;
        bin_s(a, n, g);
    }

    return 0;
}