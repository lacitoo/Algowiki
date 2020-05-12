#include <iostream>
#include <vector>
#include <stack>

#define MAXN 100000
#define MAXM 300000
#define MOD  1000000007
#define llu unsigned long long 

using namespace std;

int N, M;
int cost[MAXN+1];
vector<int> elek[MAXN+1];
vector<int> trans[MAXN+1];
bool volt[MAXN+1];
int topik[MAXN+1], topikptr;

llu mennyi = 0;
llu ways = 1;

void
dfs(int p)
{
    volt[p] = 1;
    for(const auto c : elek[p]){
        if(!volt[c])
            dfs(c);
    }
    topik[topikptr++] = p;
}

unsigned minv = 0;
int mindb = 0;

void
dfs2(int p)
{
    volt[p] = 0;
    if(cost[p] < minv){
        minv = cost[p];
        mindb = 1;
    }else if(cost[p] == minv){
        mindb++;
    }
    for(const auto c : trans[p]){
        if(volt[c])
            dfs2(c);
    }
}

// Kosaraju

int
main()
{
    ios_base::sync_with_stdio(false);

    // be
    cin >> N;
    for(int i = 1; i <= N; i++){
        cin >> cost[i];
    }
    cin >> M;
    for(int i = 1; i <= M; i++){
        int a, b;
        cin >> a >> b;
        elek[a].push_back(b);
        trans[b].push_back(a);
    }

    // do
    for(int i = 1; i <= N; i++){
        if(!volt[i])
            dfs(i);
    }

    while(topikptr >= 0){
        int m = topik[--topikptr];
        if(volt[m]){
            minv = -1;
            mindb = 0;
            dfs2(m);
            mennyi += minv;
            ways = (ways * mindb) % MOD;
        }
    }

    // ki
    cout << mennyi << " " << ways << endl;

    return 0;
}