#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

int n,m, bevetel, hely, osszdb;
vector<int> tomeg, ar, db, dp;


int max(int a, int b){
    return (a>b?a:b);
}

int beolvas(){
    cin>>n>>m;
    bevetel = 0;
    hely = m;
    osszdb = 0;
    tomeg.push_back(0);
    ar.push_back(0);
    db.push_back(0);
    for (int i = 0; i < n; i++)
    {
        int suly,ertek,osszes,min;
        cin>>suly>>ertek>>osszes>>min;
        bevetel+=ertek*min;
        hely-=suly*min;
        osszdb+=osszes-min;
        if(hely<0){ return -1; }
        tomeg.push_back(suly);
        ar.push_back(ertek);
        db.push_back(osszes-min);
    }
    dp.resize(hely+1,0);
    return 1;
}

int megold(){
    ofstream f;
    f.open("output.txt");
    f<<hely<<" "<<osszdb<<" "<<bevetel<<"\n";
    for(int i=0;i<n;++i){
        while(db[i]>0){
            /*for(int j=hely-1;j>0;--j){
                if(j-tomeg[i]>=0) { dp[j]=max(dp[j],(dp[j-tomeg[i]]+ar[i])); }
                //else { dp[j]=max(dp[j],ar[i]); }
                f<<dp[j]<<"\t";
            }*/
            for(int j=hely;j>=tomeg[i];--j){
                dp[j]=max(dp[j],(dp[j-tomeg[i]]+ar[i]));
                f<<dp[j]<<"\t";
            }
            f<<"\n";
            --db[i];
        }
    }
    f.close();
    return bevetel+dp[hely];
}

int main(){
    ios_base::sync_with_stdio(0);
    if(beolvas()==-1){ cout<<-1<<endl; }
    else{
        cout<<megold()<<endl;
    }
}

/*
5 100
10 10 3 3
20 5 10 0
5 10 10 1
30 70 5 1
40 100 10 0

5 50
1 10 3 3
5 5 5 4
7 5 2 1
2 3 5 0
10 1 1 1
*/