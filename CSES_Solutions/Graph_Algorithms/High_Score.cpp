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
const ll INF = (ll) 1e14 + 7;
const int N = (int) 1e6 + 7;
 
/*---------------------------------------------------------------*/
 
int n, m, cnt[N];
vec(int) tinp[N];
vii(int, int) inp[N];
bool check[N], infi[N];
ll duong[N];
 
void FordBellman(int s) {
    memset(duong, 0x3f, (n + 1) * sizeof(ll)); duong[s] = 0;
    memset(check, false, (n + 1) * sizeof(bool)); check[s] = true;
    queue <int> qu; qu.push(s);
 
    while (!qu.empty()) {
        int u = qu.front(); qu.pop(); ++cnt[u]; check[u] = false;
        if (cnt[n] > n) {
            cout << -1;
            return;
        }
        for (ii(int, int) v : inp[u]) if (minimize(duong[v.fi], duong[u] + v.se) && !check[v.fi]) {
            if (cnt[v.fi] > 2 * n) {
                infi[v.fi] = true;
                continue;
            }
            qu.push(v.fi);
            check[v.fi] = true;
        }
    }
 
    for (int u : tinp[n]) {
        if (infi[u]) {
            cout << -1;
            return;
        }
        for (int v : tinp[u]) {
            if (infi[v]) {
                cout << -1;
                return;
            }
        }
    }
    if (infi[n]) {
        cout << -1;
        return;
    }
 
    cout << -duong[n];
}
 
__Trung_Hieu___ {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    //freopen(".inp", "r", stdin);
    //freopen(".out", "w", stdout);
    //freopen("Input.txt", "r", stdin);
    //freopen("Output.txt", "w", stdout);
    //freopen("TEST.inp", "r", stdin);
    //freopen("TEST.out", "w", stdout);
 
    cin >> n >> m;
    Rep(new_edge, m) {
        int u, v, w; cin >> u >> v >> w;
        inp[u].pub({v, -w});
        tinp[v].pub(u);
    }
 
    FordBellman(1);
 
    return 0;
}