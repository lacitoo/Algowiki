#include <iostream>
#include <queue>
using namespace std;

//Adatok
int n, m, c[500], k;
queue<int> q;
bool dp[100001]; //Optimalizálás: eltároljuk a már kiszámolt adatokat

int main(){
    //Beolvasás
    cin>>n>>m;
    for (int i = 0; i < n; i++){
        cin>>c[i];
    }
    
    //Feladat megoldása
    for (q.push(0); !q.empty(); q.pop()){ //Ameddig nem üres a sor addig kiveszünk belőle
        int a = q.front();
        if(a<m+1 && !dp[a]){ //Optimalizálás: Ha már tudjuk, hogy előálítható akkor már számoltunk vele és most nem kell
            for (int j = 0; j < n; j++){
                if(a+c[j]<m+1){ //Hozzáadjuk a sorhoz azokat amiket ebből a számból elő lehet álítani
                    q.push(a+c[j]);
                }
            }
            dp[a]=true;
            ++k;
        }
    }
    
    //Kiírás
    cout<<m-k+1<<"\n";
    for (int i = 0; i < m+1; i++){
        if(dp[i] == false){
            cout<<i<<" ";
        }
    }
    cout<<"\n";
    return 0;
}