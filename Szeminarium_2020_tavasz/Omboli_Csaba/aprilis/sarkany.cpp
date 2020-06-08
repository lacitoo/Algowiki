#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

int lkkt(int a,int b);

int main()
{
    int n,penzunk;
    vector<int> napok;
    cin>>n>>penzunk;
    for(int i=0;i<n;i++)
    {

        int tmp;
        cin>>tmp;
       napok.push_back(tmp);
    }
    bool van=false;
    int mego;
    int i=0;
    while(i<n && van==false)
    {
        int j=0;
        while(j<i && van==false)
        {
            int osszeg=0;
            for(int k=j;k<j+(n-i)+1;k++)
            {
                osszeg+=napok[k];
                //cout<<napok[k]<<" ";
            }
            mego=n-i+1;
            van=osszeg<=penzunk;
                //cout<<"//"<<osszeg<<"//";
                //cout<<"|";
                j++;
        }
        //cout<<endl;
        i++;
    }
    if(van)
        cout<<mego;
    else
        cout<<0;
    return 0;
}
int lkkt(int a,int b)
{
    int szorzat=a*b;
    int tmp;

   if (a<0) a= -a;
   if (b<0) b= -b;
   while(b > 0) {
      tmp = b;
      b = a % b;
      a = tmp;
   }
   return szorzat/a;
}
