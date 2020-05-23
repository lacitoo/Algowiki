#include <iostream>
#include <vector>
 
using namespace std;
 
int n,m,temp;
vector<int> piles;
 

int binarySearch(int begin, int end, int val); 

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n;
    piles.push_back(0);
    //intervallumok beolvasása
    for (int i = 0; i < n; ++i) 
    {
        cin >> temp;
        piles.push_back(piles[i] + temp);
    }
    cin >> m;
    //keresendõ elemek beolvasása
    for (int i = 0; i < m; ++i) 
    {
        cin >> temp;
        //elemek megkeresése, és kiírása
        binarySearch(0, n, temp);
    }

    return 0;
}

//bináris keresés
int binarySearch(int begin, int end, int val)
{
    if (end - 1 == begin) 
        cout << end << endl;

    else 
    {
        int mid = (begin + end) / 2;
        if (val == piles[mid]) 
            cout << mid << endl;

        else if (val == piles[end]) 
            cout << end << endl;
        
        else if (val < piles[mid]) 
            binarySearch(begin, mid, val);
        
        else 
            binarySearch(mid, end, val);    
    }

}