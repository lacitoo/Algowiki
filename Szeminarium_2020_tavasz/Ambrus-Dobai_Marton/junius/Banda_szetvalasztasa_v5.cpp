#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> G, c;
vector<int> p, d, L, s, max_s;
vector<bool> ElvagoP;
int n, m, ido = 0, csucs;

void MelyBejar(int i) {
    d[i] = ++ido;
    L[i] = ido;
    s[i] = 1;
    for(int q : G[i]){
        if (d[q] == 0) { // p−>q fa él
            p[q]=i;
            MelyBejar(q);
            s[i]+=s[q];
            if(s[q]>max_s[i]){
              max_s[i]=s[q];
            }
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
    for(int q = 2; q<n ; q++ ) {
        if(max_s[q]< s[1] - s[q])max_s[q] = s[1] - s[q];
        int par = p[q] ;
        if( par == 1 ){
            rfiai++;
            c[1].push_back(q);
        }else{
            ElvagoP[par] = ElvagoP[par] || L[q] >= d[par];
            if(ElvagoP[par]){
              c[par].push_back(q);
            }
        }
    }
    ElvagoP[1] = rfiai > 1;
}

void MaxCsucs(){
    int max_resz, min_max_s;
    bool van = false;
    csucs;
    if(ElvagoP[1]){
        csucs=1;
        max_resz=c[1].size();
        min_max_s=max_s[1];
        van=true;
    }
    for(int i=2; i<n; ++i){
        if(van && ElvagoP[i]){
            if(max_resz<1+c[i].size()){
                csucs=i;
                max_resz=1+c[i].size();
                min_max_s=max_s[i];
            }else if(max_resz==1+c[i].size()){
                if(max_s[i]<min_max_s){
                    csucs=i;
                    max_resz=1+c[i].size();
                    min_max_s=max_s[i];
                }
            }
        }else if(!van && ElvagoP[i]){
            csucs=i;
            max_resz=1+c[i].size();
            min_max_s=max_s[i];
            van=true;
        }
    }
    if(!van){ csucs=1; }
}

int main(){
    ios_base::sync_with_stdio(0);

    cin>>n>>m;
    n=n+1;
    G.resize(n);
    p.resize(n);
    d.resize(n);
    L.resize(n);
    s.resize(n);
    c.resize(n);
    ElvagoP.resize(n);
    max_s.resize(n);
    for(int i=0; i<m; ++i){
        int a,b;
        cin>>a>>b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    Adatok();
    MaxCsucs();
    cout<<csucs<<endl;
}
//67/100