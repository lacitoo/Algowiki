#include <iostream>
#include <vector>
using namespace std;


// Egy varost reprezentalo struktura
struct varos
{
    int be, low;
    bool biztonsagos;
    vector<varos*> szomszedok;
};


int db;
int ido;
// Keressunk elvago pontokat
void keres(varos* forras, varos* v)
{
    // belepesi ido es kezdeti low-ertek beallitasa
    v->low = v->be = ido++;
    int faelek = 0;
    // jarjunk be minden sz szomszedot
    for (varos* sz : v->szomszedok)
    {
        if (sz->be == -1)
        {
            // meg nem jartuk be: v es sz kozott fael van
            keres(v, sz);
            if (sz->low < v->low)
                v->low = sz->low;
            if (sz->low >= v->be && forras != nullptr)
            {
                // v elvago pont: ha meg biztonsagoskent van jelolve, mar tudjuk, hogy nem az
                if (v->biztonsagos)
                {
                    // v egy meg nem eszlelt elvago pont
                    v->biztonsagos = false;
                    ++db;
                }
            }
            ++faelek;
        }
        else if (sz != forras)
        {
            // mar bejartuk: v es sz kozott vissza-el van
            if (sz->be < v->low)
                v->low = sz->be;
        }
    }
    // ha v a gyoker, kulon vizsgalni kell
    if (forras == nullptr && faelek > 1 && v->biztonsagos)
    {
        // a gyoker is elvago pont
        v->biztonsagos = false;
        ++db;
    }
}


int main()
{
    // elso reszfeladat
    int N, M;
    cin >> N >> M;
    while (N != 0 || M != 0)
    {
        // letrehozzuk a varosok tombjet
        varos* varosok = new varos[N];
        for (int i = 0; i < N; ++i)
        {
            varosok[i].be = varosok[i].low = -1;
            varosok[i].biztonsagos = true;
        }

        // beolvassuk a hidakat, elkeszitjuk a grafot
        for (int i = 0; i < M; ++i)
        {
            int u, v;
            cin >> u >> v;
            --u; --v;
            varosok[u].szomszedok.push_back(&varosok[v]);
            varosok[v].szomszedok.push_back(&varosok[u]);
        }

        // keresunk elvago pontokat es kiirjuk az eredmenyt
        ido = 0;
        db = 0;
        keres(nullptr, &varosok[0]);
        cout << db << endl;

        // kovetkezo reszfeladat
        delete[] varosok;
        cin >> N >> M;
    }
    return 0;
}
