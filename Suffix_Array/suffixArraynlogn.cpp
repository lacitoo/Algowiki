#include <vector>
#include <string>
#include <iostream>

using std::vector;
using std::string;
using std::pair;
using std::max;

vector<int> sort_cyclic_shifts(string const& s) {
    int n = s.size();

    // kell a szamlalo rendezeshez
    const int alphabet = 256;

    // a vektorok: maga a szuffixtomb, a c tomb, es a szamlalo rendezes tomb
    vector<int> suffixArray(n), rank(n), cnt(max(alphabet, n), 0);

    // SZAMLALO RENDEZES
    // Mennyi van egy karakterbol
    for (int i = 0; i < n; i++)
        cnt[s[i]]++;
    // Az i. helyen az lesz mennyi van az i. megelozo karakterekbol + az i.-bol osszesen.
    // Ezzel meghatarozzuk azt, hogy az utolso ilyen karakternek hanyadiknak kell lennie a suffixArray tombben.
    for (int i = 1; i < alphabet; i++)
        cnt[i] += cnt[i-1];
    // Minden karakterfajtarol tudjuk hol kell lennie az utolsonak suffixArrayben, szoval ha talalunk egyet akkor
    // eggyel csokkentjuk azt a szamot, es oda kell mennie a kovetkezonek. Szoval berakjuk sorrendben a
    // suffixArraybe a karaktereket.
    for (int i = 0; i < n; i++)
        suffixArray[--cnt[s[i]]] = i;

    // Ekvivalenciaosztalyok meghatarozasa az alapjan, hogy mar rendezett a suffixArray
    rank[suffixArray[0]] = 0;
    int classes = 1;
    for (int i = 1; i < n; i++) {
        if (s[suffixArray[i]] != s[suffixArray[i-1]]) classes++;
        rank[suffixArray[i]] = classes - 1;
    }

    vector<int> newSuffixArray(n), newRank(n);
    // A k valtozo a dokumentacioban. (1 << step) == 2 ^ step
    for (int step = 0; (1 << step) < n; ++step) {
        // A masodik komponenseket sima kivonassal lehet "rednezni"
        for (int i = 0; i < n; i++) {
            newSuffixArray[i] = suffixArray[i] - (1 << step);
            if (newSuffixArray[i] < 0) newSuffixArray[i] += n;
        }

        // SZAMLALO RENDEZES az elso komponensekre
        // Felkeszules a szamlalo rendezesre
        fill(cnt.begin(), cnt.begin() + classes, 0);
        // Hany darab van beloluk
        for (int i = 0; i < n; i++)
            cnt[rank[newSuffixArray[i]]]++;
        // Itt ugyanaz a logika mint az elso szamlalo rendezesben
        for (int i = 1; i < classes; i++)
            cnt[i] += cnt[i-1];
        for (int i = n-1; i >= 0; i--)
            suffixArray[--cnt[rank[newSuffixArray[i]]]] = newSuffixArray[i];

        // Ekvivalenciaosztalyok meghatarozasa az alapjan, hogy a suffixArray mar rendezett.
        newRank[suffixArray[0]] = 0;
        classes = 1;
        for (int i = 1; i < n; i++) {
            // A parok amiket rendeztunk
            pair<int, int> cur = {rank[suffixArray[i]], rank[(suffixArray[i] + (1 << step)) % n]};
            pair<int, int> prev = {rank[suffixArray[i-1]], rank[(suffixArray[i-1] + (1 << step)) % n]};

            // Uj sztring kovetkezik -> eggyel nagyobb ekvivalenciaosztaly
            if (cur != prev) ++classes;
            newRank[suffixArray[i]] = classes - 1;
        }
        rank.swap(newRank);
    }

    return suffixArray;
}

vector<int> suffix_array_construction(string s) {
    // A vegere rakjuk a $ karakterunket
    s += "$";
    vector<int> sorted_shifts = sort_cyclic_shifts(s);
    // Az elso biztosan $ lesz, igy az torolheto
    sorted_shifts.erase(sorted_shifts.begin());
    return sorted_shifts;
}

int main() {
    string s = "abbacd";

    auto vec = suffix_array_construction(s);

    for (int i : vec) {
        std::cout << i << std::endl;
    }
}
