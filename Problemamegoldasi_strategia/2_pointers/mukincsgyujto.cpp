#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n, p;
    cin >> n >> p;

    vector< pair<int, int> > xs;
    for(int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        pair<int, int> tmp2;
        tmp2.first = tmp;
        tmp2.second = i;
        xs.push_back(tmp2);
    }

    std::sort(xs.begin(), xs.end(), [](pair<int, int> &left, pair<int, int> &right) {
        return left.first > right.first;
    });

    int i = 0;
    int j = xs.size()-1;

    bool prev = false;
    bool found = false;
    while(i != j)
    {
        if(xs[i].first + xs[j].first == p) {
            cout << (xs[j].second + 1) << " " << (xs[i].second + 1) << endl;
            found = true;
            break;
        }
        else if(xs[i].first + xs[j].first > p) i++;
        else j--;
    }

    if(!found) cout << -1 << endl;

    return 0;
}