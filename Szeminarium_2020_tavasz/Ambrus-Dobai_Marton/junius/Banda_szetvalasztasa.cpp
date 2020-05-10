#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> G, c;
vector<int> p, d, L, s;
vector<bool> ElvagoP;
int n, m, ido = 0, csucs;

void MelyBejar(int i) {
    d[i] = ++ido;
    L[i] = ido;
    s[i] = 1;
    for(int q : G[i]){
        if (d[q] == 0) { // p−>q fa él
            p[q]=i;
            c[i].push_back(q);
            MelyBejar(q);
            s[i]+=s[q];
            if (L[q] < L[i]){
                L[i] = L[q];
            } 
        } else if (q != p[i] && d[q] < L[i] ) { // p−>q visszaél
            L[i] = d[q];
        }
    }
}

void Adatok(){
    MelyBejar(1) ;
    int rfiai = 0;
    for(int q = 2; q<=n ; q++ ) {
        int par = p[q] ;
        if( par == 1 ){
            rfiai++;
        }else{
            ElvagoP[par] = ElvagoP[par] || L[q] >= d[par];
        }
    }
    ElvagoP[1] = rfiai > 1;
}

int max_s(int p){
    int max=s[1] - s[p];
    for (int i = 0; i < c[p].size(); i++){
        if(s[c[p][i]]>max) max=s[c[p][i]];
    }
    return max;
}

void print(int i){
    cerr<<i<<": parent:"<<p[i]<<" num:"<<d[i]<<" L[i]:"<<L[i];
    cerr<<" size:"<<s[i]<<" cut:"<<ElvagoP[i]<<" children:";
    for (int j = 0; j < c[i].size(); j++){
        cerr<<c[i][j]<<" ";
    }
    cerr<<"\n";
}

void MaxCsucs(){
    int max_resz=0, min_max_s=0;
    bool van = false;
    csucs = -1;
    for(int i=1; i<n; ++i){
        print(i);
        if(van && ElvagoP[i]){
            int mms = max_s(i);
            if(max_resz<1+c[i].size()){
                csucs=i;
                max_resz=1+c[i].size();
                min_max_s=mms;
            }else if(max_resz==1+c[i].size()){
                if(mms<min_max_s){
                    csucs=i;
                    max_resz=1+c[i].size();
                    min_max_s=mms;
                }
            }
        }else if(!van && ElvagoP[i]){
            csucs=i;
            max_resz=1+c[i].size();
            min_max_s=max_s(i);
            van=true;
        }
    }
}

int main(){
    cin>>n>>m;
    n=n+1;
    G.resize(n);
    p.resize(n);
    d.resize(n);
    L.resize(n);
    s.resize(n);
    c.resize(n);
    ElvagoP.resize(n);
    for(int i=0; i<m; ++i){
        int a,b;
        cin>>a>>b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    cerr<<"read\n";
    Adatok();
    cerr<<"data collected\n";
    MaxCsucs();
    cout<<csucs;
}
/*
10 11
1 3
2 3
2 4
3 4
3 5
5 7
6 7
7 8
7 9
8 10
9 10
*/