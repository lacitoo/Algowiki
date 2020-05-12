#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>

using namespace std;

int memory[1001][1001];

int find_length(string szo, int i, int j)
{
    if (memory[i][j] != -1)
    {
        return memory[i][j];
    }
    if (i == j)
    {
        return memory[i][j] = 1;
    }
    else if (szo[i] == szo[j] && i + 1 == j)
    {
        return memory[i][j] = 2;
    }
    else if (szo[i] == szo[j])
    {
        return memory[i][j] = find_length(szo, i + 1, j - 1) + 2;
    }
    return memory[i][j] = max(find_length(szo, i, j - 1), find_length(szo, i + 1, j));
}

int main()
{
    string szo;
    cin >> szo;
    memset(memory, -1, sizeof(int) * 1001 * 1001);
    cout << find_length(szo, 0, szo.size() - 1);

    return 0;
}
