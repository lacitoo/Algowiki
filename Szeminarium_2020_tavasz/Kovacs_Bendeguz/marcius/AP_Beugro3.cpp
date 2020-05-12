using namespace std;
#include <iostream>
#include <vector>

char alma[200001][3];
vector<int> voltak;
vector<int> megoldas;
int n;
int hanyvan;

void beolvasas()
{
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> alma[i][0] >> alma[i][1] >> alma[i][2];
        voltak.push_back(i);
    }
}

int illeszkedes(int a, int b)
{
    //if (alma[a][2] == alma[b][0]) { return 1; }
    if (alma[a][1] == alma[b][0] && alma[a][2] == alma[b][1]) { return 2; }
    //else if (alma[b][2] == alma[a][0]) { return 3; }
    else if (alma[b][1] == alma[a][0] && alma[b][2] == alma[a][1]) { return 4; }
    else { return 0; }

/*
0 - nem
1 - elsore szimplan a masodik
2 - elsore duplan a masodik
3 - masodikra szimplan az elso
4 - masodikra duplan az elso
*/

}

void kiir()
{
    cout << alma[megoldas[0]][0] << alma[megoldas[0]][1] << alma[megoldas[0]][2];
    for (int i = 1; i < n; i++)
    {
        cout << alma[megoldas[i]][2];
    }
}

void egyetkiir(int a)
{
    cout << alma[a][0] << alma[a][1] << alma[a][2] << "\n";
}

bool elemee(int a)
{
    for (int i = 0; i < hanyvan; i++)
    {
        if (voltak[i] == a) { return 1; }
    }
    return 0;
}

int main()
{
    beolvasas();
    hanyvan = n-1;
    int vege = 0;
    int aktualis = 0;
    //egyetkiir(aktualis);
    int baloldal = aktualis;
    megoldas.push_back(0);
    voltak.erase(voltak.begin());
    int k = 54;
    while (vege < 2)
    {
        int volteA = 0;
        if (k == 54) {
            int mennyiJobb = 0;
            int mennyiBal = 0;
            int aktJobb = 0;
            int aktBal = 0;
            int kintIJ = 0;
            int kintIB = 0;
            for (int i = 0; i < hanyvan; i++)
            {
                if (/*elemee(i) &&*/ illeszkedes(aktualis, voltak[i]) == 2) { mennyiJobb++; aktJobb = voltak[i]; kintIJ = i; }
                if (/*elemee(i) &&*/ illeszkedes(baloldal, voltak[i]) == 4) { mennyiBal++; aktBal = voltak[i]; kintIB = i; break; }
                if (mennyiJobb > 2) { break; }
            }
            if (mennyiJobb <= mennyiBal && mennyiJobb != 0) { volteA++; /*egyetkiir(aktJobb);*/ aktualis = aktJobb;  hanyvan--; megoldas.push_back(aktJobb); voltak.erase(voltak.begin()+ kintIJ); }
            else if (mennyiBal == 0 && mennyiJobb >= 1) { volteA++; /*egyetkiir(aktJobb);*/ aktualis = aktJobb;  hanyvan--; megoldas.push_back(aktJobb); voltak.erase(voltak.begin() + kintIJ);}
            else if(mennyiBal == 1 &&mennyiJobb == 0) {volteA++; /*egyetkiir(aktBal);*/ baloldal = aktBal; hanyvan--; megoldas.insert(megoldas.begin(), aktBal); voltak.erase(voltak.begin() + kintIB);
            }
            else if (mennyiBal < mennyiJobb && mennyiJobb != 0) { volteA++; /*egyetkiir(aktBal);*/ baloldal = aktBal; hanyvan--; megoldas.insert(megoldas.begin(), aktBal); voltak.erase(voltak.begin() + kintIB);
            }
        }
        if (volteA == 0) {
            if (k == 54) { aktualis = baloldal; k = 53; }
            vege++;
            int volteB = 0;
            for (int i = 0; i < hanyvan; i++)
            {
                if (/*elemee(i) &&*/ (alma[voltak[i]][1] == alma[aktualis][0] && alma[voltak[i]][2] == alma[aktualis][1])) {volteB++; /*egyetkiir(voltak[i]);*/ aktualis = voltak[i]; hanyvan--; megoldas.insert(megoldas.begin(), voltak[i]); voltak.erase(voltak.begin() + i); break; }
            }
            if (volteB == 0) { vege++; }
        }

    }

    if (hanyvan != 0) { cout << "NO\n"; }
    else { cout << "YES\n"; kiir();}
}
