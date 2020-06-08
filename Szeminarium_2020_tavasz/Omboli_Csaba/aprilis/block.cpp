#include <iostream>
#include <algorithm>

using namespace std;
int elofordulas(string s, char c);
int main()
{
    int n;
    string blocks;
    cin>>blocks;
    n=blocks.size();
    int b,w;
    b=elofordulas(blocks,'B');

    if(b==0 || b==n)
    {
        cout<<0;
    }
    else
    {
        if(b % 2!=0 && (n-b)%2!=0)
            cout<<-1;
        else
        {
            //megoldás
            char c=blocks[0];
            int x=1;
            while(x<n && blocks.at(x)==c)
            {
                x++;
            }
            //cout<<x+1;

        }
    }
    return 0;
}

int elofordulas(string s, char c)
{
    int osszeg=0;
    for(int i=0;i<s.size();i++)
    {
        if(s.at(i)==c)
        {
            osszeg++;
        }
    }
    return osszeg;
}
