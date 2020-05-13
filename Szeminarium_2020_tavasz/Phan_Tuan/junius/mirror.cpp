#include <bits/stdc++.h> 
  

using namespace std;
char w[1001];  
char rw[1001];

  

int lcs(char* X, char* Y, int m, int n) 
{ 
    int L[m + 1][n + 1]; 
    int i, j; 
  

    for (i = 0; i <= m; i++) { 
        for (j = 0; j <= n; j++) { 
            if (i == 0 || j == 0) 
                L[i][j] = 0; 
  
            else if (X[i - 1] == Y[j - 1]) 
                L[i][j] = L[i - 1][j - 1] + 1; 
  
            else
                L[i][j] = max(L[i - 1][j], L[i][j - 1]); 
        } 
    } 
  
    return L[m][n]; 
} 
  

int max(int a, int b) 
{ 
    return (a > b) ? a : b; 
} 
  

int main() 
{    
    string input;
    cin >> input;
    int hossz = input.size();
    strcpy(w, input.c_str());
    reverse(input.begin(), input.end());
    strcpy(rw, input.c_str());
  
    cout<<lcs(w, rw, hossz, hossz);
  
    return 0; 
} 