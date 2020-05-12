using namespace std;
#include <iostream>
#include <math.h>

int main()
{
    int x, y;
    cin >> x >> y;
    int aktualis = 1;
    int seged = pow(aktualis, 2);
    int vege;
    while (1) {
        if (seged % 2 == 0) {
            if ((seged / 2 > x && seged / 2 > y) || ((seged / 2) > x ) || ( (seged / 2) > y)) { vege = aktualis - 1; break; }
        }
        else {
            if  ( ((seged-1) / 2 > x && ((seged-1) / 2)+1 > y) || ((seged - 1) / 2) > x || (((seged - 1) / 2)+1 > x && (seged - 1) / 2 > y) || (((seged - 1) / 2) + 1 > x && ((seged - 1) / 2)+1 > y) || ((seged - 1) / 2) > y) { vege = aktualis - 1; break; }
        }
        aktualis++;
        seged = pow(aktualis, 2);

    }
    cout << vege << endl;
    return 0;
}

/*int x, y;
    cin >> x >> y;
    int aktualis = floor(sqrt(x + y));
    while (1) {
        if (aktualis % 2 == 0 && (pow(aktualis, 2) / 2 > x || pow(aktualis, 2) / 2 > y)) { aktualis--; }
        else if (aktualis % 2 == 1 && ((pow(aktualis, 2)-1) / 2 > x || (pow(aktualis, 2)-1) / 2 > y)) { aktualis--; }
        else { break; }
    }
    cout << aktualis << endl;
    return 0;*/