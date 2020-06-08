#include <iostream>
#include <vector>
#include <algorithm>

void melysegiSorrend(const int start, const std::vector<std::vector<int>>& gr�f, std::vector<bool>& volt, std::vector<int>& sorrend);
void melysegi(const int start, const std::vector<std::vector<int>>& gr�f, std::vector<bool>& volt);

int main()
{
    int n, m;
    std::cin >> n >> m;

    std::vector<std::vector<int>> gr�f(n);
    std::vector<std::vector<int>> forditott(n);
    std::vector<bool> volt(n, false);
    std::vector<int> sorrend;

    for (int i = 0; i < m; i++)
    {
        int a, b;
        std::cin >> a >> b;
        gr�f[a - 1].push_back(b - 1);
        forditott[b - 1].push_back(a - 1);
    }

    for (int i = 0; i < gr�f.size(); i++)
    {
        if (!volt[i])   melysegiSorrend(i, gr�f, volt, sorrend);      
    }
    volt.assign(n, false);
    melysegiSorrend(sorrend.back(), gr�f, volt, sorrend);

    if (std::count(volt.begin(), volt.end(), false) != 0)   std::cout << -1;    
    else
    {
        volt.assign(n, false);
        melysegi(sorrend.back(), forditott, volt);
        for (int i = 0; i < volt.size(); i++)
        {
            if (volt[i])    std::cout << i + 1 << " ";
        }
    }
}

void melysegi(const int start, const std::vector<std::vector<int>>& gr�f, std::vector<bool>& volt)
{
    volt.at(start) = true;
    for (auto x : gr�f.at(start))
    {
        if (!volt.at(x))    melysegi(x, gr�f, volt);
    }
}

void melysegiSorrend(const int start, const std::vector<std::vector<int>>& gr�f, std::vector<bool>& volt, std::vector<int>& sorrend)
{
    volt.at(start) = true;
    for (auto x : gr�f.at(start))
    {
        if (!volt.at(x))    melysegiSorrend(x, gr�f, volt, sorrend);
    }
    sorrend.push_back(start);
}