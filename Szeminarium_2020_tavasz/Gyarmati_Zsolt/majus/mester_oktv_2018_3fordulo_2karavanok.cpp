#include <iostream>
#include <vector>

using namespace std;

#define MAXN 5000
#define MAXM 100000

int N, M;

vector<int> pontok[MAXN+1];
vector<int> transz[MAXN+1];
char volte[MAXN+1];
char osszes;

int target;
void
dfs(int p)
{
    osszes--;
    volte[p] = target;
    for(const auto k : pontok[p]){
        if(volte[k] != target){
            dfs(k);
        }
    }
}

void
dfs2(int p)
{
    volte[p] = 0;
    for(const auto k : transz[p]){
        if(volte[k]){
            dfs2(k);
        }
    }
}

int
main()
{
    ios_base::sync_with_stdio(false);

    /* Beolv */
    cin >> N >> M;
    osszes = N;
    for(int i = 1; i <= M; i++){
        int a, b;
        cin >> a >> b;
        pontok[a].push_back(b);
        transz[b].push_back(a);
    }

    /* Csak arra vagyunk kíváncsiak, hogy ha lenne topologikus sorrendünk,
       akkor melyik lenne az első benne. */
    target = 1;
    int p = 1;
    for(; p <= N; p++){
        if(volte[p]) continue;
        dfs(p);
        if(!osszes)
            break;
    }

    /* Ha ez megoldás <=> létezik megoldás */
    osszes = N;
    target = 2;
    dfs(p);
    if(osszes) {
        cout << "-1" << endl;
        return 0;
    }

    /* Ha ez megoldás volt, akkor a vele erősen összefüggő komponensben lévők
       is azok. */
    dfs2(p);

    /* Kiír */
    for(int i = 1; i <= N; i++){
        if(!volte[i])
            cout << i << " ";
    }

    return 0;
}