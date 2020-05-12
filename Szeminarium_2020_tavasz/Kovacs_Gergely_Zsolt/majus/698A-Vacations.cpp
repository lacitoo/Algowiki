#include <iostream>
#include <vector>
#define MIN(a, b) ((a) > (b) ? (b) : (a))

using namespace std;

int main() {
    int db, x;
    cin >> db;
    vector<int> comp(db, 0), sport(db, 0);
    for (int i = 0; i < db; i++) {
        cin >> x;
        if (x < 3) {
            if (x != 1)
                comp[i] = 1;
            if (x != 2)
                sport[i] = 1;
        }
    }

    for (int i = db - 2; i >= 0; i--) {
        sport[i] = MIN(sport[i] + comp[i + 1], sport[i + 1] + 1);
        comp[i] = MIN(comp[i] + sport[i + 1], comp[i + 1] + 1);
    }

    cout << MIN(sport[0], comp[0]);
    return 0;
}