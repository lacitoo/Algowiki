#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define MAXN 200000
#define MAXM 1000000

using namespace std;

int N, M;

vector<int> elek[MAXN+1];
bool bejart[MAXN+1];
char csapat[MAXN+1];

int
main()
{
    ios_base::sync_with_stdio(false);

    cin >> N >> M;

    for(int i = 0; i < M; i++){
        int a, b;
        cin >> a >> b;

        elek[a].push_back(b);
        elek[b].push_back(a);
    }

    //bejar

    

    for(int i = 1; i <= N; i++){
        if(bejart[i]) continue;

        queue<int> varolista;
        varolista.push(i);
        bejart[i] = true;
        csapat[i] = 1;

        bool melyik = false;

        while(!varolista.empty()){
            int most = varolista.front();
            varolista.pop();

            for(const auto& c : elek[most]){
                if(bejart[c]){
                    if(csapat[c] == csapat[most]){
                        cout << "-1" << endl;
                        return 0;
                    }
                    continue;
                }

                bejart[c] = true;
                csapat[c] = 1 - csapat[most];
                varolista.push(c);
            }
            melyik = !melyik;
        }
    }

    for(int i = 1; i <= N; i++){
        if(bejart[i] && csapat[i] == 1){
            cout << i << " ";
        }
    }cout << endl;

    for(int i = 1; i <= N; i++){
        if(bejart[i] && csapat[i] == 0){
            cout << i << " ";
        }
    }cout << endl;

    return 0;
}