#include <iostream>

using namespace std;

const int MaxN = 4000;

int N;
int P[MaxN];
int LCS[MaxN + 1][MaxN + 1];

bool VanE = false;
int K, L;

int main() {
    ios::sync_with_stdio(false);
    
    cin >> N;
    
    for (int i = 0; i < N; ++i) {
        cin >> P[i];
    }
    
    for (int i = 0; i < N; ++i) {
        LCS[0][i] = 0;
    }
    
    for (int i = 1; i <= N; ++i) {
        for (int j = i + 1; j <= N; ++j) {
            if (P[i - 1] == P[j - 1]) {
                LCS[i][j] = LCS[i - 1][j - 1] + 1;
                
                if (!VanE || LCS[i][j] > L) {
                    VanE = true;
                    L = LCS[i][j];
                    K = i - L;
                }
            } else {
                LCS[i][j] = 0;
            }
        }
    }
    
    if (VanE) {
        for (int i = 0; i < L; ++i) {
            cout << P[K + i] << " ";
        }
        
        cout << endl;
    } else {
        cout << -1 << endl;
    }
    
    return 0;
}
