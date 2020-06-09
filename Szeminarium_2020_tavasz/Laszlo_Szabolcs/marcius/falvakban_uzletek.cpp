#include <iostream>
#include <vector>

using namespace std;

vector<vector<int> > G;
bool szin[10001];
bool volt[10001];

bool szomszed(int s)
{
    for(int i=0;i<G[s-1].size();i++)
    {
        if(szin[G[s-1][i]-1]==true)
        {
            return true;
        }
    }
    return false;
}
void MB(int s)
{
        volt[s-1]=true;
        for(int i=0;i<G[s-1].size();i++)
        {
            if(!volt[G[s-1][i]-1])
            {
                MB(G[s-1][i]);
            }
        }
        if(szin[s-1]==false&&szomszed(s)==false)
        {
            szin[s-1]=true;
        }
}

void beolvas()
{
    int n, v1, v2;
    cin>>n;
    vector<int> vertex;
    G.assign(n, vertex);
    for(int i=0;i<n-1;i++)
    {
        cin>>v1>>v2;
        G[v1-1].push_back(v2);
        G[v2-1].push_back(v1);
    }
}

void kiir()
{
    int c1=0;

    for(int i=0;i<G.size();i++)
    {
        if(szin[i])
        {
            c1++;
        }
    }
    cout<<c1<<endl;

    for(int i=0;i<G.size();i++)
    {
        if(szin[i])
        {
            cout<<i+1<<" ";
        }
    }
}

int main()
{
    beolvas();
    MB(1);
    kiir();


    return 0;
}
