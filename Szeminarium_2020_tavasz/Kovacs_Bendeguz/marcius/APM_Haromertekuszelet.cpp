using namespace std;
#include <iostream>
#include <vector>

void elsoharom(int* a, int* b, int* c)
{

}

int main()
{
    int n;
    vector<int> szamok;
    cin >> n;
    for (int i = 0; i < n; i++) { int seged; cin >> seged; szamok.push_back(seged); }

    int maxhossz = 0;
    if (n == 1) { maxhossz = 1; }
    else if (n == 2) { maxhossz = 2; }
    else {
        int akthossz = 3;
        int elso = 0;
        int akt1 = szamok[elso];
        int akt2 = szamok[elso+1];
        int akt3 = szamok[elso+2];
        int i = 3;
        while (i < n)
        {
            if (szamok[i] == akt1 || szamok[i] == akt2 || szamok[i] == akt3) { akthossz++; if (akthossz > maxhossz) { maxhossz = akthossz; } }
            else{
                elso++;
                akt1 = szamok[elso];
                akt2 = szamok[elso + 1];
                akt3 = szamok[elso + 2];
                if (akthossz > maxhossz) { maxhossz = akthossz; akthossz = 3; }
            }
            i++;
        }
    }
    cout << maxhossz;
}
