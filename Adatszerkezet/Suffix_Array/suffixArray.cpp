#include <iostream>
#include <vector>
#include <algorithm>

using std::string;
using std::vector;

string s;

vector<int> suffixArray;
vector<int> rank;

void buildSuffixArray() {
    int n = s.size();

    // tombok feltoltese
    suffixArray.assign(n, -1);
    rank.assign(2 * n, -1);
    vector<int> newRank(rank.size(), -1);

    // kezdetleges ertekek adasa, amikor csak 1 hosszuakat nezunk
    for (int i = 0; i < n; i++) {
        suffixArray[i] = i;

        // karakter kodja a kezdetleges rang
        rank[i] = s[i];
    }

    int step;
    // a rendezeshez hasznalatos hasonlito eljaras
    auto cmp = [&step](int a, int b) -> bool {
        // szamjegyes rendezes
        if (rank[a] != rank[b]) return rank[a] < rank[b];
        return rank[a + (1<<step)] < rank[b + (1<<step)];
    };

    // 1 << step == 2^step
    for (step = 0; (1<<step) < n; step++) {
        // lerendezzuk a tombot
        sort(suffixArray.begin(), suffixArray.end(), cmp);

        // melyik rangu osztalynal jarunk jelenleg
        int rankAt = 0;
        newRank[suffixArray[0]] = 0;

        // ha egy uj fajta szuffixet talalunk akkor eggyel magasabb rangot adunk neki
        for (int i = 1; i < n; i++) {
            if (cmp(suffixArray[i-1], suffixArray[i])) rankAt++;
            newRank[suffixArray[i]] = rankAt;
        }
        swap(rank, newRank);
    }
}