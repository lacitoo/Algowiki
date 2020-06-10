#include <iostream>
#include <sstream>
#include <vector>
#include <stack>

class Solution {

private:

  int node_count;
  int edge_count;
  
  std::vector<int> edges[100001];
  bool on_stack[100001] = {};
  int depth[100001] = {};
  int parent[100001] = {};

  int index = 1;
  std::stack<int> stack;

  int scc[100001] = {};
  int curr = 1;

public:
  
  /**
   * This is the important bit.
   *
   * We use Tarjan's algorithm to form a (reverse) topological order of
   * every strongly connected component of the input graph. If there is one, 
   * we ouput "0 0", if there are more, because they are reverse topological 
   * order, we must make an edge from any element
   * of the first group to any element of the last, and output that edge.
   *
   * Sources:
   *  - https://en.wikipedia.org/wiki/Strongly_connected_component
   *  - https://en.wikipedia.org/wiki/Tarjan%27s_strongly_connected_components_algorithm
   */
  void solve(int v) {

    depth[v] = index;
    parent[v] = index;
    index++;

    stack.push(v);
    on_stack[v] = true;

    for(int w : edges[v]) {
      if(parent[w] == 0) {
        solve(w);
        parent[v] = parent[v] < parent[w] ? parent[v] : parent[w];
      } else if(on_stack[w]) {
        parent[v] = parent[v] < depth[w] ? parent[v] : depth[w];
      }
    }

    if(parent[v] == depth[v]) {
      int w;
      do {
        w = stack.top();
        stack.pop();
        scc[w] = curr;
      } while(w != v);
      curr++;
    }
  }

  void solveAll() {
    for(int i = 1; i < node_count; i++) {
      if(depth[i] == 0) {
        //std::cout << "Solving " << i << std::endl;
        index = 1;
        solve(i);
      }
    }
  }

  void read() {
    std::cin >> node_count >> edge_count;

    for(int e = 0; e < edge_count; e++) {
      int from, to;
      std::cin >> from >> to;
      edges[from].push_back(to);
    }
  }

  void write() {

    int a = 0;
    int b = 0;

    if(curr == 2) {
      std::cout << "0 0" << std::endl;
    } else {
      for(int i = 1; i <= node_count; i++) {
        //std::cout << i << " -> SCC " << scc[i] << std::endl;
        if(a == 0 && scc[i] == 1) {
          a = i;
        } else if(b == 0 && scc[i] == curr - 1) {
          b = i;
        }
      }
    }

    std::cout << a << ' ' << b << std::endl;
    
  }
};

int main() {

  Solution s;

  s.read();
  s.solveAll();
  s.write();
  
}
