#include<iostream>
#include<queue>
#include <vector>

std::vector<int> csapat1;
std::vector<int> csapat2;

std::vector< std::vector<int> > graph;
std::vector<bool> visited;

void bfs(int u);
void out(std::vector<int> va);
bool osszefere(std::vector<int> v ,int a);

int main()
{
    
    int n, m;
    std::cin >> n >> m  ;
    visited.assign(n+1, false);
    graph.assign(n+1, std::vector<int>());
    for (int i = 0; i < m; i++)
    {
        int a, b;
        std::cin >> a >> b;
        graph.at(a).push_back(b);
        graph.at(b).push_back(a);
    }

    for (int i = 1; i < visited.size(); i++)
    {
        if (!visited.at(i))
        {
            bfs(i);
            //std::cout << "\n";
        }
    }

    out(csapat1);
    out(csapat2);
	return 0;
}

void bfs(int u)
{
    std::queue<int> q;
    q.push(u);
    visited.at(u) = true;
    int c=0;
    csapat1.push_back(u);
    while (!q.empty()) {

        int f = q.front();
        q.pop();
        
        //std::cout << f<<" ";

        for (auto i : graph.at(f))
        {
            if (!visited.at(i))
            {
                q.push(i);
                visited.at(i) = true;

                if (c % 2 == 0)
                    csapat2.push_back(i);
                else
                    csapat1.push_back(i);
            }
        }
        c++;
    }
}

void out(std::vector<int> va)
{
    for (auto i : va)
    {
        std::cout << i<<" ";
    }
    std::cout << "\n";
}

bool osszefere(std::vector<int> v, int a)
{

}