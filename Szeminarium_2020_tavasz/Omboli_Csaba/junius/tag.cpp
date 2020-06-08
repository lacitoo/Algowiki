#include <iostream>
#include <vector>
#include <queue>
#define MAX_N 200000
#define UNVISITED -1

//a fa, szomszédsági listában eltárolva
std::vector<int> tree[MAX_N];

//csúcsok távolságai a gyökér elemtõl
int distA[MAX_N];

//csúcsok távolságai az x csúcstól
int distB[MAX_N];

int main() {
    std::ios_base::sync_with_stdio(false);

    int N, x;
    std::cin >> N >> x;

    //a 0-tól indexelt csúcsok miatt
    x--;

    //szomszéd-párok beolvasása
    for (int i = 0; i < N - 1; ++i) 
    {
        int a, b;
        std::cin >> a >> b;

        //a 0-tól indexelt csúcsok miatt
        a--;
        b--;

        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    //a távolságot tároló vectorok inicializálása N elemre, UNVISITED(-1) értékre
    std::fill(distA, distA + N, UNVISITED);
    std::fill(distB, distB + N, UNVISITED);
    

    //              iteratív mélységi bejárás a gyökértõl kezdve
    /////////////////////////////////////////////////////////////////////////////
 
    std::queue<int> bfs;
    bfs.push(0);

    //a gyökér elem önmagától vett távolsága 0
    distA[0] = 0;

    while (!bfs.empty())
    {
        for (int n : tree[bfs.front()])
        {
            if (distA[n] == UNVISITED)
            {
                //az aktuális elem gyökér elemtõl vett távolság := az aktuális
                //elem szülõ elemének gyökértõl vett távolsága + 1
                distA[n] = distA[bfs.front()] + 1;
                bfs.push(n);
            }
        }
        bfs.pop();
    }
    
    //              iteratív mélységi bejárás az x csúcstól kezdve
    ////////////////////////////////////////////////////////////////////////////
    
    //bfs biztosan üres, ezért újra felhasználható
    bfs.push(x);

    //az x csúcs önmagától vett távolsága 0
    distB[x] = 0;

    //a maximális távolság amit agyökérbõl kiindulva meg kell tenni(ez minimum a gyökér és az x csúcs távolsága)
    int maxDist = distA[x];
    while (!bfs.empty()) {

        for (int n : tree[bfs.front()]) 
        {
            //az n csúcsban még nem jártunk, és a gyökér legalább 1 egységgel távolabb van tõle, mint az x csúcs
            if (distB[n] == UNVISITED && distA[n] > distB[bfs.front()] + 1) {
                distB[n] = distB[bfs.front()] + 1;
                bfs.push(n);

                //távolság változó aktualizálása
                if (distA[n] > maxDist)
                    maxDist = distA[n];
            }
        }
        bfs.pop();
    }

    std::cout << maxDist * 2 << '\n';
    return 0;
}