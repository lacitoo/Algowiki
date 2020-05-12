using namespace std;
#include <iostream>
#include <vector>

char darabok[200001][3];
vector<int> voltak;
vector<int> megoldasBal;
vector<int> megoldasJobb;
int n;
int hanyvan;

void beolvasas()
{
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> darabok[i][0] >> darabok[i][1] >> darabok[i][2];
        voltak.push_back(i);
    }
}

int illeszkedes(int a, int b)
{
    //if (darabok[a][2] == darabok[b][0]) { return 1; }
    if (darabok[a][1] == darabok[b][0] && darabok[a][2] == darabok[b][1]) { return 2; }
    //else if (darabok[b][2] == darabok[a][0]) { return 3; }
    else if (darabok[b][1] == darabok[a][0] && darabok[b][2] == darabok[a][1]) { return 4; }
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
    if (megoldasBal.size() > 0 && megoldasJobb.size() > 0)
    {
        cout << darabok[megoldasBal[megoldasBal.size() - 1]][0] << darabok[megoldasBal[megoldasBal.size() - 1]][1] << darabok[megoldasBal[megoldasBal.size() - 1]][2];
        for (int i = megoldasBal.size() - 2; i >= 0; i--)
        {
            cout << darabok[megoldasBal[i]][2];
        }
        for (int i = 0; i < megoldasJobb.size(); i++)
        {
            cout << darabok[megoldasJobb[i]][2];
        }
    }
    else if (megoldasBal.size() > 0)
    {
        cout << darabok[megoldasBal[megoldasBal.size() - 1]][0] << darabok[megoldasBal[megoldasBal.size() - 1]][1] << darabok[megoldasBal[megoldasBal.size() - 1]][2];
        for (int i = megoldasBal.size() - 2; i >= 0; i--)
        {
            cout << darabok[megoldasBal[i]][2];
        }
    }
    else
    {
        cout << darabok[megoldasJobb[0]][0] << darabok[megoldasJobb[0]][1] << darabok[megoldasJobb[0]][2];
        for (int i = 1; i < megoldasJobb.size(); i++)
        {
            cout << darabok[megoldasJobb[i]][2];
        }
    }
   
}

void egyetkiir(int a)
{
    cout << darabok[a][0] << darabok[a][1] << darabok[a][2] << "\n";
}

int main()
{
    beolvasas();
    hanyvan = n - 1;
    int vege = 0;
    int aktualis = 0;
    //egyetkiir(aktualis);
    int baloldal = aktualis;
    megoldasJobb.push_back(0);
    voltak.erase(voltak.begin());
    int k = 54;
    int ik = 2;
    while (vege < 2)
    {
        int volteA = 0;
        if (k == 54) {
            int mennyiJobb = 0;
            int mennyiBal = 0;
            for (int i = 0; i < hanyvan; i++)
            {
               ik++;
               if (illeszkedes(baloldal, voltak[i]) == 4) 
               {
                   mennyiBal++; 
                   volteA++; 
                   //egyetkiir(aktBal);
                   baloldal = voltak[i]; 
                   hanyvan--; 
                   megoldasBal.push_back(voltak[i]); 
                   voltak.erase(voltak.begin() + i);
                   i--;
               }
               else if (illeszkedes(aktualis, voltak[i]) == 2) 
               { 
                   mennyiJobb++;
                   volteA++; 
                   /*egyetkiir(aktJobb);*/ 
                   aktualis = voltak[i];
                   hanyvan--;
                   megoldasJobb.push_back(voltak[i]);
                   voltak.erase(voltak.begin() + i);
                   i--;
               }
               //if (mennyiJobb > 2) { break; }
            }
        }
        if (volteA == 0) {
            
            if (k == 54) { aktualis = baloldal; k = 53; }
            vege++;
            int volteB = 0;
            for (int i = 0; i < hanyvan; i++)
            {
                ik++;
                if (darabok[voltak[i]][1] == darabok[aktualis][0] && darabok[voltak[i]][2] == darabok[aktualis][1]) 
                {
                    volteB++; 
                    /*egyetkiir(voltak[i]);*/ 
                    aktualis = voltak[i]; 
                    hanyvan--; 
                    megoldasBal.push_back(voltak[i]); 
                    voltak.erase(voltak.begin() + i);
                    i--;
                }
            }
            if (volteB == 0) { vege++; }
        }

    }

    if (hanyvan != 0) { cout << "NO\n"; /*cout << "\n" << ik;*/
    }
    else { cout << "YES\n"; kiir(); /*cout << "\n" << ik;*/ }
}

