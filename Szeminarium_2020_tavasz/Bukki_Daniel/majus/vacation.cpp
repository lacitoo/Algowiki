#include <iostream>
using namespace std;


enum Options
{
    None = 0,
    Coding = 1,
    Sport = 2,
    Both = Coding | Sport
};

int main()
{
    int n;
    cin >> n;
    Options* O = new Options[n];
    for (int i = 0; i < n; ++i)
    {
        int o;
        cin >> o;
        O[i] = (Options)o;
    }

    int maxN = 0;
    int maxC = 0;
    int maxS = 0;
    for (int i = n - 1; i >= 0; --i)
    {
        int _maxN = maxN;
        if (maxC > _maxN) _maxN = maxC;
        if (maxS > _maxN) _maxN = maxS;

        int _maxC = 0;
        if ((O[i] & Options::Coding) == Options::Coding)
        {
            if (maxN > _maxC) _maxC = maxN;
            if (maxS > _maxC) _maxC = maxS;
            ++_maxC;
        }

        int _maxS = 0;
        if ((O[i] & Options::Sport) == Options::Sport)
        {
            if (maxN > _maxS) _maxS = maxN;
            if (maxC > _maxS) _maxS = maxC;
            ++_maxS;
        }

        maxN = _maxN;
        maxC = _maxC;
        maxS = _maxS;
    }

    int max = maxN;
    if (maxC > max) max = maxC;
    if (maxS > max) max = maxS;
    cout << n - max << endl;
    return 0;
}
