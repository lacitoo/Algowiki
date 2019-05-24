#include <iostream>
#include <vector>
#include <map>

using namespace std;

// Bemeneti ID szerint rendezzük és kiírjuk a pozíciókat
void print(vector<int>& seats, int n)
{
    vector<int> xs(n);
    for(int i = 0; i < seats.size(); ++i)
    {
        if(seats[i] != -1)
            xs[seats[i]] = i;
    }    

    for(int i : xs)
    {
        cout << i << " ";
    }
    cout << endl;
}

// Visszalépéses keresés
bool solve(vector<int>& seats, vector< vector<int> >& xs, int index, int& n)
{
    // Ha már leültettük az összes embert akkor meg van a megoldás, kiírjuk
    if(index >= xs.size())
    {
        print(seats, n);
        return true;
    }

    // Az adott ember minden lehetséges ülését kipróbáljuk
    for(int i : xs[index])
    {
        // Ha még nem ül ott senki, akkor megnézzük hogy jó lenne-e ez az ültetés
        if(seats[i] == -1)
        {
            seats[i] = index;
            
            if(solve(seats, xs, index + 1, n))
                return true;

            // Ha nem jó az ültetés akkor visszalépünk
            seats[i] = -1;
        }
    }

    return false;
}

int main()
{
    // beolvasás
    int n, m;
    cin >> n >> m;

    vector< vector<int> > xs;

    for(int i = 0; i < n; ++i)
    {
        int tmp;
        vector<int> tmpp;

        do
        {
            cin >> tmp;
            tmpp.push_back(tmp);
        } while (tmp != 0);

        tmpp.pop_back();
        xs.push_back(tmpp);
    }

    // -1-re inicializáljuk az értékeket, ami azt jelzi hogy nem ül ott senki
    vector<int> seats(m + 1, -1);

    // Ez elindítja a rekurzív algoritmust, ami ha talál megoldást azt kiírja, ha pedig nem akkor -1et írunk ki
    if(!solve(seats, xs, 0, n)) cout << "-1" << endl;

    return 0;
}