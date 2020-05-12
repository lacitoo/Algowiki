#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> v;

bool search(int a, int b, bool &l){
    if(!l && v[a].size() != 0){
        for(int i=0; i<v[a].size(); ++i){
            if(i==b)
                l = true;
            else
                search(i, b, l);
        }
    }
    return l;
}

void cnt(int a, int &c){
    if(v[a].size() != 0){
        for(int i:v[a]){
            cnt(i, c);
        }
    }
    ++c;
}

int main(){
    int n, x, y;
    cin >> n >> x >> y;
    int m;
    for(int i=2; i<=n; i++){
        cin >> m;
        v[m].push_back(i);
    }
    bool l = false;
    cout << search(x, y, l) << endl;
    int c = 0;
    int d = 0;
    cnt(x, c);
    cnt(y, d);
}