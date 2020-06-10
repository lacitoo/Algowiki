    #include <iostream>
    #include <vector>
    #include <stack>
     
    int main() {
      int employees;
      std::cin >> employees;
     
      std::vector<int> children[2000];
      int parent[2000];
      int dist[2000];
     
      for(int i = 0; i < employees; i++) {
        int a;
        std::cin >> a;
        if(a > 0) a--;
        parent[i] = a >= 0 ? a : i; 
        dist[i] = 0;
        if(a >= 0) children[a].push_back(i);
      }
     
      int max_depth = 0;
      std::stack<int> s;
     
      for(int i = 0; i < employees; i++) {
        if(parent[i] == i) {
     
          int depth = 0;
          s.push(i);
     
          while(!s.empty()) {
            int c = s.top();
            s.pop();
     
            dist[c] = dist[parent[c]] + 1;
            if(dist[c] > depth) {
              depth = dist[c];
            }
     
            for(int n : children[c]) {
              s.push(n);
            }
          }
     
          if(depth > max_depth) {
            max_depth = depth;
          }
     
        }
      }
     
      std::cout << max_depth << std::endl;
    }
