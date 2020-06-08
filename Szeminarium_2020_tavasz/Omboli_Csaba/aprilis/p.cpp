#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    vector<int>meghivottak;
    vector<int> kimenet;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int a,b;
        cin>>a>>b;
        meghivottak.push_back(a);
        meghivottak.push_back(b);
    }
    sort(meghivottak.begin(),meghivottak.end());
    for(int i=0;i<meghivottak.size()-1;i++)
    {
        if(find(kimenet.begin(),kimenet.end(),meghivottak[i])==kimenet.end())
        {
         if(meghivottak[i]==meghivottak[i+1])
            kimenet.push_back(meghivottak[i]);
        }
    }
    for(int i=0;i<meghivottak.size();i++)
        cout<<meghivottak.at(i)<<" ";

    cout<<endl;
    cout<<kimenet.size()<<endl;
    for(int i=0;i<kimenet.size();i++)
        cout<<kimenet.at(i)<<" ";

    return 0;
}
