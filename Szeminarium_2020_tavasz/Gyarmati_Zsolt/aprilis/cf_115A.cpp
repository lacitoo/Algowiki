#include <iostream>
#include <vector>
#include <queue>

#define MAXN    2000

using namespace std;

int N;
vector<int> ponts[MAXN+1], tocheck;
int jarte[MAXN+1];
int absmax = 1;

int
main()
{
    ios_base::sync_with_stdio(false);
    cin >> N;

    for(int i = 1; i <= N; i++){
        int t;
        cin >> t;
        if(t == -1)
            tocheck.push_back(i);
        else
            ponts[t].push_back(i);
    }

    for(const auto k : tocheck){
        queue<int> sor;
        sor.push(k);
        jarte[k] = 1;
        do{
            int most = sor.front();
            sor.pop();
            int mj = jarte[most]+1;
            for(const auto c : ponts[most]){
                if(!jarte[c]){
                    jarte[c] = mj;
                    if(mj > absmax)
                        absmax = mj;
                    sor.push(c);
                }
            }
        }while(!sor.empty());
    }

    cout << absmax << endl;

    return 0;
}