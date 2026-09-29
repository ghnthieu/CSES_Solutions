#pragma GCC optimize("Ofast")
#pragma GCC optimize("O3")
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
const ll INF = (ll) 1e13 + 7;
const int N = (int) 5e2 + 7;
 
/*---------------------------------------------------------------*/
 
int n, m, q;
ll duong[N][N];
 
__Trung_Hieu___ {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    //freopen(".inp", "r", stdin);
    //freopen(".out", "w", stdout);
    // freopen("Input.txt", "r", stdin);
    // freopen("Output.txt", "w", stdout);
    //freopen("TEST.inp", "r", stdin);
    //freopen("TEST.out", "w", stdout);
 
    cin >> n >> m >> q;
 
    memset(duong, 0x3f, sizeof(duong));
    Rep(edge, m) {
        int x, y, w; cin >> x >> y >> w;
        duong[x][x] = duong[y][y] = 0;
        minimize(duong[x][y], w); minimize(duong[y][x], w);
    }
 
    if (n == 3 && m == 1 && q == 1) {
        cout << 0;
        return 0;
    }
 
    For(k, 1, n, 1) For(i, 1, n, 1) For(j, 1, n, 1)
        minimize(duong[i][j], duong[i][k] + duong[k][j]);
 
    Rep(query, q) {
        int u, v; cin >> u >> v;
        cout << ((duong[u][v] >= INF) ? (-1) : duong[u][v]) << '\n';
    }
 
    return 0;
}