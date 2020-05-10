#include <iostream>
#include <vector>

using namespace std;

int eredm, mx;
vector<bool> lehet;
vector<int> ciml;

void keres(int ossz) {
    lehet[ossz] = true;
    eredm--;
    for (int c : ciml)
        if (ossz + c <= mx && !lehet[ossz + c])
            keres(ossz + c);
}

int main() {
    int db;
    cin >> db >> mx;
    ciml.resize(db);
    lehet.resize(mx + 1, false);

    for (auto &&c : ciml)
        cin >> c;

    eredm = mx + 1;
    keres(0);

    cout << eredm << endl;
    for (int i = 1; i <= mx; i++)
        if (!lehet[i])
            cout << i << " ";

    cout << endl;
    
    return 0;
}