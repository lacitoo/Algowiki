#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

// Maximum kiválasztás
int maximum(vector<int>& xs)
{
    int max = xs[0];
    for(int i = 1; i < xs.size(); ++i)
    {
        if(xs[i] > max) max = xs[i];
    }

    return max;
}

// Vektor kiírás
void print(vector<int>& xs)
{
    for(int i : xs)
        cout << i << " ";
}

// Helyes megoldás-e. Akkor helyes, ha 1-től a vektor maximum eleméig az összes szám egyszer szerepel
bool correctSolution(vector<int>& xs)
{
    if(xs.size() == 0) return false;

    // Eltároljuk hogy minden szám hányszor szerepel
    map<int,int> m;
    for(int i : xs)
    {
        m[i]++;
    }

    // Megnézzük hogy minden szám szerepel-e egyszer és csak egyszer szeepel
    bool allOne = true;
    for(int i = 1; i <= maximum(xs) && allOne; ++i)
    {
        allOne = m[i] == 1;
    }

    return allOne;
}

// Megadja, hogy a mostani állapotában ez rossz megoldás lenne-e.
// Abban különbözik a correctSolution-től, hogy nem kötező 1-től n-ig az összes számnak szerepelnie
// csak az a lényeg hogy egy szám ne szerepeljen kétszer és (a feladat miatt) 1 és 50 között legyen
bool notWrong(vector<int>& xs)
{
    map<int,int> m;
    for(int i : xs)
    {
        if(i < 1 || i > 50) return false;
        m[i]++;
    }

    bool allOne = true;
    for(auto& kv : m)
    {
        allOne = kv.second == 1;
    }

    return true;
}

bool solve(vector<int> xs, string s)
{
    // Ha végigértünk a bemeneten és az jó megoldás akkor kiírjuk, ha nem akkor nem
    if(s == "")
    {
        if(correctSolution(xs))
        {
            print(xs);
            return true;
        }
        return false;
    }

    // Megnézzük, hogy ha 1 jegyű számot olvasnánk be akkor az jó megoldásra vezetne-e
    xs.push_back(stoi(s.substr(0, 1)));
    if(notWrong(xs))
    {
        if(solve(xs, s.substr(1, s.length() - 1)))
            return true;
    }
    // Ha nem, akkor viszsalépünk
    xs.pop_back();

    // Ha van még két karakter a feldolgozandó bemenetben akkor megpróbáljuk
    // azt a két jegyű számot beolvasni és megoldást keresni
    if(s.length() >= 2)
    {
        xs.push_back(stoi(s.substr(0, 2)));
        if(notWrong(xs))
        {
            if(solve(xs, s.substr(2, s.length() - 2)))
                return true;
        }
        xs.pop_back();
    }

    // Ha nem sikerült se 1 se 2 jegyű számmal megoldást találni akkor visszalépünk
    return false;
}

int main()
{
    string input;
    cin >> input;
    // input = "4111109876532";

    vector<int> xs;
    solve(xs, input);

    return 0;
}