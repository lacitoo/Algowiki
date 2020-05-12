#include <iostream>

using namespace std;

int main() {
    int idegen, sz_hossz, u_hossz, igenyek;
    cin >> idegen >> sz_hossz >> u_hossz >> igenyek;
    int elsonapok[igenyek];
    for(int i=0; i<igenyek; i++){
        cin >> elsonapok[i];
    }
    int db = idegen;
    int utolso[idegen];
    for(int i=0; i<idegen; i++){
        utolso[i] = elsonapok[i];
    }
    for(int i=idegen; i<igenyek; i++){
        int j=0;
        while(j<idegen && elsonapok[i]<utolso[j]+u_hossz){
            j++;
        }
        if(j<idegen){
            utolso[j] = elsonapok[i];
            db++;
        }
    }
    cout << db;
}