#include <iostream>
#include <vector>
#include <queue>

using namespace std;
vector <vector <int> > G;
int N, X, Y;
int dbX, dbY;

bool f(int akt, int keres, int &counter){
    bool van = false;
    for (int beosztott : G[akt]){
        counter++;
        van = f(beosztott, keres, counter);
        if (beosztott==keres){
            van=true;
        }
    }
    return van;
}

int main()
{
    cin>>N>>X>>Y;
    G.resize(N+1);
    int akt;
    for (int i=2;i<=N;i++){
        cin>>akt;
        G[akt].push_back(i);
    }
    cerr<<endl;

    //1.
    dbX=0;
    dbY=0;
    if (f(X,Y,dbX)){
        cout<<1<<endl;
    }
    else if(f(Y,X,dbY)){
        cout<<2<<endl;
    }
    else{
        cout<<3<<endl;
    }

    cout<<dbX<<" "<<dbY<<endl;

    //3.
    return 0;
}
