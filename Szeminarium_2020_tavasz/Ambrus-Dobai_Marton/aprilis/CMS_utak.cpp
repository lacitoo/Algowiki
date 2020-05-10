#include <iostream>
#include <vector>

using namespace std;

int utvonalAra(int ind,int veg,vector<vector<int>> varos,vector<vector<int>> fizet,vector<int> voltmar,int ar){
    int min = -1;
    for (int i = 1; i < (int)(varos[ind].size()) && min==-1; i++){
        //cout<<varos[ind][i]<<": ";
        if(varos[ind][i]==veg){
            //cout<<"megvan!!\n";
            return ar + fizet[ind][i];
        }else{
            if(voltmar[varos[ind][i]]==0){
                voltmar[varos[ind][i]]=1;
                int akt=utvonalAra(varos[ind][i],veg,varos,fizet,voltmar,ar+fizet[ind][i]);
                if(akt<min || min==-1){
                    min=akt;
                }
                
                //cout<<" ar "<<akt<<endl;
            }else{
                //cout<<"volt mar "<<endl;
            }
        }
    }
    return min;
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> varos(n+1);
    vector<vector<int>> fizet(n+1);
    vector<int> voltmar(n+1);
    for (int i = 0; i < m; i++){
        int a,b;
        char c;
        cin>>a>>b>>c;
        varos[a].push_back(b);
        fizet[a].push_back(c=='F'?1:0);
        varos[b].push_back(a);
        fizet[b].push_back(c=='F'?1:0);
    }
    int kez,veg;
    cin>>kez>>veg;
    int min=utvonalAra(kez,veg,varos,fizet,voltmar,0);

    cout<<min;
}

/*
7 11
1 2 F
1 5 I
2 5 I
2 3 I
5 3 F
5 6 F
3 6 I
3 4 F
6 4 F
6 7 I
4 7 F
1 4
*/