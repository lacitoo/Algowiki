#include <iostream>
#include <queue>
#include <vector>
 
 
// EZ A PRÓBÁLKOZÁS NEM_MŰKÖDIK
// ROSSZ_STRATÉGIA
 
struct Node
{
    bool is_visited = false;
    bool store = false;
};
 
 
void BFS_store(std::vector<std::vector<int>>& graph, std::vector<Node>& visited, std::queue<int>& posqueue, std::queue<int> negqueue, int start)
{
    visited[start].is_visited = true;
    if (visited[start].store)
    {
        for (int v : graph[start])
        {
            if (!visited[v].is_visited)
            {
                visited[v].is_visited = true;
                negqueue.push(v);
            }
        }
 
    }
    else
    {
        for (int v : graph[start])
        {
            if (!visited[v].is_visited)
            {
                visited[v].is_visited = true;
                posqueue.push(v);
                visited[v].store = true;
            }
        }
    }
    if (negqueue.size() > 0)
    {
        int index = negqueue.front();
        negqueue.pop();
        BFS_store(graph, visited, posqueue, negqueue, index);
    }
    else if (posqueue.size() > 0)
    {
        int index = posqueue.front();
        posqueue.pop();
        BFS_store(graph, visited, posqueue, negqueue, index);
    }
}
 
 
int main()
{
 
    int n;
    std::cin >> n;
    std::vector<std::vector<int>> graph(n);
    std::vector<Node> visited(n);
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        std::cin >> a >> b;
        graph[a - 1].push_back(b - 1);
        graph[b - 1].push_back(a - 1);
    }
    visited[0].store = true;
    std::queue<int> posqueue;
    std::queue<int> negqueue;
    BFS_store(graph, visited, posqueue, negqueue, 0);
 
    std::vector<int> store1, store2;
    for (size_t i = 0; i < visited.size(); i++)
    {
        if (visited[i].store)
        {
            store1.push_back(i + 1);
        }
        else
        {
            store2.push_back(i + 1);
        }
    }
    if (store1.size() > store2.size())
    {
        std::cout << store1.size() << std::endl;
        std::cout << store1[0];
        for (size_t i = 1; i < store1.size(); i++)
        {
            std::cout << " " << store1[i];
        }
    }
    else
    {
        std::cout << store2.size() << std::endl;
        std::cout << store2[0];
        for (size_t i = 1; i < store2.size(); i++)
        {
            std::cout << " " << store2[i];
        }
    }
}