#include <iostream>

using namespace std;

int ertek[1000], suly[1000], maxertek[1001][1001]; //Tegyuk fel, hogy  N,W<=1000

int main()
{
    int T;
    cin>>T; // ennyiszer hajtjuk vegre a muveletet
    while (T--)
    {
        //adatok beolvasasa
		int N, W;
        cin>>N>>W;
        for (int i = 0; i < N; ++i)
        {
            cin>>ertek[i];
        }
        for (int i = 0; i < N; ++i)
        {
            cin>>suly[i];
        }
		
		//elso sor/oszlop feltoltese
        for (int i = 0; i <= N; ++i)
        {
            maxertek[0][i] = 0;
        }
        for (int i = 1; i <= W; ++i)
        {
            maxertek[i][0] = 0;
        }


        for (int i = 1; i <= W; ++i) //maradek tablazat feltoltese
        {
            for (int j = 1; j <= N; ++j)
            {
                if (suly[j-1]>i)
                {
                    maxertek[i][j] = maxertek[i][j-1];
                }
                else
                {
                    maxertek[i][j] = max(maxertek[i][j-1], (ertek[j-1] + maxertek[i-suly[j-1]][j-1]));
                }
            }
        }

        cout<<maxertek[W][N]<<endl; // eredmenykiiras
    }
    return 0;
}
