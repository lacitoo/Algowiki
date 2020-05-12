#include <iostream>
#include <vector>
#include <queue>
#include <stack>
 
struct Node {
  std::vector<int> neighbors;
  int parent;
  bool chk;
};
 
int main() {
  int node_count, edge_count, root_node;
  std::cin >> node_count >> edge_count >> root_node;
 
  struct Node nodes[10001];
 
  for(int i = 0; i < edge_count; i++) {
    int a, b;
    std::cin >> a >> b;
    nodes[a].neighbors.push_back(b);
    nodes[b].neighbors.push_back(a);
  }
 
  nodes[root_node].parent = root_node;
 
  std::queue<int> q;
  q.push(root_node);
 
  while(!q.empty()) {
 
    int node_id = q.front();
    q.pop();
 
    struct Node &node = nodes[node_id];
   
    for(int n : node.neighbors) {
 
      if(n == node.parent) continue;
 
      struct Node &neighbor = nodes[n];
 
      if(neighbor.parent > 0) {
 
          std::queue<int> a;
          std::stack<int> b;
 
          int curr = n;
          while(curr != root_node) {
            a.push(curr);
            nodes[curr].chk = true;
            curr = nodes[curr].parent;
          }
 
          bool valid = true;
 
          curr = node_id;
          while(curr != root_node) {
            b.push(curr);
            if(nodes[curr].chk) {
              valid = false;
              break;
            }
            curr = nodes[curr].parent;
          }
 
          if(valid) {
 
            std::cout << (a.size() + b.size() + 1) << '\n' << root_node << ' ';
            while(!b.empty()) {
              int i = b.top();
              b.pop();
              std::cout << i << ' ';
            }
            while(!a.empty()) {
              int i = a.front();
              a.pop();
              std::cout << i << ' ';
            }
            std::cout << std::endl;
 
            return 0;
           
          } else {
            while(!a.empty()) {
              int i = a.front();
              a.pop();
              nodes[i].chk = false;
            }
          }
 
      } else {
        neighbor.parent = node_id;
        q.push(n);
      }
    }
  }
 
  std::cout << "-1" << std::endl;
 
  return 0;
}
