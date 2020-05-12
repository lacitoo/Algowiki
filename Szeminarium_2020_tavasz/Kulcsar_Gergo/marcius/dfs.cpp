#include <iostream>

using namespace std;

void dfs(int m, int A[], int B[], int C[], int a, int64_t &multi) {
    for(int i=0; i<m; i++) {
        if(A[i] == a && C[B[i]-1] == 0) {
            multi = multi * 2;
            C[B[i]-1] = 1;
            dfs(m, A, B, C, B[i], multi);
        } else if(B[i] == a && C[A[i]-1] == 0) {
            multi = multi * 2;
            C[A[i]-1] = 1;
            dfs(m, A, B, C, A[i], multi);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    int A[m], B[m];
    for(int i=0; i<m; i++) {
        cin >> A[i];
        cin >> B[i];
    }
    int C[n];
    for(int i=0; i<n; i++) {
        C[i] = 0;
    }
    int64_t multi = 1;
    for(int j=1; j<=n; j++) {
        if(C[j-1] == 0) {
            C[j-1] = 1;
            dfs(m, A, B, C, j, multi);
        }
    }
    cout << multi;
}