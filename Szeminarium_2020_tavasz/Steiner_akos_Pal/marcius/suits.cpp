#include <iostream>
#include <algorithm>
 
using namespace std;
 
int main()
{
    int a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;
 
    int minimum;
    int result;
 
    if (e > f)
    {
       minimum = min(a,d);
 
       result = minimum * e;
       a = a - minimum;
       d = d - minimum;
 
       minimum = min(min(b, c), d);
       result = result + minimum * f;
 
    }
    else
    {
       minimum = min(min(b, c), d);
 
       result = minimum * f;
       b = b - minimum;
       c = c - minimum;
       d = d - minimum;
 
       minimum = min(a,d);
       result = result + minimum * e;
    }
 
    cout << result;
 
    return 0;
}