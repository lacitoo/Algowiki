    #include <bits/stdc++.h>
    using namespace std;
     
    #define ll long long int
    #define N 100004
    #define inf 1e17
    #define mod 1000000007
     
    ll a[N];
    vector <ll> g[N],gr[N];
    stack <ll> s;
    ll vis[N];
    vector <ll> tmp;
     
    vector < vector<ll> > ans;
     
    void dfs(ll u)
    {
        vis[u]=1;
        for(ll v:g[u])
        {
            if(vis[v]==0)
                dfs(v);
        }
     
        s.push(u);
    }
     
    void dfs2(ll u)
    {
        vis[u]=1;
        tmp.push_back(u);
        for(ll v:gr[u])
        {
            if(vis[v]==0)
                dfs2(v);
        }
    }
     
     
    int main()
    {
        ll n;
        ll i;
        cin >> n;
        for(i=1;i<=n;i++)
        {
            cin >> a[i];
        }
        ll m;
        cin >> m;
        ll u,v;
        for(i=1;i<=m;i++)
        {
            cin >> u >> v;
            g[u].push_back(v);
            gr[v].push_back(u);
        }
     
        for(i=1;i<=n;i++)
        {
            if(vis[i]==0)
                dfs(i);
        }
        
        for(i=1;i<=n;i++)
        {
            vis[i]=0;
        }
     
        while(!s.empty())
        {
            u=s.top();
            s.pop();
            if(vis[u])
                continue;
            tmp.clear();
            dfs2(u);
            ans.push_back(tmp);
        }
     
     
        ll times=1;
        ll val=0;
        for(auto it:ans)
        {
            ll mn=inf;
            for(auto x:it)
            {
                if(a[x]<mn)
                {
                    mn=a[x];
                }
            }
            ll c=0;
            for(auto x:it)
            {
                if(a[x]==mn)
                {
                    c++;
                }
            }
            times=(times*c)%mod;;
            val+=mn;
        }
     
        cout << val << " " << times;
        return 0;
     
        
    }