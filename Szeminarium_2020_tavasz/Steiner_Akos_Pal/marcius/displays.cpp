#include <iostream>
#include <algorithm>
#include <vector>
 
using namespace std;
 
int main()
{
    int n;
 
    cin >> n;
 
    int s[n];
    int c[n];
 
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
    }
 
    for (int i = 0; i < n; i++)
    {
        cin >> c[i];
    }
 
    int maximum = *max_element(c,c+n);
    int minimum = *min_element(c,c+n);
 
    int result = maximum * 3 + 1;
    bool fain = false;
 
    for (int i = 0; i < n-2; i++)
    {
        if (result > c[i] + minimum * 2)
        for (int j = i; j < n-1; j++)
        {
            if(s[j] > s[i] && result > c[i] + c[j] + minimum)
            {
                for (int k = j; k < n; k++)
                {
                    if (s[k] > s[j] && result > c[i] + c[j] + c[k])
                    {
                        result = c[i] + c[j] + c[k];
                        fain  = true;
                    }
                }
            }
        }
    }
 
    if (fain == false)
    {
        result = -1;
    }
 
    cout << result;
 
    return 0;
}