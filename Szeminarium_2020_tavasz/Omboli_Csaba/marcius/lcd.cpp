#include <iostream>

using namespace std;
string max_szam(int num);
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int d;
        cin>>d;
        cout<<max_szam(d)<<endl;
    }
    return 0;
}
 string max_szam(int num)
 {
     string szam="";
     if(num % 2 == 0)
     {
         for(int i=0;i<num/2;i++)
         {
             szam+="1";
         }
     }
     else
     {
         szam="7";
         for(int i=0;i<(num-3)/2;i++)
         {
             szam+="1";
         }
     }
     return szam;
 }
