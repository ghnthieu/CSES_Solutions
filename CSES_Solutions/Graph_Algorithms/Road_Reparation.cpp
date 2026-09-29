#include <bits/stdc++.h>
using namespace std;
 
#define fi first
#define se second
#define pb pop_back
#define pub push_back
#define __Trung_Hieu___ signed main()
#define mask(i) (1LL << (i))
#define bit(n, i) (((n) >> (i)) & 1)
#define all(v) v.begin(), v.end()
#define vec(kdl) vector <kdl>
#define ii(kdl1, kdl2) pair <kdl1, kdl2>
#define vii(kdl1, kdl2) vector <pair <kdl1, kdl2>>
#define For(i, l, r, up) for (int i = (l), _r = (r); i <= _r; i += up)
#define Ford(i, r, l, dw) for (int i = (r), _l = (l); i >= _l; i -= dw)
#define Rep(i, n) for (int i = 0, _n = (n); i < _n; ++i)
template <typename T1, typename T2> bool minimize(T1 &a, T2 b) { if (a > b) { a = b; return true; } return false; }
template <typename T1, typename T2> bool maximize(T1 &a, T2 b) { if (a < b) { a = b; return true; } return false; }
 
typedef long long ll;
typedef unsigned long long ull;
const int MOD = (int) 1e9 + 7;
const int N = (int) 1e6 + 7;
 
/*---------------------------------------------------------------*/
 
struct Edge {
    int u, v, w;
};
 
struct Dsu {
    vec(int) par;
 
    void init(int n) {
        par.resize(n + 5, 0);
        For(i, 1, n, 1) par[i] = i;
    }
 
    int find_par(int u) {
        if (u == par[u]) return u;
        return (par[u] = find_par(par[u]));
    }
 
    bool add_par(int u, int v) {
        u = find_par(u); v = find_par(v);
        if (u == v) return false;
        par[v] = u; return true;
    }
 
} dsu;
 
int n, m;
vec(Edge) edge;
 
bool cmp(Edge x, Edge y) {
    return (x.w < y.w);
}
 
__Trung_Hieu___ {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    //freopen(".inp", "r", stdin);
    //freopen(".out", "w", stdout);
    // freopen("Input.txt", "r", stdin);
    // freopen("Output.txt", "w", stdout);
    //freopen("TEST.inp", "r", stdin);
    //freopen("TEST.out", "w", stdout);
 
    cin >> n >> m;
    Rep(new_edge, m) {
        int u, v, w; cin >> u >> v >> w;
        edge.pub(Edge{u, v, w});
    }
 
    sort(all(edge), cmp); ll ans = 0; dsu.init(n);
    for (Edge x : edge) if (dsu.add_par(x.u, x.v)) {
        ans += x.w; --n;
    }
 
    if (n == 1)
        cout << ans;
    else
        cout << "IMPOSSIBLE";
 
    return 0;
}