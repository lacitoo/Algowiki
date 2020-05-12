#include <iostream>
#include <vector>
#include <iterator>

using namespace std;

int main(){
    int n, m;
    cin >> n;
    cin >> m;
    int L;
    cin >> L;
    int sum = 0;
    vector<int> vec(10000);
    int last = L;
    int height = last;
    vec.push_back(L);
    bool increasing = true;
    for(int i=1; i<n; ++i){
        cin >> L;
        bool inc = last < L;
        int h = height + L;
        if(L != last && (increasing || !inc) && h<=m){
            int j = 0;
            for(; j<vec.size() && vec[j]!=L; ++j);
            if(j==vec.size()){
                vec.push_back(L);
                height = h;
                ++sum;
                increasing = inc;
            }else{
                vec.resize(0);
                vec.push_back(L);
                height = L;
                increasing = true;
            }
        }else{
            vec.resize(0);
            vec.push_back(L);
            height = L;
            increasing = true;
        }
        last = L;
    }
    cout << sum;
}