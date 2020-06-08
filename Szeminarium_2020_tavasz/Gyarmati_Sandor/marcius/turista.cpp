#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){

    int N, M, L;
    cin >> N >> M >> L;

    vector< vector<int> > tabla(N+1, vector<int>(N+1, 1001));
    vector< vector<int > > szulo(N+1, vector<int>(N+1, 0));
    
    int f, t, in;
    for(int i = 0; i < M; i++){
        cin >> f >> t >> in;
        if(  in < tabla[f][t] ){
            tabla[f][t] = in;
            tabla[t][f] = in;
            szulo[f][t] = f;
            szulo[t][f] = t;
        }
    }

    
    for(int i = 1; i <= N; i++ ){
        for(int j = 1; j <= N; j++){
            cerr << tabla[i][j] << " ";
        }cerr << endl;
    }
    
    
    
    for(int i = 1; i <= N; i++ ){
        for(int j = 1; j <= N; j++){
            cerr << szulo[i][j] << " ";
        }cerr << endl;
    }


    for(int k = 1; k <= N; k++){
        for(int i = 1; i <= N; i++){
            for(int j = 1; j <= N; j++){
                if( tabla[i][j] > tabla[i][k] + tabla[k][j] ){
                    tabla[i][j] = tabla[i][k] + tabla[k][j];
                    szulo[i][j] = k;
                }
            }
        }
    }

    /*
    for(int i = 1; i <= N; i++ ){
        for(int j = 1; j <= N; j++){
            cerr << tabla[i][j] << " ";
        }cerr << endl;
    }
    */
    
    
    for(int i = 1; i <= N; i++ ){
        for(int j = 1; j <= N; j++){
            cerr << szulo[i][j] << " ";
        }cerr << endl;
    }
    
    

    vector<int> v;

    for(int i = 1; i <= N; i++){
        if( i != L){
            v.push_back(i);
        }
    }
    int mins = 100000;
    vector<int> mego;
    vector<bool> volte(N + 1, false);

    do{

        for(int i = 0; i <= N; i++){
            volte[i] = false;
        }
        volte[L] = true;
        if( !volte[ szulo[L][v[0]] ] ){
            //cerr << "nem jo az elso\n"; 
            continue;
        }
        volte[v[0]] = true;
        int sum = tabla[L][v[0]];
        bool kitor = false;
        for(int i = 0; i < N-2; i++){
            if( !volte[ szulo[v[i]][v[i+1]] ]){
                //cerr << (i+1) << "-t nem tudom hozzavenni\n";
                kitor = true;break;
            }
            volte[v[i+1]] = true;
            sum += tabla[v[i]][v[i+1]];
        }   
        if( kitor ){
            continue;
        } 
        sum += tabla[v[N-2]][L];
        if(sum < mins){
            mins = sum;
            mego = v;
        }
    }while( next_permutation(v.begin(), v.end()) );

    cout << mins << endl;
    for(int i = 0; i < N-1; i++){
        cout << mego[i] << " ";
    }cout << endl;
}