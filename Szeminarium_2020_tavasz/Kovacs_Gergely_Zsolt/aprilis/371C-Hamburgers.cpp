#include <iostream>
#define AR0(db) ((db)*kell[0] - van[0]) * ar[0]
#define AR1(db) ((db)*kell[1] - van[1]) * ar[1]
#define AR2(db) ((db)*kell[2] - van[2]) * ar[2]
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define JO(db) (MAX(AR0(db), 0) + MAX(AR1(db), 0) + MAX(AR2(db), 0) <= penz)

using namespace std;

int main() {
    char c = 0;
    int kell[3] = {0, 0, 0}, van[3], ar[3];
    long long penz, db;
    bool sok;
    while (c != '\n') {
        c = cin.get();
        if (c == 'B')
            kell[0]++;
        if (c == 'S')
            kell[1]++;
        if (c == 'C')
            kell[2]++;
    }
    cin >> van[0] >> van[1] >> van[2];
    cin >> ar[0] >> ar[1] >> ar[2];
    cin >> penz;

    long long lepes;
    if (kell[0])
        lepes = db = (van[0] + penz / ar[0]) / kell[0];
    else if (kell[1])
        lepes = db = (van[1] + penz / ar[1]) / kell[1];
    else
        lepes = db = (van[2] + penz / ar[2]) / kell[2];
    while ((sok = !JO(db)) || JO(db + 1)) {
        lepes = lepes / 2 > 0 ? lepes / 2 : 1;
        if (sok)
            db -= lepes;
        else
            db += lepes;
    }
    cout << db << endl;
    return 0;
}