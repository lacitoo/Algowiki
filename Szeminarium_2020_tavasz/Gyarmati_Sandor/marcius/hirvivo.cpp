#include <iostream>
#include <vector>
#include <algorithm>

#define ALL(x) x.begin(), x.end()
using namespace std;

struct el{
    int aInd, bInd, hossz;
};

vector<int> sets;
vector<int> counters;
int darab;

int root(int a){
    if (sets[a] == a){
        return a;
    }
    return sets[a] = root(sets[a]);
}

void unions(int a, int b){
    a = root(a);
    b = root(b);
    if (a == b){
        return;
    }
    darab--;
    //cerr << a << " and " << b << " is now unioned\n";
    if(counters[a] >= counters[b] ){
        counters[a] += counters[b];
        sets[b] = a;
    }else{
        counters[b] += counters[a];
        sets[a] = b;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N, M, H, K;
    cin >> N >> M >> H >> K;
    vector< pair<int, int> > p(H);
    vector< el > elek;
    for(int i = 0; i < H; i++){
        cin >> p[i].first >> p[i].second;
        for(int j = 0; j < i; j++ ){
            int hossz = ( abs(p[i].first - p[j].first) + abs(p[i].second - p[j].second)  );
            elek.push_back( {i, j, hossz} );
            //elek.push_back( {i, j, ( abs(p[i].first - p[j].first) + abs(p[i].second - p[j].second)  )} );
        }
    }
    sort(elek.begin(), elek.end(), [](const el &a, const el &b){return a.hossz < b.hossz;});
    
    /*
    cerr << "Az elek novekvo sorrendben: \n";
    for(int i = 0; i < elek.size(); i++){
        cerr << elek[i].aInd << " " << elek[i].bInd << " : " << elek[i].hossz << endl;
    }
    */

    counters.resize(H, 1);
    sets.resize(H);
    darab = H;
    int L;
    for(int i = 0; i < H; i++){
        sets[i] = i;
    }
    for(int i = 0; i < elek.size() && darab > K; i++){
        L = elek[i].hossz;
        unions(elek[i].aInd, elek[i].bInd);
    }
    cout << L << endl;
}