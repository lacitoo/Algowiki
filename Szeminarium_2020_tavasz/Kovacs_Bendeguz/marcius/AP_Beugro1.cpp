using namespace std;
#include <iostream>
#include <vector>
#include <math.h>

int n;
vector<int> meretek;
vector<int> arak;
int minimumar = 2000000000;
int mine = -1;
int minej = -1;

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
        if (b < minimumar) { minimumar = b; }
        arak.push_back(b);
    }
}

int minAB()
{
    int min = 2000000000;
    int mini = 0;
    for (int i = 1; i < (n-1); i++)
    {
        if (arak[i] < min && arak[i] >= mine && i != minej) { min = arak[i]; mini = i;}
    }
    mine = min;
    minej = mini; 
    return mini;
}

int minJ(int a)
{
    int i = 0;
    int minj = -1;
    int mineddig = -1;
    int mineddigj = -1;
    while (i != (n - a))
    {
        int min = 2000000000;
        for (int j = a; j < n; j++)
        {
            if (arak[j] < min && arak[j] >= mineddig && j != mineddigj) { min = arak[j]; minj = j; }
        }
        if (meretek[a-1] < meretek[minj]) { return minj; }
        mineddig = min;
        mineddigj = minj;
        i++;
    }
    
    return -1;
}

int minB(int b)
{
    int a = 0;
    int i = 0;
    int minj = -1;
    int mineddig = -1;
    int mineddigj = -1;
    while (i != (b - a))
    {
        int min = 2000000000;
        for (int j = a; j < b; j++)
        {
            if (arak[j] < min && arak[j] >= mineddig && j != mineddigj) { min = arak[j]; minj = j; }
        }
        if (meretek[b] > meretek[minj]) { return minj; }
        mineddig = min;
        mineddigj = minj;
        i++;
    }

    return -1;
}

int megoldas1()
{
    int min = 2000000000;
    for (int i = 0; i < n - 2; i++) {
        if (arak[i] + (2 * minimumar) < min)
        {
            for (int j = i + 1; j < n - 1; j++) {

                if ((arak[j] + arak[i] + minimumar) < min)
                {
                    for (int k = j + 1; k < n; k++)
                    {
                        if (meretek[i] < meretek[j] && meretek[j] < meretek[k])
                        {
                            if ((arak[i] + arak[j] + arak[k]) < min) { min = (arak[i] + arak[j] + arak[k]); }
                        }
                    }
                }
            }
        }
    }


    if (min == 2000000000) { min = -1; }
    return min;
}

int megoldas2()
{
    int vege = 2000000000;
    int meddig = n;
    if (n > 15) { meddig = floor(n / 5); }
    else { meddig = 5; }
    
    for (int i = 0; i < meddig; i++)
    {
        int c = minAB();
        if (minB(c) != -1 && minJ(c + 1) != -1)
        {
            int t = arak[minB(c)] + arak[minJ(c + 1)] + arak[c];
            if (t < vege) { vege = t; }
        }
    }
    if (vege == 2000000000) { return -1; }
    else { return vege; }
}

int main()
{
    beolvasas();

    int megoldas = megoldas1();
    //int megoldas = megoldas2();

    cout << megoldas;   
}
