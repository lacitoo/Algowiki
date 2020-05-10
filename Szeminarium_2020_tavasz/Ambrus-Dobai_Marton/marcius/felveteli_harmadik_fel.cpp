#include <iostream>
#include <string>
using namespace std;

char x[200000][4];
bool y[200000];


int main(){
    int n;
    cin>>n;
    string password = "";
    for (int i = 0; i < n; i++){
        cin>>x[i];
    }
    password = x[0];
    y[0]=1;
    int db=1;
    while(db>-1 && db<n){
        //cout<<db<<" "<<password<<endl;
        for (int i = 1; i < n; i++)
        {
            if(y[i]==0){
                if(password[1]==x[i][2] && password[0]==x[i][1]){
                    y[i]=1;
                    password=(x[i][0]+password);
                    ++db;
                }
                else if(password[password.length()-1]==x[i][1] && password[password.length()-2]==x[i][0]){
                    y[i]=1;
                    password=(password+x[i][2]);
                    ++db;
                }
            }
        }
        if(db==1){
            db=-1;
        }
    }
    if(db==-1){
        cout<<"NO\n";
    } else {
        cout<<"YES\n"<<password<<endl;
    }
}