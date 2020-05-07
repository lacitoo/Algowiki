#include <iostream>
using namespace std;


// total heights might get big, so we store them in ulongs.
typedef unsigned long long ulong;


int main()
{
    int N;
    cin >> N;

    // load left row heights
    int* L = new int[N];
    for (int l = 0; l < N; ++l)
        cin >> L[l];

    // load right row heights
    int* R = new int[N];
    for (int r = 0; r < N; ++r)
        cin >> R[r];

    // initially: for 0 chosen people the maximum total height is always 0
    ulong NMax = 0;
    ulong LMax = 0;
    ulong RMax = 0;
    // select people starting from end of row
    for (int i = N - 1; i >= 0; --i)
    {
        // for the i-th position the maximum total height of selected people so far is:
        ulong n = LMax > RMax ? LMax : RMax;// if we select neither
        ulong l = L[i] + (RMax > NMax ? RMax : NMax);// if we pick the person on the left
        ulong r = R[i] + (LMax > NMax ? LMax : NMax);// if we pick the person on the right
        // set maximum total heights after the i-th pick
        NMax = n;
        LMax = l;
        RMax = r;
    }

    // initially we can pick either left or right, which is the same as if
    // we had picked neither in the round before, so the answer is in NMax:
    cout << (LMax > RMax ? LMax : RMax) << endl;
    return 0;
}
