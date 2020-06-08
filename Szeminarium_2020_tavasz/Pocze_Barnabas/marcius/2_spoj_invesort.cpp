#include <bits/stdc++.h>

static constexpr int MAXN = 10;
static constexpr int MAXNCHOOSE2 = MAXN * (MAXN-1) / 2;



using namespace std;


template<size_t N>
constexpr size_t fact() {
    return N * fact<N-1>();
}

template<>
constexpr size_t fact<0>() {
    return 1;
}


template<size_t IDX = 0, size_t ...D>
struct Helper : Helper<IDX+1, D..., fact<IDX>()> {};

template<size_t ...D>
struct Helper<MAXN, D...> {
    static constexpr array<size_t, MAXN> table = { D... };
};

static constexpr array<size_t, MAXN> f = Helper<>::table;



template<typename T>
using nodearr = array<T, fact<MAXN>()>;

static nodearr<size_t> perms;
static nodearr<array<int, MAXNCHOOSE2>> g;
static nodearr<int> cnt;

static nodearr<int> dst_a, dst_b;
static nodearr<int> inq;
static nodearr<int> que;
static nodearr<bool> populated;

static size_t perm_id_inv(size_t x, size_t i, size_t j) {
    
    int d[MAXN+1], *p = d+MAXN;
    
    size_t x2 = x;
    
    *p = -1;
    
    while (x > 0) {
        *--p = x%10;
        x /= 10;
    }
    
    if (x2 < 1000000000)
        *--p = 0;
    
    while (i < j)
        swap(p[i++], p[j--]);
    
    size_t r = 0;
    
    bool seen[MAXN] = {false};
    
    for (int a = 0; a < MAXN; a++) {
        for (int b = 0; b < p[a]; b++) {
            if (!seen[ b ])
                r += f[MAXN-a-1];
        }
        
        seen[ p[a] ] = true;
    }

    return r;
}


static int bfs(int from, int to, int id, int maxd, nodearr<int> & dst) {
    
    size_t qs = 0, qe = 0;
    
    inq[from] = id;
    dst[from] = 0;
    
    que[qe++] = from;

    while (qs < qe) {
        
        int x = que[qs++];

        if (x == to) break;
        
        if (dst[x] >= maxd)
            continue;
        
        if (!populated[x]) {
            
            for (size_t i = 0; i < MAXN; i++) {
                for (size_t j = i+1; j < MAXN; j++) {
                    g[x][ cnt[x]++ ] = perm_id_inv( perms[x], i, j);
                }
            }
            
            populated[x] = true;
        }
        
        for (int i = 0; i < cnt[x]; i++) {
            
            int y = g[x][i];
            
            
            if (inq[y] != id) {
                dst[y] = dst[x]+1;
                
                if (inq[y] == -id)
                    return y;
                
                inq[y] = id;
                que[qe++] = y;
            }
        
        }
    }
    
    return -1;
}

static size_t to_num(const array<int, MAXN> & v) {
    size_t r = 0;
    for (int x : v)
        r = 10*r + x;
        
    return r;
}

static size_t to_num(const string & s) {
    size_t r = 0;
    for (char c : s)
        r = 10*r + (c - 'a');
    
    return r;
}

int main() {
    
    array<int, MAXN> base {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    
    for (size_t i = 0; ; i++) {

        perms[i] = to_num(base);

        if (!next_permutation(begin(base), end(base)))
            break;
    }
    
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    for (int id = 1; ; id++) {
        
        string a, b;
        
        cin >> a >> b;
        
        if (a == "*" || b == "*")
            break;
        
        int a_id = perm_id_inv(to_num(a), 0, 0);
        int b_id = perm_id_inv(to_num(b), 0, 0);
        
        bfs(a_id, b_id, id, 4, dst_a);
        
        if (inq[b_id] == id) {
            cout << dst_a[b_id];
        }
        else {
            
            int c = bfs(b_id, a_id, -id, 4, dst_b);    
            
            if (c >= 0) {
                cout << dst_a[c] + dst_b[c];
            }
            else
                cout << '9';
            
        }
        
        cout << '\n';
    }
    
    return 0;
}
