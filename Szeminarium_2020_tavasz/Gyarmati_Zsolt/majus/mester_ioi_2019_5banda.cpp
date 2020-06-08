#include <iostream>
#include <vector>

#define MAXN 10000
#define MAXM 500000

using namespace std;

vector<int> pontok[MAXN+1];

int N, M;

int tin[MAXN+1];
int low[MAXN+1];
int cnt = 1;

int valasz_komponens = 0, valasz_maxelottunk = 0, valasz = 1;

int
tarjan(int current, int parent)
{
    low[current] = tin[current] = cnt++;
    int komponensek = 1;    /* Hány komponensre szakítaná szét a gráfot a pont kivétele */
    int mi = 1;             /* Mennyi pont van előttünk + mi */
    int maxelottunk = 0;    /* Legnagyobb előttünk lévő komponens csúcsszáma */
    int mogottunk = N - 1;  /* A szülőnkkel egy komponensben hányan vannak */

    bool elvagopont = false;
    for(const auto next : pontok[current]) {
        if(next == parent) continue;

        if(!tin[next]) {
            int gyerekek = tarjan(next, current);

            /* Ha a pont elvágó pont, és kivételével létrejönne az a komponens, aminek pontja a 'next' azonosítójú */
            if(tin[current] <= low[next]) {
                elvagopont = true;
                maxelottunk = max(maxelottunk, gyerekek);
                mogottunk -= gyerekek;
                komponensek++;
            }
            mi += gyerekek;

            low[current] = min(low[current], low[next]);
        }else{
            low[current] = min(low[current], tin[next]);
        }
    }
    
    /* Ha elvágó pont volt + speciális vizsgálat a legelső pontra. */
    if(elvagopont && (current != 1 || (--komponensek >= 2))) {
        /* Lehet hogy a szülőnk komponense nagyobb, hiszen ezt az előbb nem vizsgáltuk. */
        maxelottunk = max(maxelottunk, mogottunk);

        /* Ha ez a pont a feladat szövege szerint jobb mint az eddigi, jegyezzük meg. */
        if(komponensek > valasz_komponens || (komponensek == valasz_komponens && maxelottunk <= valasz_maxelottunk)
           ){            
            /* Ha a legkisebb sorszámú */
            if(komponensek != valasz_komponens || maxelottunk != valasz_maxelottunk || current < valasz)
                valasz = current;
            valasz_komponens = komponensek;
            valasz_maxelottunk = maxelottunk;

        }
    }

    return mi;
}

int
main()
{
    ios_base::sync_with_stdio(0);

    /* Beolvasás */
    cin >> N >> M;
    for(int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        pontok[a].push_back(b);
        pontok[b].push_back(a);
    }

    /* Megoldás */
    tarjan(1, 1);
    
    /* Kiírás */
    cout << valasz << endl;

    return 0;
}