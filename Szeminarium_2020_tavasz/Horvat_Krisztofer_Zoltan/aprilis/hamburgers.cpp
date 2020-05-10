// Mester -> NT, OKTV, IOI válogató -> OKTV 2018/19 3. forduló -> 2.
#include <iostream>
#include <string>

using namespace std;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string recipe;
    getline(cin, recipe);

    long long int nb, ns, nc, pb, ps, pc, r;
    cin >> nb >> ns >> nc;
    cin >> pb >> ps >> pc;
    cin >> r;

    long long int cb = 0, cs = 0, cc = 0;
    for (char c : recipe) {
        switch (c){
            case 'B':
                ++cb;
                break;
            case 'S':
                ++cs;
                break;
            case 'C':
                ++cc;
                break;
        }
    }
    long long int min = 0, max = r + nb + ns + nc, curr;
    while (min + 1 < max) {
        long long int money = 0;
        curr = (min + max) / 2;
        money += (curr * cb > nb) ? (curr * cb - nb) * pb : 0;
        money += (curr * cs > ns) ? (curr * cs - ns) * ps : 0;
        money += (curr * cc > nc) ? (curr * cc - nc) * pc : 0;
        if (money > r) {
            max = curr - 1;
        } else {
            min = curr;
        }
    }

    long long int money = 0;
    money += (max * cb > nb) ? (max * cb - nb) * pb : 0;
    money += (max * cs > ns) ? (max * cs - ns) * ps : 0;
    money += (max * cc > nc) ? (max * cc - nc) * pc : 0;
    if (money > r) {
        cout << min << endl;
    } else {
        cout << max << endl;
    }

    return 0;
}