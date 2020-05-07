#include <iostream>
using namespace std;


// Az osszmagasssag nagy lehet, hasznaljunk minel nagyobb egesz tipust
typedef unsigned long long ulong;


int main()
{
    int N;
    cin >> N;

    // Beolvassuk a bal oldali sor magassagait
    int* L = new int[N];
    for (int l = 0; l < N; ++l)
        cin >> L[l];

    // Beolvassuk a jobb oldali sor magassagait
    int* R = new int[N];
    for (int r = 0; r < N; ++r)
        cin >> R[r];

    // Hatulrol indulva: ha senkit nem valasztunk, az osszmagassag minden esetben 0
    ulong NMax = 0;
    ulong LMax = 0;
    ulong RMax = 0;
    // Visszafele haladva valasszunk jatekosokat
    for (int i = N - 1; i >= 0; --i)
    {
        // Az i-edik valasztas utani legnagyobb összmagassag
        ulong n = LMax > RMax ? LMax : RMax;// ha senkit nem valasztunk
        ulong l = L[i] + (RMax > NMax ? RMax : NMax);// ha a bal oldali jatekost valasztjuk
        ulong r = R[i] + (LMax > NMax ? LMax : NMax);// ha a jobb oldali jatekost valasztjuk
        // A kovetkezo korben mar ezekre az ertekekre hivatkozunk majd, mint eddigi legnagyobb osszegek
        NMax = n;
        LMax = l;
        RMax = r;
    }

    // A kezdeti valasztas mindegy (vagy bal, vagy jobb): amelyik nagyobb, az a valasz
    cout << (LMax > RMax ? LMax : RMax) << endl;
    return 0;
}
