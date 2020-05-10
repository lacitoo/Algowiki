#include <iostream>
#include <vector>
#include <queue>

using namespace std;


struct Vertex
{
    vector<int> edges;
    int parent = -1, distFromRoot = 0;
};

class TheTagGame
{
public:
    TheTagGame(int _n, int _x) : n(_n), x(_x) {
        for (int i = 0; i < n; ++i) {
            Vertex vert;
            v.push_back(vert);
        }
    }

    void addEdge(int a, int b) {
        v[a].edges.push_back(b);
        v[b].edges.push_back(a);
    }

    int solution() {
        init();

        int heighest = x;
        for (int i = 0; i < (v[x].distFromRoot - 1) / 2; ++i) {
            heighest = v[heighest].parent;
        }
        
        queue<int> q;
        q.push(heighest);
        
        int maxDist = v[heighest].distFromRoot;
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            maxDist = max(maxDist, v[curr].distFromRoot);

            for (int child : v[curr].edges) {
                if (child != v[curr].parent) {
                    q.push(child);
                }
            }
        }
        return maxDist * 2;
    }

private:
    int n, x;
    vector<Vertex> v;

    void init() {
        queue<int> q;
        q.push(0);

        while(!q.empty()) {
            int from = q.front();
            q.pop();

            for (int to : v[from].edges) {
                if (v[from].parent != to) {
                    v[to].parent = from;
                    v[to].distFromRoot = v[from].distFromRoot + 1;
                    q.push(to);
                }
            }
        }
    }

    int max(int a, int b) {
        return a > b ? a : b;
    }
};



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, x;
    cin >> n >> x;

    TheTagGame ttg(n, x - 1);
    for (int i = 1; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        ttg.addEdge(a - 1, b - 1);
    }

    cout << ttg.solution() << endl;

    return 0;
}