#include <iostream>

using namespace std;
int penz;
int napszam;
int nap[100000];
int main()
{
    cin>>napszam>>penz;
    for(int i=0;i<napszam;i++){
        cin>>nap[i];
    }
    int minimum=100000;
    int akt = 0;
    for (int i=0;i<napszam;i++){
        akt=0;
        int j;
        for(j=i;j<napszam && akt<penz;j++){
            akt+=nap[j];
        }
        if(akt>=penz){
            if (j-i<minimum){
                minimum=j-i;
            }
        }
    }
    cout<<minimum;
    return 0;
}
