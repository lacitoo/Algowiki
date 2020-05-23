#include <iostream>
#include <vector>
#include <queue>
#define MAX_N 200000
#define UNVISITED -1

//a fa, szomsz�ds�gi list�ban elt�rolva
std::vector<int> tree[MAX_N];

//cs�csok t�vols�gai a gy�k�r elemt�l
int distA[MAX_N];

//cs�csok t�vols�gai az x cs�cst�l
int distB[MAX_N];

int main() {
    std::ios_base::sync_with_stdio(false);

    int N, x;
    std::cin >> N >> x;

    //a 0-t�l indexelt cs�csok miatt
    x--;

    //szomsz�d-p�rok beolvas�sa
    for (int i = 0; i < N - 1; ++i) 
    {
        int a, b;
        std::cin >> a >> b;

        //a 0-t�l indexelt cs�csok miatt
        a--;
        b--;

        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    //a t�vols�got t�rol� vectorok inicializ�l�sa N elemre, UNVISITED(-1) �rt�kre
    std::fill(distA, distA + N, UNVISITED);
    std::fill(distB, distB + N, UNVISITED);
    

    //              iterat�v m�lys�gi bej�r�s a gy�k�rt�l kezdve
    /////////////////////////////////////////////////////////////////////////////
 
    std::queue<int> bfs;
    bfs.push(0);

    //a gy�k�r elem �nmag�t�l vett t�vols�ga 0
    distA[0] = 0;

    while (!bfs.empty())
    {
        for (int n : tree[bfs.front()])
        {
            if (distA[n] == UNVISITED)
            {
                //az aktu�lis elem gy�k�r elemt�l vett t�vols�g := az aktu�lis
                //elem sz�l� elem�nek gy�k�rt�l vett t�vols�ga + 1
                distA[n] = distA[bfs.front()] + 1;
                bfs.push(n);
            }
        }
        bfs.pop();
    }
    
    //              iterat�v m�lys�gi bej�r�s az x cs�cst�l kezdve
    ////////////////////////////////////////////////////////////////////////////
    
    //bfs biztosan �res, ez�rt �jra felhaszn�lhat�
    bfs.push(x);

    //az x cs�cs �nmag�t�l vett t�vols�ga 0
    distB[x] = 0;

    //a maxim�lis t�vols�g amit agy�k�rb�l kiindulva meg kell tenni(ez minimum a gy�k�r �s az x cs�cs t�vols�ga)
    int maxDist = distA[x];
    while (!bfs.empty()) {

        for (int n : tree[bfs.front()]) 
        {
            //az n cs�csban m�g nem j�rtunk, �s a gy�k�r legal�bb 1 egys�ggel t�volabb van t�le, mint az x cs�cs
            if (distB[n] == UNVISITED && distA[n] > distB[bfs.front()] + 1) {
                distB[n] = distB[bfs.front()] + 1;
                bfs.push(n);

                //t�vols�g v�ltoz� aktualiz�l�sa
                if (distA[n] > maxDist)
                    maxDist = distA[n];
            }
        }
        bfs.pop();
    }

    std::cout << maxDist * 2 << '\n';
    return 0;
}