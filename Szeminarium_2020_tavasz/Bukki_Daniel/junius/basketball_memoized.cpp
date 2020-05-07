#include <iostream>
using namespace std;


typedef unsigned long long ulong;


int n;
int* L;
int* R;
ulong* NMax;
ulong* LMax;
ulong* RMax;

ulong calcNMax(int p);
ulong calcLMax(int p);
ulong calcRMax(int p);


// calculates the maximum height of selectable players
// if the selected player before p was 2 steps ago.
ulong calcNMax(int p)
{
    if (p >= n) return 0;
    if (NMax[p] == 0)
    {
        int p_ = p + 1;
        ulong ml = L[p] + calcLMax(p_);
        if (ml > NMax[p])
            NMax[p] = ml;
        ulong mr = R[p] + calcRMax(p_);
        if (mr > NMax[p])
            NMax[p] = mr;
    }
    return NMax[p];
}

// calculates the maximum height of selectable players
// if the selected player before p was 1 step ago from the left row.
ulong calcLMax(int p)
{
    if (p >= n) return 0;
    if (LMax[p] == 0)
    {
        int p_ = p + 1;
        ulong mn = calcNMax(p_);
        if (mn > LMax[p])
            LMax[p] = mn;
        ulong mr = R[p] + calcRMax(p_);
        if (mr > LMax[p])
            LMax[p] = mr;
    }
    return LMax[p];
}

// calculates the maximum height of selectable players
// if the selected player before p was 1 step ago from the right row.
ulong calcRMax(int p)
{
    if (p >= n) return 0;
    if (RMax[p] == 0)
    {
        int p_ = p + 1;
        ulong mn = calcNMax(p_);
        if (mn > RMax[p])
            RMax[p] = mn;
        ulong ml = L[p] + calcLMax(p_);
        if (ml > RMax[p])
            RMax[p] = ml;
    }
    return RMax[p];
}


int main()
{
    cin >> n;

    L = new int[n];
    for (int l = 0; l < n; ++l)
        cin >> L[l];

    R = new int[n];
    NMax = new ulong[n];
    LMax = new ulong[n];
    RMax = new ulong[n];
    for (int r = 0; r < n; ++r)
    {
        cin >> R[r];
        NMax[r] = 0;
        LMax[r] = 0;
        RMax[r] = 0;
    }

    cout << calcNMax(0) << endl;
    return 0;
}
