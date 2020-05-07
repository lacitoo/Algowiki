#include <atomic>
#include <bits/stdc++.h>
using namespace std;
 
 
vector<string> split_string(string);
 
 
enum direction : char
{
    none,
    horizontal,
    vertical,
    diagonal,
};
 
struct step
{
    size_t length;
    direction dir;
};
 
vector<int> longestCommonSubsequence(vector<int> a, vector<int> b)
{
    step** T = new step*[a.size() + 1];
    for (size_t y = 0; y <= a.size(); ++y)
    {
        T[y] = new step[b.size() + 1];
        for (size_t x = 0; x <= b.size(); ++x)
            T[y][x] = { 0, direction::none };
    }
 
    for (size_t y = a.size() - 1; y < a.size(); --y)
    {
        for (size_t x = b.size() - 1; x < b.size(); --x)
        {
            size_t hor = x + 1;
            size_t ver = y + 1;
            if (a[y] == b[x])
            {
                T[y][x].length = 1 + T[ver][hor].length;
                T[y][x].dir = direction::diagonal;
            }
            else
            {
                if (T[ver][x].length > T[y][hor].length)
                {
                    T[y][x].length = T[ver][x].length;
                    T[y][x].dir = direction::vertical;
                }
                else
                {
                    T[y][x].length = T[y][hor].length;
                    T[y][x].dir = direction::horizontal;
                }
            }
        }
    }
 
    vector<int> v;
    size_t y = 0;
    size_t x = 0;
    while (y < a.size() && x < b.size())
    {
        switch (T[y][x].dir)
        {
        case direction::none:
            // shouldn't be a problem (never enters here)
            break;
        case direction::horizontal:
            ++x;
            break;
        case direction::vertical:
            ++y;
            break;
        case direction::diagonal:
            v.push_back(a[y]);
            ++y; ++x;
            break;
        }
    }
    return v;
}
 
int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));
 
    string nm_temp;
    getline(cin, nm_temp);
 
    vector<string> nm = split_string(nm_temp);
 
    int n = stoi(nm[0]);
 
    int m = stoi(nm[1]);
 
    string a_temp_temp;
    getline(cin, a_temp_temp);
 
    vector<string> a_temp = split_string(a_temp_temp);
 
    vector<int> a(n);
 
    for (int i = 0; i < n; i++) {
        int a_item = stoi(a_temp[i]);
 
        a[i] = a_item;
    }
 
    string b_temp_temp;
    getline(cin, b_temp_temp);
 
    vector<string> b_temp = split_string(b_temp_temp);
 
    vector<int> b(m);
 
    for (int i = 0; i < m; i++) {
        int b_item = stoi(b_temp[i]);
 
        b[i] = b_item;
    }
 
    vector<int> result = longestCommonSubsequence(a, b);
 
    for (int i = 0; i < result.size(); i++) {
        fout << result[i];
 
        if (i != result.size() - 1) {
            fout << " ";
        }
    }
 
    fout << "\n";
 
    fout.close();
 
    return 0;
}
 
vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });
 
    input_string.erase(new_end, input_string.end());
 
    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }
 
    vector<string> splits;
    char delimiter = ' ';
 
    size_t i = 0;
    size_t pos = input_string.find(delimiter);
 
    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));
 
        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }
 
    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));
 
    return splits;
}
