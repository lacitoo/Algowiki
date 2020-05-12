#include <iostream>

using namespace std;

///1 A-ból mehet 2 kölünböző B-be
///2 A-ból nem mehet ugyanabba a B-be


int main()
{
    int n;
    cin >> n;
    int S[n];
    int C[n];
    for(int i=0; i<n; i++) {
        cin >> S[i];
    }
    for(int i=0; i<n; i++) {
        cin >> C[i];
    }
    int A[n];
    A[0] = 0;
    int ai = 1;
    int B[n];
    int bi = 0;
    int Ba[n];
    int l = 0;
    int Cc[n];
    int ci = 0;
    int Cb[n];
    for(int i=1; i<n; i++) {
        int j = 0;
        //while(S[i]<S[A[j]] && j<ai) {
        //    j++;
        //}
        for(; j<ai; j++) {
            if(S[i]>=S[A[j]]) {
                break;
            }
        }
        if(j==i) {
            A[ai] = i;
            ai++;
            continue;
        }
        int p = 0;
        for(; p<i; p++) {
            if(S[p]<=S[i] && C[p]<=C[i]) {
                break;
            }
        }
        if(p==i) {
            A[ai] = i;
        }
        l = -1;
        for(int k=0; k<ai; k++) {
            if(S[A[k]]<S[i] && (l==-1 || C[A[k]]<C[l])) {
                l = A[k];
            }
        }
        if(l>-1) {
            B[bi] = i;
            Ba[bi] = l;
        }
        if(p==i) {
            ai++;
        }
        int q = -1;
        for(int k=0; k<bi; k++) {
            if(S[B[k]]<S[i] && (q==-1 || C[B[k]]+C[Ba[k]]<C[B[q]]+C[Ba[q]])) {
                q = k;
            }
        }
        if(q>-1) {
            Cc[ci] = i;
            Cb[ci] = q;
            ci++;
        }
        if(l>-1) {
            bi++;        
        }
    }

    int m = -1; 
    for(int i=0; i<ci; i++) {
        if(m==-1 || C[Cc[i]]+C[B[Cb[i]]]+C[Ba[Cb[i]]] < m) {
            m = C[Cc[i]]+C[B[Cb[i]]]+C[Ba[Cb[i]]];
        }
    }
    cout << m;
    return 0;
}