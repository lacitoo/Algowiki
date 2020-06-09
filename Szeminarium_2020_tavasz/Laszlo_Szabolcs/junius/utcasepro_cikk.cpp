#include <iostream>
#include <vector>

using namespace std;

vector<vector<int> > mtrx;
int tin[10000];
int tout[10000];
int timer = 0;

void DFS(int v)
{
    tin[v]=++timer;
    cout<< v+1 <<" ";
    for(int i=0;i<mtrx[v].size();i++)
    {
        if(tin[mtrx[v][i]]==0)
        {
            DFS(mtrx[v][i]);
            cout<<v+1<<" ";
        }
        else if(tout[mtrx[v][i]]!=0)
        {
            cout<<mtrx[v][i]+1<<" "<<v+1 <<" ";
        }
    }
    tout[v]=++timer;
}


int main()
{
    ///Beolvasás
    int a, b, n, m;

    cin>>n>>m;

    vector<int> v;

    mtrx.assign(n,v);

    for(int i=0;i<m;i++)
    {
        cin>>a>>b;

        mtrx[a-1].push_back(b-1);
        mtrx[b-1].push_back(a-1);
    }
    ///Függvénymeghívás
    DFS(0);

    return 0;
}
