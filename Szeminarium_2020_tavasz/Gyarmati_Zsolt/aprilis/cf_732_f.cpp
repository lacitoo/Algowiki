#include <iostream>
#include <vector>

#define MAXN    400000
#define MAXM    400000

using namespace std;

struct el {
    int a;
    int b;
    bool isbridge;
};

el elek[MAXM+1];
/* v_a és v_b közötti élek + hanyadik élnek felelnek meg az eredeti listában */
vector<pair<int, int>> pontok[MAXN+1];

int N, M;

/* Tarjan algoritmushoz */
int tim[MAXN+1];
int low[MAXN+1];
int cnt = 1;

/* Legnagyobb komponens egy pontja és mérete, a 0 kezdőérték nekünk megfelelő */
int maxpoint;
int maxsize;

/* Elvágó élek megjelölése + legnagyobb elvágott részgráf egy pontjának
 * megkeresése Tarjan algoritmussal */
int
tarjan(int from, int current)
{
    tim[current] = cnt++;
    low[current] = tim[current];

    /* Jegyezzük, hogy bejárásnál hány másik pont van még a komponensen belül.*/
    int child = 1;

    for(const auto& c : pontok[current]){
        int to = c.first;
        
        if(!tim[to]){
            int rc = tarjan(current, to);
            low[current] = min(low[current], low[to]);
            if(low[to] == tim[to]){
                elek[c.second].isbridge = true;
                if(rc > maxsize){
                    maxsize = rc;
                    maxpoint = to;
                }
            }else
                child += rc;
        }else if (to != from){
            low[current] = min(low[current], tim[to]);
        }
    }
    return child;
}

void
bridges_from(int p)
{
    int rc = tarjan(p, p);
    if(rc > maxsize){
        maxsize = rc;
        maxpoint = p;
    }
}

/* Irányított körök készítése + hídak jó irányba forgatása */
void
fix_dfs(int from)
{
    /* Az elérési időre már nincs szükségünk, ezért újrahasznosíthatjuk mint
     * "járt-e" tömb. Mivel a Tarjan minden pontot bejárt, ezért itt az összes
     * érték nemnulla kezdetben. */
    tim[from] = 0;

    for(const auto& c : pontok[from]){
        int to = c.first;
        auto& ell = elek[c.second];

        if(tim[to]){
            /* "Oda élek" bejárási iránnyal szembe forgatva */
            fix_dfs(to);
            ell.a = to;
            ell.b = from;
        }else{
            /* Vissza élek az oda élekkel ellentétes irányba + a szülők is ebbe
             * a kategóriába fognak esni, ami pont jó nekünk. */
            ell.a = from;
            ell.b = to;
        }
    }
}

int
main()
{
    ios_base::sync_with_stdio(false);

    /* Beolvasás */
    cin >> N >> M;
    for(int i = 0; i < M; i++){
        cin >> elek[i].a >> elek[i].b;
        pontok[elek[i].a].push_back({elek[i].b, i});
        pontok[elek[i].b].push_back({elek[i].a, i});
    }

    /* Megoldás */
    bridges_from(1);
    fix_dfs(maxpoint);

    /* Kiíratás */
    cout << maxsize << endl;
    for(int i = 0; i < M; i++)
        cout << elek[i].a << " " << elek[i].b << endl;

    return 0;
}