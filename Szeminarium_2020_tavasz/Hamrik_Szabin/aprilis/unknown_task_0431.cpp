#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

void traverse(int current, std::vector<int> neighbors[], std::vector<int> hops[], bool visited[], std::vector<int> &path) {

  path.push_back(current);
  visited[current] = true;

  bool visitHappened = false;
  for(int neighbor : neighbors[current]) {

    std::vector<int> &ha = hops[current];
    std::vector<int> &hb = hops[neighbor];

    std::vector<int>::iterator hfa = std::find(ha.begin(), ha.end(), current);
    std::vector<int>::iterator hfb = std::find(hb.begin(), hb.end(), current);

    if(hfa == ha.end() && hfb == hb.end()) {
      visitHappened = true;
      ha.push_back(neighbor);
      hb.push_back(current);
      traverse(neighbor, neighbors, hops, visited, path);
    }
  }

  if(visitHappened) {
    path.push_back(current);
  }
}

int main() {
  int node_count, edge_count;
  std::cin >> node_count >> edge_count;

  bool visited[100];
  std::vector<int> neighbors[100];
  std::vector<int> hops[100];

  for(int i = 0; i < edge_count; i++) {
    int a, b;
    std::cin >> a >> b;
    neighbors[a].push_back(b);
    neighbors[b].push_back(a);
  }

  std::vector<int> path;
  traverse(1, neighbors, hops, visited, path);

  for(int i = 0; i < path.size(); i++) {
    std::cout << path[i] << ' ';
  }

  return 0;
}
