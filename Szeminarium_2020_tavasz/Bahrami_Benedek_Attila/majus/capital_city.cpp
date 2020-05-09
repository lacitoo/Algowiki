#include <iostream>
#include <vector>
#include <algorithm>
 
void DFS(int start, std::vector<std::vector<int>>& graph, std::vector<bool>& visited)
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
    std::vector<int> ans;
    std::vector<std::vector<int>> graph(n);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        std::cin >> a >> b;
        graph[b - 1].push_back(a - 1);
    }
 
    for (int i = 0; i < n; i++)
    {
        std::vector<bool> visited(n, false);
        DFS(i, graph, visited);
        if (std::count(visited.begin(), visited.end(), false) == 0)
        {
            ans.push_back(i + 1);
        }
    }
 
    std::cout << ans.size() << std::endl;
    for (size_t i = 0; i < ans.size(); i++)
    {
        std::cout << ans[i] << " ";
    }
}