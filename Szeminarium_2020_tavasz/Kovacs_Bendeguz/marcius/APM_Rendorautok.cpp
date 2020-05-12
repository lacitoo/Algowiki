using namespace std;
#include <iostream>
#include <vector>

int hol[100000000] = { 0 };

int main()
{
    int n, m, max = 0;
    vector<pair<int, int>> elso;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        elso.push_back(make_pair(a - 1, b - 1));
        if (b > max) { max = b; }
        for (int i = a - 1; i <= b - 1; i++)
        {
            hol[i]++;
        }
    }
    vector<pair<int, int>> masodik;
    cin >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        elso.push_back(make_pair(a - 1, b - 1));
        if (b > max) { max = b; }
        for (int i = a - 1; i <= b - 1; i++)
        {
            hol[i]++;
        }
    }

    int db = 0;
    int seged = 0;
    for (int i = 0; i < max; i++)
    {
        if (hol[i] == 0 || i == max-1) { if (seged != 0) { seged = 0; db++; } }
        else { seged++; }
    }
    //if (hol[max - 1] != 0) { db++; }
    cout << db;

    seged = 0;
    for (int i = 0; i < max; i++)
    {
        if (hol[i] == 0 || i == max-1) {
            if (seged != 0) { if (i == max - 1) { cout << "\n" << i - seged + 1 << " " << i+1; seged = 0; } else { cout << "\n" << i - seged + 1 << " " << i; seged = 0; } }
        }
        else { seged++; }
    }

}