#include <iostream>
using namespace std;

//Adatok
int n, m, c[500], k;
bool dp[100001], d[100001]; //Optimalizálás: eltároljuk a már kiszámolt adatokat és azt, hogy már számoltuk

bool rec(int i){
    if(i<0){ return false; }
    if(d[i]){ return dp[i]; } //Optimalizálás: ha már tudjuk, hogy előálítható akkor csak visszaadjuk ezt
    for (int j = 0; j < n && !dp[i]; j++){ //Optimalízálás: csak addig megyünk amíg elöször nem lesz igaz
        dp[i] = rec(i - c[j]); //Rekurzívan kiszámoljuk, hogy bármelyik szám, amiből ez előálítható, előálítható-e
    }
    d[i] = true;
    return dp[i];
}

int main(){
    //Beolvasás
    cin>>n>>m;
    for (int i = 0; i < n; i++){
        cin>>c[i];
    }
    
    //Feladat megoldása
    dp[0] = true;
    for (int i = 1; i < m+1; i++){
        if(rec(i)){ ++k;  } //Mindegyik számra meghívjuk a rekurzív függvényt ami megadja,
    }                       //hogy előálítható-e ez a szám.
    
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