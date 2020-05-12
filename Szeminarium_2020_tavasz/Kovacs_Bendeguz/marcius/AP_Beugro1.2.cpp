using namespace std;
#include <iostream>
#include <vector>
#include <algorithm>

int n;
vector<int> meretek;
vector<int> arak;

void beolvasas()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int b;
        cin >> b;
        meretek.push_back(b);
    }
    for (int i = 0; i < n; i++)
    {
        int b;
        cin >> b;
        arak.push_back(b);
    }
}

int megoldas()
{
    int aa, bb, cc;
   int b = min_element(arak);
   for(int i = 0; i < n; i++)
   {
       if (b == 0 || b == n - 1) { break; }
       for (int j = b; j < n; j++)
       {
           if ( meretek[(min_element(arak[b + 1], arak.end))] > b )
           {
               cc = arak[min_element(arak[b + 1], arak.end)];
           }
           else
           {
               break;
           }
       }
   }
}

int main()
{
    beolvasas();
    //int megoldas = megoldas();
   
}
