#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> G;
vector<bool> visited;
vector<bool> leszX;
vector<bool> leszY;

void BFS(int start, int X, int Y, int &leszXdb, int &leszYdb)
{
    queue<int> q;
    q.push(start);
    visited[start] = true;
    while (!q.empty())
    {
        int current = q.front();
        q.pop();
        for (int v : G[current])
        {
            if (!visited[v])
            {
                q.push(v);
                visited[v] = true;
                if (current == X || leszX[current])
                {
                    leszX[v] = true;
                    leszXdb++;
                }
                if (current == Y || leszY[current])
                {
                    leszY[v] = true;
                    leszYdb++;
                }
            }
        }
    }
}

int main()
{
    int X, Y, hossz, a;
    cin >> hossz >> X >> Y;
    X--;
    Y--;
    G.resize(hossz);
    visited.resize(hossz, false);
    leszX.resize(hossz, false);
    leszY.resize(hossz, false);

    for (int i = 1; i < hossz; i++)
    {
        cin >> a;
        G[a - 1].push_back(i);
        G[i].push_back(a - 1);
    }
    int Xdb = 0, Ydb = 0;
    BFS(0, X, Y, Xdb, Ydb);
    if (leszX[Y])
    {
        cout << 1;
    }
    else if (leszY[X])
    {
        cout << 2;
    }
    else
    {
        cout << 3;
    }
    cout << endl;
    // Második feladat
    cout << 0 << endl;

    cout << Xdb << " " << Ydb << endl;
    return 0;
}