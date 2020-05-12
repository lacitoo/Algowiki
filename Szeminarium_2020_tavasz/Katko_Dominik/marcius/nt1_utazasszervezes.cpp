#include <iostream>

using namespace std;
int vezetokszama;
int vezetok[10];
int szezonhossz;
int utazashossz;
int igenyszam;
int igenyek[10000];
int elvallalt=0;

int main()
{
    cin>>vezetokszama>>szezonhossz>>utazashossz>>igenyszam;
    for (int i=0;i<vezetokszama;i++){
        vezetok[i]=0; //mikortol szabad
    }
    for (int i=0;i<igenyszam;i++){
        cin>>igenyek[i];
    }
    for (int i=0;i<igenyszam;i++){
        bool vallalt = false;
        for (int j=0;j<vezetokszama && !vallalt;j++){
            if(vezetok[j]<=igenyek[i]){
                vezetok[j]=igenyek[i]+utazashossz-1;
                elvallalt++;
                cerr<<j<<" "<<igenyek[i]<<endl;
                vallalt=true;
            }
        }
    }
    cout<<elvallalt<<endl;
    return 0;
}
