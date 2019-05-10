#include <iostream>
#include <vector>

using namespace std;

int main() {
    // kis gyorsitas
    ios::sync_with_stdio(false);

    int N, A, B;
    cin >> N >> A >> B;
    A--, B--;

    // ebben taroljuk, hogy kinek ki a fonoke, kezdetben minden -1
    vector<int> bosses(N, -1);
    int boss, subordinate;

    for (int i = 0; i < N - 1; i++) {
        cin >> boss >> subordinate;

        bosses[subordinate - 1] = boss - 1;
    }

    // ebben taroljuk, hogy A-nak kik a fonokei
    vector<bool> bossesOfA(N, false);

    // itt jarjuk be, es nezzuk meg, hogy kik A fonokei
    int at = bosses[A]; // hogy magat A-t mar ne ertsuk bele
    while (at != -1) {
        bossesOfA[at] = true;

        at = bosses[at];
    }

    // itt jarjuk be B fonokeit es keressuk a kozoseket
    at = bosses[B];
    int solution = -1;
    while (at != -1 && solution == -1) {
        // found one
        if (bossesOfA[at]) {
            solution = at + 1;
        }

        at = bosses[at];
    }

    cout << solution << endl;

    return 0;
}
