#include <iostream>
#include <vector>

using namespace std;

int main(){
    vector<int> plates;
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        int seged;
        cin >> seged;
        for(int j=0; j<seged; j++){
            plates.push_back(i+1);
        }
    }
    cin >> n;
    for(int i=0; i<n; i++){
        int q;
        cin >> q;
        cout << plates[q-1] << endl;
    }
}