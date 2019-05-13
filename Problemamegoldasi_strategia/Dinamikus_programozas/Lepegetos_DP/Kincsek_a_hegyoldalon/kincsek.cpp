#include <iostream>

using namespace std;

//A gyûjtõpontok egyszerû tárolásához szükséges struktúra
struct Gyujto
{
    int o;  //oszlop index
    int s;  //sor index
};

int main()
{
    //Deklaráció és beolvasás
    int H[1000][1000]={0}; //A hegyoldal területének mátrixa
    int N;
    int M;
    cin>>N>>M;
    int K;
    cin>>K;
    int G;
    cin>>G;
    Gyujto GY[1000];

    //Mátrix feltöltése a kincsekkel
    for (int i=0; i<K; i++)
    {
        int s; //sor index
        int o; //oszlop index
        cin>>s>>o;
        H[s-1][o-1]=1; //-1 a 0-tól indexelés miatt
    }

    //Gyûjtõpontok beolvasása, és elhelyezés a mátrixban
    for (int i=0; i<G; i++)
    {
        int s;  //sor index
        int o;  //oszlop index
        cin>>s>>o;
        H[s-1][o-1]=-1; //gyûjtõpont elhelyezése a mátrixban -1 értékkel
        GY[i].o=o-1;
        GY[i].s=s-1;
    }

    //Dinamikus Programozás, mátrix/táblázat feltöltése a "Részletes megoldás" rész alapján
    for(int i=0; i<N; i++)
    {
        for (int j=0; j<M; j++)
        {
            if (H[i][j]!=-1 && (H[i-1][j]!=-1 || H[i][j-1]!=-1)) //Ha nem gyûjtõpont
            {
                if (i-1>=0 && j-1>=0)  //Általános eset
                {
                    if (H[i-1][j]>H[i][j-1])
                    {
                        H[i][j]+=H[i-1][j];
                    }
                    else
                    {
                        H[i][j]+=H[i][j-1];
                    }

                }
                else if (i-1>=0 && j==0) //Elsõ oszlop esete
                {
                    H[i][j]+=H[i-1][j];
                }
                else if (i==0 && j-1>=0) //Elsõ sor esete
                {
                    H[i][j]+=H[i][j-1];
                }

            }
        }
    }

    //Maxmimum kiválasztás
    int maxi=0;  //maximális kincsek
    int maxio=0; //gyûjtõhely oszlop indexe
    int maxis=0; //gyûjtõhely sor indexe
    for (int i=0; i<G; i++)
    {
        int o=GY[i].o;
        int s=GY[i].s;
        if (H[s-1][o]>maxi && s-1>=0)
        {
            maxi=H[s-1][o];
            maxio=o+1;
            maxis=s+1;
        }
        if (H[s][o-1]>maxi && o-1>=0)
        {
            maxi=H[s][o-1];
            maxio=o+1;
            maxis=s+1;
        }
    }
    if (maxi==0)  //Ha nincs oda vihetõ kincs, akkor nincs hely sem
    {
        cout<<maxi<<endl;
    }
    else
    {
        cout<<maxi<<endl;
        cout<<maxis<<" "<<maxio<<endl;
    }

/*
    //Táblázat kíírása, szemléltetés
    for (int i=0; i<N; i++)
    {
        for (int j=0; j<M; j++)
        {
            cout<<H[i][j]<<" ";
        }
        cout<<endl;
    }
*/
    return 0;
}
