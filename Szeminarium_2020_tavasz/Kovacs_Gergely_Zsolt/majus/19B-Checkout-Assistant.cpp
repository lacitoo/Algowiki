#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, a, b;
    unsigned long long minjo = -1, sumsec = 0;
    cin >> n;
    vector<pair<int, unsigned long long>> items(n);

    for (auto &&i : items) {
        cin >> i.first >> i.second;
        sumsec += i.first;
    }

    vector<unsigned long long> *DP1 = new vector<unsigned long long>(n + sumsec + 1, -1), *DP2 = new vector<unsigned long long>(n + sumsec + 1, -1), *temp;

    (*DP1)[n - 1] = 0;
    (*DP1)[n + items[0].first] = items[0].second;

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < n + sumsec + 1; j++) {
            if (j + 1 == n + sumsec + 1) {
                if ((*DP1)[j - items[i].first] < (unsigned long long)-1)
                    (*DP2)[j] = (*DP1)[j - items[i].first] + items[i].second;
            } else if (j - items[i].first < 0 || (*DP1)[j - items[i].first] == (unsigned long long)-1) {
                (*DP2)[j] = (*DP1)[j + 1];
            } else {
                (*DP2)[j] = min((*DP1)[j + 1], (*DP1)[j - items[i].first] + items[i].second);
            }
        }
        // swap(DP1, DP2);
        temp = DP1;
        DP1 = DP2;
        DP2 = temp;
    }

    cout << *min_element((*DP1).begin() + n, (*DP1).end()) << endl;

    return 0;
}