#include <bits/stdc++.h>

#define MAXN 200000

using namespace std;


vector<int> g[MAXN];
int alice_dst[MAXN];
int bob_dst[MAXN];
bitset<MAXN> vis;

void dst_dfs(int x, int *dst) {
    
    vis[x] = true;
    
    for (auto y : g[x]) {
        if (!vis[y]) {
            dst[y] = dst[x]+1;
            dst_dfs(y, dst);
        }
    }
    
}

int bob_dfs(int x) {
    
    vis[x] = true;
    
    int ans = x;

    for (auto y : g[x]) {
        if (!vis[y] && alice_dst[y] > bob_dst[y]) {
            int r = bob_dfs(y);
            
            if (alice_dst[ans] < alice_dst[r])
                ans = r;
        }
    }
    
    return ans;
}

int main() {
    
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int n, x;
    
    cin >> n >> x;
    
    for (int i = 0; i < n-1; i++) {
        int a, b;
        cin >> a >> b;
        
        g[a-1].push_back(b-1);
        g[b-1].push_back(a-1);
    }
    
    
    vis.reset();
    alice_dst[0] = 0;
    dst_dfs(0, alice_dst);
     
     
    vis.reset();
    bob_dst[x-1] = 0;
    dst_dfs(x-1, bob_dst);
    
    
//    for (int i = 0; i < n; i++)
//        printf("%d ", alice_dst[i]);
//    printf("\n");
//    
//    for (int i = 0; i < n; i++)
//        printf("%d ", bob_dst[i]);
//    printf("\n");

   
    
    vis.reset();
    cout << 2 * alice_dst[ bob_dfs(x-1) ] << endl;
    
    return 0;
}
