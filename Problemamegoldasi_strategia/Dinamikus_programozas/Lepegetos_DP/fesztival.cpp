#include <bits/stdc++.h>

using namespace std;

struct elo
{
    int kezd, veg, id, ert;
    int bev;
    elo*chosen;
    bool kell = false;
};

elo t[100001];

bool grtr (elo a, elo b) //a rendezéshez szükséges (ezzel használjuk a sort() függvényt)
{
    return (a.veg<b.veg);
}

vector<elo> vec;
int n;


int indfinder(int ala, int fr) //ennél gyorsabban is meg lehetne találni az indexet, de a feladathoz ez is elégséges volt
{
    int i = fr;
    while (i--)
    {
        if (t[i].veg < t[fr].kezd)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //beolvasás
    cin>>n;
    for (int i = 0; i < n; ++i)
    {
        t[i].id=i+1;
        cin>>t[i].kezd>>t[i].veg>>t[i].ert;
    }
    //beolvasás vége

    sort(t,t+n, grtr); //rendezés

    //itt készülnek a részeredmények
    int mind = 0;
    for (int i = 0; i < n; ++i)
    {
        int van, vani, nincs;
        nincs = t[i-1].bev;
        vani = indfinder(t[i].kezd,i);
        if (vani == -1)
        {
            van = t[i].ert;
        }
        else
        {
            van = t[vani].bev+t[i].ert;
        }

        if (van>nincs)
        {
            t[i].bev=van;
            t[i].kell = true;
            if (vani != -1)
                t[i].chosen = &t[vani];
        }
        else
        {
            t[i].bev=nincs;
            t[i].chosen=&t[i-1];
        }
        if (t[i].bev>t[mind].bev) //leellenõrzi, hogy ez-e a legnagyobb részeredmény
        {
            mind = i;
        }
    }
    //itt már elkészültek a részeredmények


    cout<<t[mind].bev<<endl; //megvan a maximális bevétel

    //összegyûjtjük az optimális lista elemeit
    vector<int> ered;
    elo*mut=&t[mind];

    while (mut)
    {
        if (mut->kell)
        {

            ered.push_back(mut->id);
        }
        mut = mut->chosen;
    }


    //és kiírjuk
    cout<<ered.size();
    for (int i = 0; i < ered.size(); ++i)
    {
        cout<<' '<<ered[i];
    }
    //hurrá, kint van!

    return 0;
}
 /*
         (__)
         (oo)
   /------\/
  / |    ||
 *  /\---/\
    ~~   ~~
*/
