#include <iostream>
#include <vector>

using namespace std;

int v[1000][1000]; //kitoltendo tablazat


int main()
{
	
    int s,o,b,p; //bemenet fogadasa
    cin>>s>>o>>b>>p;
    v[0][0] = p;
    for (int i = 1; i < o; ++i) //elso sor
    {
        cin>>p;
        p = v[0][i-1]+p-b;
        if (p<1 || v[0][i-1] == -1)
        {
            p = -1;
        }
        v[0][i] = p;
    }
	
    for (int i = 1; i < s; ++i) //tabla tobbi resze
    {
        cin>>p;
        p = v[i-1][0]+p-b;
        if (p<1 || v[i-1][0] == -1) 
        {
            p = -1;
        }
        v[0][i] = p;
        for (int j = 1; j < o; ++j)
        {
            cin>>p;
            if (v[i][j-1] < 1 && v[i-1][j] < 1)
            {
                p = -1;
            }
            else
            {
                if (v[i][j-1] > v[i-1][j])
                {
                    p = p + v[i][j-1] - b;
                }
                else
                {
                    p = p + v[i-1][j] - b;
                }
            }
            v[i][j] = p;
        }
    }
	
	
    if (v[s-1][o-1] < 1) // eredmeny kiirasa
    {
        cout<<-1;
        return 0;
    }
    cout<<v[s-1][o-1]<<endl;
    return 0;
}
