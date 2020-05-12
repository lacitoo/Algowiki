#include <iostream>
using namespace std;

//Adatok
int n, m, c[500], k;
bool dp[100001];

int main(){
    //Beolvasás
    cin>>n>>m;
    for (int i = 0; i < n; i++){
        cin>>c[i];
    }
    
    //Feladat megoldása
    dp[0] = true; //0-ból indulunk ki
    for (int i = 0; i < m+1; i++){
        if(dp[i] == true){ //Optimalizálás: csak az előálíthatókon dolgozik
            for (int j = 0; j < n; j++){ //Végig megyünk a megadott értékeken
                int a = i + c[j];
                if(a<m+1 && dp[a] == false){ //ha az aktuális szám előálítható akkor 
                    ++k;                     //az új értéket hozzáadva az is előálítható lesz
                    dp[a] = true;
                }
            }
        }
    }
    
    //Kiírás
    cout<<m-k<<"\n";
    for (int i = 0; i < m+1; i++){
        if(dp[i] == false){
            cout<<i<<" ";
        }
    }
    cout<<"\n";
    return 0;
}