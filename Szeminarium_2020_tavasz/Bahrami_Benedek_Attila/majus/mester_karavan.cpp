#include <iostream>
#include <vector>
#include <algorithm>

void DFS_order(const int start, const std::vector<std::vector<int>>& graph, std::vector<bool>& visited, std::vector<int>& order)
{
    visited[start] = true;
    for (int v : graph[start])
    {
        if (!visited[v])
        {
            DFS_order(v, graph, visited, order);
        }
        
    }
    order.push_back(start);
}

void DFS(const int start, const std::vector<std::vector<int>>& graph, std::vector<bool>& visited)
{
    visited[start] = true;
    for (int v : graph[start])
    {
        if (!visited[v])
        {
            DFS(v, graph, visited);
        }
        
    }
}

int main()
{
    int n, m;
    std::cin >> n >> m;
    
    std::vector<std::vector<int>> graph(n);
    std::vector<std::vector<int>> graph_transposed(n);
    std::vector<bool> visited(n, false);
    std::vector<int> order;

    for (int i = 0; i < m; i++)
    {
        int a, b;
        std::cin >> a >> b;
        graph[a - 1].push_back(b - 1);
        graph_transposed[b - 1].push_back(a - 1);
    }
    
    for (size_t i = 0; i < graph.size(); i++)
    {
        if (!visited[i])
        {
            DFS_order(i, graph, visited, order);
        }
    }
    visited.assign(n, false);
    DFS_order(order.back(), graph, visited, order);

    if (std::count(visited.begin(), visited.end(), false) != 0)
    {
        std::cout << -1;
    }
    else
    {
        visited.assign(n, false);
        DFS(order.back(), graph_transposed, visited);
        for (size_t i = 0; i < visited.size(); i++)
        {
            if (visited[i])
            {
                std::cout << i + 1 << " ";
            }
        }
    }    
}