#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Vertex {
    Vertex(int _ind) : ind(_ind) {}

    int ind;
    bool visited = false;
    vector<int> edges;
    int parent = -1;
    int cnt = 0;
};

class Graph_EL
{
public:
    Graph_EL(int _n) : n(_n) {
        for (int i = 0; i < n; ++i) {
            Vertex vert(i);
            v.push_back(vert);
        }
    }

    void addEdge(int a, int b) {
        v[a].edges.push_back(b);
        v[b].edges.push_back(a);
    }

    void bfs(int start) {
        queue<int> q;
        q.push(start);
        v[start].visited = true;
        while (!q.empty()) {
            int from = q.front();
            q.pop();
            for (int to : v[from].edges) {
                if(v[to].visited && to != v[from].parent){
                    cout << v[from].cnt + v[to].cnt + 1 << endl;
                    queue<int> res;
                    vector<int> r;
                    while(from != start){
                        r.push_back(from);
                        from = v[from].parent;
                    }
                    while(to != start){
                        res.push(to);
                        to = v[to].parent;
                    }
                    cout << start << " ";
                    while(!r.empty()){
                        int x = r.back();
                        r.pop_back();
                        cout << x << " ";
                    }
                    while(!res.empty()){
                        cout << res.front() << " ";
                        res.pop();
                    }
                    return;
                }
                else if(!v[to].visited){
                    v[to].visited = true;
                    v[to].parent = from;
                    v[to].cnt = v[from].cnt + 1;
                    q.push(to);
                }
            }
        }
    }
private:
    int n;
    vector<Vertex> v;
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, start;
    cin >> n >> m >> start;

    Graph_EL graph(n+1);
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        graph.addEdge(a, b);
    }
    graph.bfs(start);
    return 0;
}