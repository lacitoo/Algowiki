#include <iostream>
#include <vector>
#include <queue>

#define MAXN 200000

using namespace std;

int N, X;

vector<int> elek[MAXN+1];

int parents[MAXN+1];
int decc[MAXN+1];
int szints[MAXN+1];

/* lassssúúúúúúúú megoldááááás */
int
dfs(int p)
{
    int m = 0;
    for(const auto c : elek[p]){
        if(szints[c]) continue;
        szints[c] = szints[p] + 1;
        parents[c] = p;

        int r = dfs(c) + 1;
        if(r > m){
            m = r;
        }
    }

    decc[p] = m;
    return m;
}

int
main()
{
    ios_base::sync_with_stdio(false);

    cin >> N >> X;

    for(int i = 0; i < N; i++){
        int a, b;
        cin >> a >> b;

        elek[a].push_back(b);
        elek[b].push_back(a);
    }

    szints[1] = 1;
    dfs(1);

    int medd = (szints[X] - 2)/2, piv = X;
    
    for(int i = 0; i < medd; i++)
        piv = parents[piv];

    cout << (decc[piv]+szints[piv]-1)*2 << endl;

    return 0;
}