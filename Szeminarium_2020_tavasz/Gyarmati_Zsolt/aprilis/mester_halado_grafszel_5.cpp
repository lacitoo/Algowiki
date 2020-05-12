/* Feladat: Mester / Gráfok, szélességi bejárás / Adott ponton átmenő legrövidebb kör */

#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <climits>

#define MAXN    10000
#define MAXM    200000

using namespace std;

int N, M, P;
vector<int> ponts[MAXN+1];
int szint[MAXN+1];
int ancestor[MAXN+1];

int
main()
{
    ios_base::sync_with_stdio(false);

    /* Beolvasás */
    cin >> N >> M >> P;
    for(int i = 0; i < M; i++){
        int a, b;
        cin >> a >> b;
        ponts[a].push_back(b);
        ponts[b].push_back(a);
    }

    /* Szélességi bejárás */
    queue<int> sor;
    sor.push(P);

    /*
       Segít, hogy "szintenként" tudjunk kiértékelni. Erre azért van szükség,
       mert páros és páratlan hosszú köröket is találhatunk egy "szint" bejárása
       során, melyből nekünk a legrövidebb kell. Tehát csak akkor mondunk
       ítéletet, hogyha már végleg bejártuk a szintet.
       Ezt pedig a 0 érték folyamatos "görgetésével" tesszük meg.
       Kezdetben feltesszük a 0-t, és hogyha megint elértük, akkor bejártuk az
       adott szintet. Ekkor kiértékelünk, és újra rátesszük a 0-t. Stb...
    */
    sor.push(0);

    /* A gyökértől vett távolság / szint egy jól megválasztott kezdeti értéke */
    int hossz = 2;

    /* Az éppen vizsgált esetleges kör hossza. */
    int minn = INT_MAX;

    /* A két pont, akik a bejárás során találkoztak. Egyikből a gyökérBE,
     * másikba a gyökérBŐL írjuk ki az utakat, hogy kört kapjunk.  */
    int a, b;

    szint[P] = 1;
    do{
        int most = sor.front();
        sor.pop();

        /* Ha végigértünk a szinten */
        if(!most){
            hossz++;
            /* Ha találtunk kört (a kör "hossza" nem a kezdeti INT_MAX) */
            if(minn != INT_MAX){
                /* Írjuk ki a hosszát */
                cout << (minn-1) << endl;

                /* Az egyik pontból akik találkoztak, fordítsuk meg a közte és
                 * a gyökér közt vezető utat. */
                stack<int> ss;
                ss.push(a);
                do{
                    a = ancestor[a];
                    ss.push(a);
                }while(a != P);

                /* Majd írjuk ezt ki */
                do{
                    int kk = ss.top();
                    ss.pop();
                    cout << kk << " ";
                }while(!ss.empty());

                /* A másik pontból pedig csak simán írjuk ki a tőle a gyökérig
                 * vezető utat. */
                do{
                    cout << b << " ";
                    b = ancestor[b];
                }while(b != P);
                cout << endl;
                
                return 0;
            }
            sor.push(0);
        }else{
            /* Szélességi bejárás */
            for(const auto c : ponts[most]){
                /* Ha még nem jártunk ott, honnan jutottunk el, és milyen
                 * távolságra vagyunk a gyökértől. */
                if(!szint[c]){
                    ancestor[c] = most;
                    szint[c] = hossz;
                    sor.push(c);
                }
                /* Ha már jártunk, és nem a szülőnk, akkor az csak úgy lehet,
                 * hogy a talált csúcs NINCS a jelenlegi és a gyökér közti úton.
                 * Tehát ezzel egy kört kapunk, amiben szerepel a gyökér.
                 * Viszont lehet nem a legrövidebb, tehát majd csak az adott
                 * szint bejárása után hozunk döntést erről. */
                else if(c != ancestor[most]){
                    /* Az ezekkel vett kör hossza a legrövidebb-e? */
                    int tm = szint[c] + szint[most];
                    if(tm < minn){
                        minn = tm;
                        a = c;
                        b = most;
                    }
                }
            }
        }
    }while(!sor.empty());

    /* Hogyha végetért a bejárás, és nem találtunk kört, akkor nincs kör. */
    cout << "-1" << endl;

    return 0;
}