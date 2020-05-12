#include <iostream>

#define MAXN    100
#define MAXK    1000

using namespace std;

int N, K;
int realcap;
int tomegek[MAXN+1];
int ar[MAXN+1];
int realmennyi[MAXN+1];
int bev;

int buffer1[MAXK+1], buffer2[MAXK+1];

int
main()
{
    ios_base::sync_with_stdio(0);

    /* be */
    cin >> N >> K;
    realcap = K;
    for(int i = 1; i <= N; i++) {
        int c, d;
        cin >> tomegek[i] >> ar[i] >> c >> d;
        realcap -= tomegek[i]*d;
        bev += ar[i]*d;
        realmennyi[i] = c-d;
    }

    if(realcap < 0) {
        cout << "-1" << endl;
        return 0;
    }

    /* do */
    int *bufferE1 = buffer1, *bufferE2 = buffer2;
    for(int i = 1; i <= N; i++) {
        int et = tomegek[i];
        for(int l = 1; l <= realmennyi[i]; l++){
            int j = 1;

            for(; j < et; j++)
                bufferE2[j] = bufferE1[j];

            for(; j <= realcap; j++)
                bufferE2[j] = max(bufferE1[j], bufferE1[j-et] + ar[i]);

            swap(bufferE1, bufferE2);
        }
    }

    /* ki */
    cout << bufferE1[realcap]+bev << endl;

    return 0;
}