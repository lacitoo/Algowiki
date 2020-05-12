using namespace std;
#include <iostream>
 
int n, k, m, c, csoportok[11], intervallumok[16001] = { 0 };

void beolvasas() {
    //paraméterek beolvasása
    cin >> n >> k >> m >> c;
    for (int i = 0; i < c; i++) {
        int b;
        cin >> b;
        intervallumok[b]++;
        //intervallumok kezdetének jelölése
    }
}
 
int main()
{
    beolvasas();
    int db = 0;

    for (int i = 0; i <= k; i++) {
        //fő intervallum bejárása
        for(int j = 1; j <=n; j++){
            //csoportok bejárása
            csoportok[j]--;// csoportok csökkentese

            if(intervallumok[i]>0 && csoportok[j]<=0){
                //ha kezdődik intervallum és szabad ez a csoport
                //akkor berakja a csoportba
                csoportok[j]=m;
                intervallumok[i]--;
                db++;
            }
        }
    }
 
    cout << db << endl;
}