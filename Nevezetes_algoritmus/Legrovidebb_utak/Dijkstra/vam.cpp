#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

const int INT_MAX = 1000000;

using namespace std;

class Graph
{
public:
    Graph() {}
    ~Graph() {}
    
    void add_edge(int x, int y)
    {
        edges[x].insert(y);
        edges[y].insert(x);
    }
    
    set<int> get_edges(int x) const { 
        if(edges.find(x) == edges.end()) {
            set<int> empty;
            return empty;
        }
        
        return edges.at(x); 
    }
    set<int> get_vertexes() const {
        set<int> vertexes;
        for(auto kv : weights) {
            vertexes.insert(kv.first);
        }
        return vertexes;
    }
    void add_weight(int x, int w) { weights[x] = w; }
    int get_weight(int x) const { return weights.at(x); }
    
private:
    map<int, set<int> > edges;
    map<int, int> weights;
};

void dijkstra(Graph& g, int start, int end, vector<int>& dist, vector<int>& prev)
{
    set<int> vertexes = g.get_vertexes();
    dist.clear(); dist.resize(vertexes.size());
    prev.clear(); prev.resize(vertexes.size());
    
    for(int v : vertexes)
    {
        dist[v] = INT_MAX;
        prev[v] = -1;
    }
    
    dist[start] = 0;
    
    while(vertexes.size() != 0)
    {
        auto elem = min_element(vertexes.begin(), vertexes.end(), [dist](const int lhs, const int rhs){
            return dist[lhs] < dist[rhs];
        });
        
        int vertex = *elem;

        // cout << vertex << endl;
        vertexes.erase(vertex);
        
        for(int u : g.get_edges(vertex))
        {
            // cout << "  " << u << endl;
            int alt = dist[u] + g.get_weight(u);
            if(alt < dist[vertex])
            {
                dist[vertex] = alt;
                prev[vertex] = u;
            }
        }
    }
}

int main()
{
    int n, m, start, end;
    cin >> n >> m >> start >> end;
    
    Graph g;
    for(int i = 0; i < n; ++i)
    {
        int tmp;
        cin >> tmp;
        g.add_weight(i, tmp);
    }
    
    for(int i = 0; i < m; ++i)
    {
        int tmp1, tmp2;
        cin >> tmp1 >> tmp2;
        g.add_edge(tmp1-1, tmp2-1);
    }
    
    vector<int> dist;
    vector<int> prev;
    
    dijkstra(g, start-1, end-1, dist, prev);


    std::cout << dist[end-1] - g.get_weight(start-1) << std::endl;

    vector<int> reverse_path;
    int ind = end-1;
    do
    {
        reverse_path.push_back(ind+1);
        ind = prev[ind];
    } while(ind != start-1);
     reverse_path.push_back(ind+1);


    for(int i = reverse_path.size() - 1; i >= 0; --i)
    // // for(int i : reverse_path)
    {
        std::cout << reverse_path[i] << " ";
    }
    std::cout << std::endl;

    // std::cout << std::endl;
    // std::cout << std::endl;

    // for(int i = 0; i < n; ++i)
    // {
    //     std::cout << prev[i] << std::endl;
    // }

    return 0;
}
