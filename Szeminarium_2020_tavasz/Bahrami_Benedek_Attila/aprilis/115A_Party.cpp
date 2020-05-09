#include <iostream>
#include <vector>
#include <queue>
 
void BFS(const std::vector<std::vector<int>>& graph, std::vector<bool>& visited, const int p, std::queue<int>& queue)
{
	visited[p] = true;
	for (int v : graph[p])
	{
		if (!visited[v])
		{
			visited[v] = true;
			queue.push(v);
		}
	}
	if (queue.size() > 0)
	{
		int index = queue.front();
		queue.pop();
		BFS(graph, visited, index, queue);
	}
}
 
 
 
int DFS_longest(std::vector<std::vector<int>>& graph, std::vector<bool>& visited, int start, int& zero, int& max)
{
	visited[start] = true;
	for (int v : graph[start])
	{
		if (!visited[v])
		{
			zero++;
			DFS_longest(graph, visited, v, zero, max);
		}
	}
	if (max < zero)
	{
		max = zero;
	}
	zero--;
	visited[start] = false;
	return max;
}
 
int main()
{
	int n;
	std::cin >> n;
	std::vector<std::vector<int>> graph(n);
	std::vector<bool> visited(n, false);
	std::vector<int> heads;
	for (int i = 0; i < n; i++)
	{
		int x;
		std::cin >> x;
		if (x != -1)
		{
			graph[x - 1].push_back(i);
		}
		else
		{
			heads.push_back(i);
		}
	}
	int max = 0;
	for (size_t i = 0; i < heads.size(); i++)
	{
		int DFS_max = 0;
		int zero = 0;
		int current = DFS_longest(graph, visited, heads[i], zero, DFS_max);
		if (current > max)
		{
			max = current;
		}
	}
 
	std::cout << max + 1;
	/*
	std::cout << std::endl << std::endl;
	for (size_t i = 0; i < graph.size(); i++)
	{
		for (size_t k = 0; k < graph[i].size(); k++)
		{
			std::cout << graph[i][k] + 1 << " ";
		}
		std::cout << std::endl;
	}
	*/
}