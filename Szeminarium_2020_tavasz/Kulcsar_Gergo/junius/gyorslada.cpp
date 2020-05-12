#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n, m;
    cin >> n;
    cin >> m;
    int L;
    cin >> L;
    int sum = 0;
    vector<int> vec;
    int last = L;
    int height = last;
    vec.push_back(L);
    bool increasing = true;
    int breakingpoint = -1;
    for(int i=1; i<n; ++i){
        cin >> L;
        bool inc = last < L;
        int h = height + L;
        if(L != last && (increasing || !inc) && h<=m){
            if(inc){
                vec.push_back(L);
                height = h;
                ++sum;
                increasing = inc;
            }else{
                if(increasing)
                    breakingpoint = vec.size()-1;
                int lowerindex = 0;
                int upperindex = breakingpoint;
                while(lowerindex <= upperindex){
                    int m = (lowerindex + upperindex)/2;
                    if(vec[m]<L)
                        lowerindex = m+1;
                    else if(vec[m]>L)
                        upperindex = m-1;
                    else{
                        vec.resize(0);
                        vec.push_back(L);
                        height = L;
                        increasing = true;
                        breakingpoint = -1;
                        break;
                    }
                }
                if(breakingpoint != -1){
                    vec.push_back(L);
                    height = h;
                    ++sum;
                    increasing = inc;
                }
            }
        }else{
            vec.resize(0);
            vec.push_back(L);
            height = L;
            increasing = true;
            breakingpoint = -1;
        }
        last = L;
    }
    cout << sum;
}