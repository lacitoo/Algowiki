// Mester -> NT, OKTV, IOI valogato -> IOI Valogato 2019 -> 5. Banda szetvalasztasa
#include <iostream>
#include <vector>

using namespace std;


struct Vertex {
    Vertex(int _ind) : ind(_ind) {}

    int ind, in = -1, low = -1, cutsTo = 0, bigest = 0;
    bool visited = false;
    vector<int> edges;
};

class bandaSzetvalasztasa
{
public:
    bandaSzetvalasztasa(int _n) : n(_n) {
        for (int i = 0; i < n; ++i) {
            Vertex vert(i);
            v.push_back(vert);
        }
        isCutPoint.assign(n, false);
    }

    void addEdge(int a, int b) {
        v[a].edges.push_back(b);
        v[b].edges.push_back(a);
    }

    int solution() {
        dfsLow(0, -1);

        int cutsToMax = 0, bigestMin = n, result = n;
        for (int i = 0; i < n; ++i) {
            if (isCutPoint[i]) {
                clearVisited();
                v[i].visited = true;
                for (int child : v[i].edges) {
                    currGroup = 0;
                    if (!v[child].visited) {
                        ++v[i].cutsTo;
                        dfsCount(child);
                    }
                    if (currGroup > v[i].bigest) {
                        v[i].bigest = currGroup;
                    }
                }
                if (v[i].cutsTo > cutsToMax) {
                    cutsToMax = v[i].cutsTo;
                    bigestMin = v[i].bigest;
                    result = i;
                } else if (v[i].cutsTo == cutsToMax && v[i].bigest < bigestMin) {
                    bigestMin = v[i].bigest;
                    result = i;
                }
            }
        }

        return result;
    }

private:
    int n, timer = 0, currGroup;
    vector<Vertex> v;
    vector<bool> isCutPoint;

    void dfsLow(int from, int parent) {
        v[from].visited = true;
        ++timer;
        v[from].in = timer;
        v[from].low = timer;

        int children = 0;
        for (int to : v[from].edges) {
            if (to == parent) {
                continue;
            }
            if (!v[to].visited) {
                dfsLow(to, from);
                v[from].low = min(v[from].low, v[to].low);
                if (v[to].low >= v[from].in && parent != -1) {
                    isCutPoint[from] = true;
                } 
                ++children;
            } else {
                v[from].low = min(v[from].low, v[to].in);
            }
        }

        if (parent == -1 && children > 1) {
            isCutPoint[from] = true;
        }
    }

    void dfsCount(int from) {
        ++currGroup;
        v[from].visited = true;
        for (int to : v[from].edges) {
            if (!v[to].visited) {
                dfsCount(to);
            }
        }
    }

    int min(int a, int b) {
        return a < b ? a : b;
    }

    void clearVisited() {
        for (int i = 0; i < n; ++i) {
            v[i].visited = false;
        }
    }
};



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    bandaSzetvalasztasa bsz(n);
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        bsz.addEdge(a - 1, b - 1);
    }

    cout << bsz.solution() + 1 << endl;

    return 0;
}