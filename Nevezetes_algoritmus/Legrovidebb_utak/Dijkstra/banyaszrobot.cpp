#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <sstream>

template <typename T,typename U>                                                   
std::pair<T,U> operator+(const std::pair<T,U> & l,const std::pair<T,U> & r) {   
    return {l.first+r.first,l.second+r.second};                                    
}    

void print_graph(int** graph, int n, int m)
{
    for(int i = 0; i < n; ++i)
    {
        std::cout << "|";
        for(int j = 0; j < m; ++j)
        {
            std::cout << std::setfill(' ') << std::setw(4) << graph[i][j] << "|";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

std::vector< std::pair<int,int> > neightbours(const std::vector< std::pair<int,int> >& Q, const std::pair<int,int>& u)
{
    std::vector< std::pair<int,int> > out;
    const static std::vector< std::pair<int,int> > neightbour_pairs = { {0,1}, {0,-1}, {-1,0}, {1,0} };
    for(int i = 0; i < 4; ++i)
    {
        auto is_elem = std::find(Q.begin(), Q.end(), u + neightbour_pairs[i]);
        if(is_elem != Q.end())
        {
            out.push_back(*is_elem);
        }
    }

    return out;
}

int dijkstra(int** graph, int n, int m, std::pair<int,int> begin, std::pair<int,int> end)
{
    std::vector< std::pair<int,int> > Q;

    int** dist = new int*[n];
    for(int i = 0; i < n; ++i)
    {
        dist[i] = new int[m];
        for(int j = 0; j < m; ++j)
        {
            dist[i][j] = __INT_MAX__;
            Q.push_back({i,j});
        }
    }
    dist[begin.first][begin.second] = 0;

    while(Q.size() != 0)
    {
        auto it = std::min_element(Q.begin(), Q.end(), [dist](const std::pair<int,int>& lhs, const std::pair<int,int>& rhs){
            return dist[lhs.first][lhs.second] < dist[rhs.first][rhs.second];
        });

        // std::cout << "# " << dist[begin.first][begin.second] << " " << dist[it->first][it->second] << std::endl;
        // std::cout << "Ł  " << it->first << " " << it->second << std::endl;
        
        std::pair<int,int> u = *it;
        Q.erase(it);

        for(auto v : neightbours(Q, u))
        {
            // std::cout << "&   " << v.first << " " << v.second << std::endl;
            // std::cout << dist[u.first][u.second] << " " << graph[v.first][v.second] << std::endl;
            int alt = dist[u.first][u.second] + graph[v.first][v.second];
            if(alt < dist[v.first][v.second])
            {
                dist[v.first][v.second] = alt;
            }
        }
    }

    // print_graph(dist, n, m);

    return dist[end.first][end.second];
}

int main(int argc, char const *argv[])
{
    // std::vector< std::pair<int,int> > asd;
    // for(int i = 0; i < 3; ++i)
    // {
    //     for(int j = 0; j < 3; ++j)
    //     {
    //         asd.push_back({i,j});
    //     }
    // }
    // std::vector< std::pair<int,int> >::iterator a = asd.begin() + 4;
    // std::cout << a->first << " " << a->second << " " << std::endl;
    // for(auto v : neightbours(asd, asd.begin() + 4) )
    //     std::cout << v.first << " " << v.second <<"   ";

    std::string line;
    std::getline(std::cin, line, '\n');
    std::stringstream ss(line);

    int n, m, f;
    ss >> n >> m >> f;

    std::pair<int,int> begin, end;

    int** graph = new int*[n];

    for(int i = 0; i < n; ++i)
    {
        graph[i] = new int[m];
        std::getline(std::cin, line, '\n');
        for(int j = 0; j < m; ++j)
        {
            switch (line[j])
            {
                case ' ': graph[i][j] = 1; break;
                case '*': graph[i][j] = f; break;
                case 'K': graph[i][j] = 0; begin = {i,j}; break;
                case 'C': graph[i][j] = 1; end = {i,j}; break;
    
                default: break;
            }
        }
    }

    // print_graph(graph, n, m);

    std::cout << dijkstra(graph, n, m, begin, end) << std::endl;

    return 0;
}
