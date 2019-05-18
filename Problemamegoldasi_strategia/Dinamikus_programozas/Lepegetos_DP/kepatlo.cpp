#include <iostream>

using namespace std;

struct pix
{
    int bal, fent, pont; //Adott pixeltõl balra esõ fehérek száma, felé esõ feketék száma, elérhetõ legkisebb érték
};

pix kep[1000][1000];

int main()
{
    int n;
    cin>>n;
    bool be;

    for(int i = 0; i < n; ++i) // Elsõ sor és oszlop értéke 0
    {
        kep[i][0].pont = 0;
        kep[0][i].pont = 0;
    }


    for (int i = 0; i < n-1; ++i) // Itt adjuk meg a bal és fent értékeket
    {
        for (int j = 0; j < n-1; ++j)
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
    cin>>be; //Utolsó pixel számonkra nem lényeges, de azért beolvassuk


    for(int i = 1; i < n; ++i) //Értékek meghatározása
    {
        for (int j = 1; j < n; ++j)
        {
            kep[i][j].pont = min(kep[i-1][j].pont + kep[i][j].bal , kep[i][j-1].pont + kep[i][j].fent); // Õ a fontos!
        }
    }

    /* //Ez megjelenítheti a táblázat fent, bal és pont értékeit
    cout<<"\n\n\n";
    cout<<"Bal:\n";
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cout<<kep[i][j].bal<<' ';
        }
        cout<<'\n';
    }

    cout<<"\n\n\n";
    cout<<"Fent:\n";
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cout<<kep[i][j].fent<<' ';
        }
        cout<<'\n';
    }

    cout<<"\n\n\n";
    cout<<"Pont:\n";
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cout<<kep[i][j].pont<<' ';
        }
        cout<<'\n';
    }
    cout<<"\n\n\n";
    cout<<"Eredmény:\n";
    */
    cout << kep[n-1][n-1].pont << endl;
    return 0;
}
