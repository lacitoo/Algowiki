#include <iostream>
#include <vector>
using namespace std;


int main()
{
    int n;
    cin >> n;

    int sum = 1;
    int* seq = new int[n + 1];
    for (int i = 0; i < n; ++i)
    {
        int l;
        cin >> l;
        seq[i] = sum;
        sum += l;
    }
    seq[n] = sum;

    int c;
    cin >> c;
    for (int i = 0; i < c; ++i)
    {
        int q;
        cin >> q;

        int min = 0;
        int max = n;
        while (min < max)
        {
            int m = (min + max) / 2;
            if (q < seq[m])
                max = m - 1;
            else if (q >= seq[m + 1])
                min = m + 1;
            else min = max = m;
        }

        if (q < seq[min])
            cout << min << endl;
        else if (q >= seq[min + 1])
            cout << min + 2 << endl;
        else cout << min + 1 << endl;
    }
    return 0;
}
