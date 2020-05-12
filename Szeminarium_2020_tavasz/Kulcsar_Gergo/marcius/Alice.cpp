#include <iostream>
#include <vector.h>

using namespace std;

void dfs(int curr, int h, int A[], int B[], int C[], int &max){
    if(max<h)
        max = h;
    int i = 0;
    while(i<n-1 && A[i] != curr && C[B[i]] != 0){
        i++;
    }
    if(i<n-1){
        C[B[i]] = 1;
        dfs(B[i], h+1, A, B, C, max);
    }else{
        i = 0;
        while(i<n-1 && B[i] != curr && C[A[i]] != 0){
            i++;
        }
        if(i<n-1){
            C[A[i]];
            dfs(A[i], h+1, A, B, C, max);
        }
    }
}

int main() {
    int 
}