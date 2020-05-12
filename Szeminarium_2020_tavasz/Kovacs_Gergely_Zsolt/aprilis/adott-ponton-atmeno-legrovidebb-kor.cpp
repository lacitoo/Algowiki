#include <iostream>
#include <vector>
#include <queue>
#include <deque>

using namespace std;

vector<vector<int>> G;
vector<int> tav;
vector<int> elozo;

pair<int, int> BFS(int start)
{
    pair<int, int> eredm(-1, -1);
    int minhossz = -1;
    queue<int> csucsok;
    csucsok.push(start);
    tav[start] = 0;
    while (!csucsok.empty())
    {
        int csucs = csucsok.front();
        csucsok.pop();
        for (int c : G[csucs])
        {
            if (tav[c] == -1)
            {
                tav[c] = tav[csucs] + 1;
                elozo[c] = csucs;
                csucsok.push(c);
            }
            else if (c != elozo[csucs] && (minhossz == -1 || tav[csucs] + tav[c] < minhossz))
            {
                minhossz = tav[csucs] + tav[c];
                eredm.first = csucs;
                eredm.second = c;
            }
        }
    }
    return eredm;
}

void elolkeres(deque<int> &dq)
{
    int curr = dq.front();
    if (tav[curr] > 0)
    {
        for (int c : G[curr])
        {
            if (tav[c] == tav[curr] - 1)
            {
                dq.push_front(c);
                break;
            }
        }
        elolkeres(dq);
    }
}

void hatulkeres(deque<int> &dq)
{
    int curr = dq.back();
    if (tav[curr] > 1)
    {
        for (int c : G[curr])
        {
            if (tav[c] == tav[curr] - 1)
            {
                dq.push_back(c);
                break;
            }
        }
        hatulkeres(dq);
    }
}

int main()
{
    int pontdb, eldb, keres;
    cin >> pontdb >> eldb >> keres;
    keres--;
    G.resize(pontdb);
    tav.resize(pontdb, -1);
    elozo.resize(pontdb);
    for (int i = 0; i < eldb; i++)
    {
        int x, y;
        cin >> x >> y;
        G[x - 1].push_back(y - 1);
        G[y - 1].push_back(x - 1);
    }
    pair<int, int> korkozep = BFS(keres);
    if (korkozep.first == -1 && korkozep.second == -1)
    {
        cout << "-1\n";
        return 0;
    }

    deque<int> eredm;
    eredm.push_front(korkozep.first);
    eredm.push_back(korkozep.second);

    elolkeres(eredm);
    hatulkeres(eredm);
    cout << eredm.size() << endl;
    for (int c : eredm)
        cout << c + 1 << " ";
    cout << endl;
    return 0;
}