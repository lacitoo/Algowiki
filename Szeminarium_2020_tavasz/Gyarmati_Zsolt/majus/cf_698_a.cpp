#include <iostream>

#define MAXN 100

using namespace std;

int N;
int ka[MAXN+2];
int kb[MAXN+2];
int m;

int
main()
{
    cin >> N;
    for(int i = 2; i <= N+1; i++){
        int tmp; cin >> tmp;
        int bm = max(ka[i-2], kb[i-2]);
        if((ka[i] =    ((tmp)&1)  + max(kb[i-1], bm)) > m) m = ka[i];
        if((kb[i] = (!!((tmp)&2)) + max(ka[i-1], bm)) > m) m = kb[i];
    }
    cout << N-m << endl;

    return 0;
}