#include <iostream>

using namespace std;

struct pix
{
    int bal, fent, pont; //Adott pixeltol balra eso feherek szama, fele eso feketek szama, elerheto legkisebb ertek
};

pix kep[1000][1000];

int main()
{
    int n;
    cin>>n;
    bool be;

    for(int i = 0; i < n; ++i) // Elso sor es oszlop erteke 0
    {
        kep[i][0].pont = 0;
        kep[0][i].pont = 0;
    }


    for (int i = 0; i < n-1; ++i) // Itt adjuk meg a bal es fent ertekeket
    {
        for (int j = 0; j < n-1; ++j) //pixelek szineinek beolvasasaval parhuzamos
        {
            cin>>be;
            kep[i+1][j].fent = kep[i][j].fent + !be;
            kep[i][j+1].bal = kep[i][j].bal + be;
        }
        cin>>be;
        kep[i+1][n-1].fent = kep[i][n-1].fent + !be;
    }

    for (int i = 0; i < n-1; ++i)
    {
        cin>>be;
        kep[n-1][i+1].bal = kep[n-1][i].bal + be;
    }
    cin>>be; //Utolso pixel szamonkra nem lenyeges, de azert beolvassuk


    for(int i = 1; i < n; ++i) //ertekek meghatarozasa
    {
        for (int j = 1; j < n; ++j)
        {
            kep[i][j].pont = min(kep[i-1][j].pont + kep[i][j].bal , kep[i][j-1].pont + kep[i][j].fent); // o a fontos!
        }
    }


    cout << kep[n-1][n-1].pont << endl; // eredmenykiiras
    return 0;
}
