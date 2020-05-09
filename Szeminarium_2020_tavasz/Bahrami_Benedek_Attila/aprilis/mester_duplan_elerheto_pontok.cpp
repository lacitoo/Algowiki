#include <iostream>
#include <vector>
#include <algorithm>
 
void DFS(std::vector<std::vector<int>>& graph, std::vector<bool>& visited, int p)
{
    visited[p] = true;
    for (int v : graph[p])
    {
        if (!visited[v])
        {
            DFS(graph, visited, v);
        }
    }
}
 
 
int main()
{
    int n, m, start;
    std::cin >> n >> m >> start;
    std::vector<std::pair<int, int>> pairs;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        std::cin >> a >> b;
        std::pair<int, int> temp;
        temp.first = a;
        temp.second = b;
        pairs.push_back(temp);
    }
 
    std::vector<bool> missing(n, true);
 
 
    for (size_t i = 0; i < pairs.size(); i++)
    {
        std::vector<std::vector<int>> graph(n);
        std::vector<bool> visited(n);
        for (size_t k = 0; k < pairs.size(); k++)
        {
            if (i != k)
            {
                int a, b;
                a = pairs[k].first;
                b = pairs[k].second;
                graph[a - 1].push_back(b - 1);
                graph[b - 1].push_back(a - 1);
            }
        }
        DFS(graph, visited, start - 1);
        for (size_t k = 0; k < visited.size(); k++)
        {
            if (!visited[k] && missing[k])
            {
                missing[k] = false;
            }
        }
    }
 
    std::cout << std::count(missing.begin(), missing.end(), true) << std::endl;
    for (size_t i = 0; i < missing.size(); i++)
    {
        if (missing[i])
        {
            std::cout << i + 1 << " ";
        }
    }
 
 
 
 
 
 
 
}