#include <iostream>
#include <climits>
#include <vector>
#include <stack>

std::vector<int> neighbors[10001];
std::vector<bool> visited(10001, false);
std::vector<bool> cut(10001, false);

std::vector<int> parent(10001, -1);
std::vector<int> children(10001, 0);

std::vector<int> largest_subtree_size(10001, 1);
std::vector<int> total_subtree_size(10001, 1);

int curr_time = 0;
std::vector<int> disc(10001, 0);
std::vector<int> low(10001, INT_MAX);

void tarjan(int curr) 
{

  disc[curr] = curr_time;
  low[curr] = curr_time;
  visited[curr] = true;

  for(int neighbor : neighbors[curr]) 
  {
    if(parent[curr] == neighbor)
    {
      continue;
    }

    curr_time++;

    if(visited[neighbor])
    {
      // Back-edge found, update highest reachable ancestor

      if(low[curr] > disc[neighbor])
      {
        low[curr] = disc[neighbor];
      }
    }
    else
    {
      // New subtree found, recurse into it

      parent[neighbor] = curr;
      children[curr]++;
      tarjan(neighbor);

      if(largest_subtree_size[curr] < largest_subtree_size[neighbor]) {
        largest_subtree_size[curr] = largest_subtree_size[neighbor];
      }

      total_subtree_size[curr] += total_subtree_size[neighbor];
    }

    if(curr > 1) 
    {
      if(disc[curr] <= low[neighbor])
      {
        // Subtree cannot reach above current vertex.
        // Cut vertex found.
        cut[curr] = true;
      }
      else if(low[curr] > low[neighbor])
      {
        // Subtree can reach above current vertex.
        // Update highest reachable ancestor.
        low[curr] = low[neighbor];
      }
    }
  }

  largest_subtree_size[curr]++;

  if(curr == 1 && children[1] > 1)
  {
    // Root has independent children.
    // Root is cut vertex.
    cut[1] = true;
  }

}

int main() 
{

  // Build graph

  int nodes, edges;
  std::cin >> nodes >> edges;

  for(int e = 0; e < edges; e++) 
  {
    int a, b;
    std::cin >> a >> b;

    neighbors[a].push_back(b);
    neighbors[b].push_back(a);
  }

  // Find articulation points

  tarjan(1);
  
  int best_cut = 0;
  int max_group = INT_MAX;

  for(int i = 1; i <= nodes; i++)
  {
    int largest_below = largest_subtree_size[i] - 1;
    int largest_above = nodes - total_subtree_size[i];

    int largest_group = largest_above > largest_below 
      ? largest_above 
      : largest_below;

    //std::cout << i << " - Largest group above: " << largest_above << std::endl;
    //std::cout << i << " - Largest group below: " << largest_below << std::endl;

    if(!cut[i]) continue;

    if(
      children[i] > children[best_cut] ||
      (
        children[i] == children[best_cut] &&
        largest_group < max_group
      )
    ) {
      best_cut = i;
      max_group = largest_group;
    }
  }

  std::cout << best_cut << std::endl;

  return 0;
}
