#include <iostream>
#include <vector>

using namespace std;



struct P
{
    vector<int> inf;
    int depth=1;
    bool been_there=false;

};

vector<P> G;
int numbers[2000];

void assert(int i)
{
        if(numbers[i]==-1)
        {
            G[i].been_there=true;
        }
        else
        {
            if(!G[numbers[i]-1].been_there)
            {
                assert(i);
            }
            G[numbers[i]-1].inf.push_back(i);
            G[i].depth = G[numbers[i]-1].depth + 1;
            G[i].been_there=true;
        }



}

int main()
{
    int n;
    cin>>n;
    P vertex;
    G.assign(n, vertex);
    for(int j=0;j<n;j++)
    {
        cin>>numbers[j];
    }
    int max=0;
    for(int i=0;i<n;i++)
    {
        if(!G[i].been_there)
        {
            assert(i);
        }

    }
    for(int k=0;k<n;k++)
    {
        if(G[k].depth>max)
        max=G[k].depth;
    }
    cout<<max;


}
