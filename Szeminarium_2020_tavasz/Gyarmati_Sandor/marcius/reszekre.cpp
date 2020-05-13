#include <iostream>
#include <vector>

#define ALL(x) x.begin(), x.end()
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin >> N;

    vector<int> a(N);
    vector<int> t(N);
    vector<int>::iterator low;
    int e = N-1;

    for(int i = 0; i < N; i++){
        cin >> a[i]; 
        /*
        for(int j = e+1; j < N; j++){
            cerr << t[j] << " ";
        }cerr << endl;
        */
        if(i == 0){
            t[e] = a[i];
            e--;
        }else{
            low = lower_bound(t.begin()+e+1, t.end(), a[i]);
            //cerr << (*low) << endl;
            //cerr << "========================\n";

            if(low == t.begin() + e + 1){
                //cerr << "eleje\n";
                t[e] = a[i];
                e--;
            }else{
                low--;
                *low = a[i];
            }
        }
    }

    cout << (N-e-1) << endl;
}
