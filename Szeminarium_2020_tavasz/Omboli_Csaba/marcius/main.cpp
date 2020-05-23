#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    unsigned int a,b,c,d,eredmeny;
    unsigned short int e,f;
    cin>>a>>b>>c>>d>>e>>f;

    if(e>f)
    {
        int mininum=min(a,d);
        eredmeny=mininum*e;
        a-=mininum;
        d-=mininum;
        mininum=min(min(b,c),d);
        eredmeny+=mininum*f;
    }
    else
    {
        int mininum=min(min(b,c),d);
        eredmeny=mininum*f;
        b-=mininum;
        c-=mininum;
        d-=mininum;
        mininum=min(a,d);
        eredmeny+=mininum*e;
    }
    cout<<eredmeny;
    return 0;
}
