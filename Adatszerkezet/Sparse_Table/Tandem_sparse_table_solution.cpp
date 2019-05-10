#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
#define ll long long
#define N 211111

char t[N];
int n;
int sa[N];
int sai[N<<1];
int lcp[N];
ll key[N];

bool comp(int i, int j) {
    return key[i] < key[j];
}

void fill_sai() {
    sort(sa, sa + n, comp);
    sai[sa[0]] = 0;
    for (int i = 1; i < n; i++) {
        sai[sa[i]] = key[sa[i]] == key[sa[i - 1]] ? sai[sa[i - 1]] : i;
    }
}

// sztring eljarasok, megtalalhatoak a Szuffixtombok es LCP tomb odlalon
void get_suffix_array() {
    for (int i = 0; i < n; i++) {
        sa[i] = i;
        sai[i] = sai[i+n] = -1;
        key[i] = t[i];
    }
    fill_sai();
    for (int p = 1; p <= n; p <<= 1) {
        for (int i = 0; i < n; i++) key[i] = sai[i]*(n+1LL) + sai[i + p];
        fill_sai();
    }
}

void get_lcp() {
    int l = 0;
    for (int i = 0; i < n; i++) lcp[i] = 0;
    for (int i = 0; i < n-1; i++) {
        int k = sai[i];
        int j = sa[k - 1];
        while (t[i + l] == t[j + l]) l++;
        lcp[k] = l;
        if (l > 0) l--;
    }
}

int sai1[N];
int lcp1[N];
#define sai2 sai
#define lcp2 lcp

#define INF (1<<30)
int w[N], lg;
struct ST { // segment tree
    int **m;
    ST(int *a, int n) {
        m = new int*[lg];
        m[0] = a;
        for (int v = 1; v < lg; v++) {
            m[v] = new int[n];
            for (int i = 0; i < n; i++) {
                int j = i+(1<<v-1);
                if (j < n) {
                    m[v][i] = min(m[v-1][i], m[v-1][j]);
                } else {
                    m[v][i] = m[v-1][i];
                }
            }
        }
    }

    int gmin(int i, int j) {
        int v = w[j-i];
        return min(m[v][i], m[v][j-(1<<v)]);
    }
};
void init_w() {
    for (lg = 0; 1<<lg <= N; lg++) {
        w[1<<lg] = lg;
    }
    for (int i = 1; i < N; i++) {
        if (w[i] == 0) w[i] = w[i-1];
    }
}

ST *t1, *t2;
void init() {
    t[n++] = '$';
    get_suffix_array();
    get_lcp();
    for (int i = 0; i < n; i++) {
        sai1[i] = sai[i];
        lcp1[i] = lcp[i];
    }
    for (int i = 0, j = n-2; i < j; i++, j--) swap(t[i], t[j]);
    get_suffix_array();
    get_lcp();
    n--;
    init_w();
    t1 = new ST(lcp1 + 1, n);
    t2 = new ST(lcp2 + 1, n);
}

int _lcp(int *sai, ST *t, int i, int j, int k) {
    i = sai[i];
    j = sai[j];
    k = sai[k];
    int I = min(min(i, j), k);
    int J = max(max(i, j), k);
    return t->gmin(I, J);
}

int get_lcp(int i, int j, int k, int l) {
    return min(l, _lcp(sai1, t1, i, j, k));
}

int get_lcs(int i, int j, int k, int l) {
    return min(l, _lcp(sai2, t2, n-1-i, n-1-j, n-1-k));
}

int main() {
    scanf("%s", t);
    n = strlen(t);
    init();
    ll interesting = 0, boring = 0;
    for (int l = 1; l <= n/3; l++) {
        for (int i = 0; i < n-2*l; i += l) {
            int j = i + l;
            int k = j + l;
            int right = get_lcp(i, j, k, l+1);
            int left = get_lcs(i, j, k, l);
            int total = min(right, l) + left - 1;
            if (total >= l) {
                if (right > l) {
                    boring += total - l + 1;
                } else {
                    boring += total - l;
                    interesting++;
                }
            }
        }
    }

    printf("%lld %lld\n", interesting, boring);
}
