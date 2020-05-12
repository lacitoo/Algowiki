#include <iostream>
 
using namespace std;
 
int smallestSubWithSum(int arr[], int n, int x)
{
    int curr_sum = 0, min_len = n+1;
 
    int start = 0, end = 0;
    while (end < n)
    {
 
        while (curr_sum <= x && end < n)
            curr_sum += arr[end++];
 
        while (curr_sum > x && start < n)
        {
            if (end - start < min_len)
                min_len = end - start;
 
            curr_sum -= arr[start++];
        }
    }
    return min_len;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,p,mini;
    cin >> n >> p;
    int tomb[n];
    for (int i=0; i<n ;i++){
            cin>>tomb[i];
    }
 
    mini=smallestSubWithSum(tomb, n, p);
    cout << mini;
    return 0;
}
