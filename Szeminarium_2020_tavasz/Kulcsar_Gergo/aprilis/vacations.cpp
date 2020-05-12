#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int n;
    cin >> n;
    int rest=0, gym=0, contest=0;
    for(int i=0; i<n; ++i){
        int k;
        cin >> k;
        int r = rest;
        int g = 0;
        int c = 0;
        r = max(max(rest, gym), contest);
        if(k==1 || k==3)
            c = max(rest, gym) + 1;
        if(k==2 || k==3)
            gym = max(rest, contest) + 1;
        rest = r;
        contest = c;
    }
    cout << n-max(max(rest, gym), contest);
}