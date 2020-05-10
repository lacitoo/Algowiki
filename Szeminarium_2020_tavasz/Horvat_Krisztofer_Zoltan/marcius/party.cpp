//https://codeforces.com/problemset/problem/115/A
#include <iostream>
#include <vector>
#include <queue>

//#define DEBUG_MODE;

using namespace std;


struct Employee {
    Employee(int _ind) : ind(_ind) {}

    int ind, parent = -1;
    vector<int> children;
};

class Party
{
public:
    Party(int _n) : n(_n) {
        for (int i = 0; i < n; ++i) {
            Employee emp(i);
            v.push_back(emp);
        }
    }

    void addEdge(int parent, int child) {
        v[parent].children.push_back(child);
        v[child].parent = parent;
    }

    void addRoot(int ind) {
        roots.push_back(ind);
    }

    int solution() {
        for (int root : roots) {
            dfs(root, 1);
        }
        return max;
    }
private:
    int n, max = 0;
    vector<Employee> v;
    vector<int> roots;

    void dfs(int from, int level) {
        max = level > max ? level : max;
        for (int to : v[from].children) {
            dfs(to, level + 1);
        }
    }
};



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    Party p(n);
    for (int i = 0; i < n; ++i) {
        int parent;
        cin >> parent;
        if (parent != -1) {
            p.addEdge(parent - 1, i);
        } else {
            p.addRoot(i);
        }
    }

    cout << p.solution() << endl;

    return 0;
}