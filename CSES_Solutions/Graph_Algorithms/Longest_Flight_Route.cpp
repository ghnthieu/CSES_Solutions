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
const int N = (int) 1e5 + 7;
 
/*-----------------------------------------------------------------------------------------------------------------*/
 
int n, m, duong[N], par[N];
vec(int) inp[N], stopo;
bool vit[N];
 
void dfs(int u) {
    vit[u] = true;
    for (int v : inp[u]) if (!vit[v])
        dfs(v);
    stopo.pub(u);
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
    Rep(edge, m)  {
        int u, v; cin >> u >> v;
        inp[v].pub(u);
    }
 
    For(i, 1, n, 1) if (!vit[i])
        dfs(i);
 
    vec(int) tmp; int idx = 0; bool check = false;
    while (idx < stopo.size()) {
        if (!check) {
            if (stopo[idx] == 1) {
                check = true;
                tmp.pub(1);
            }
        }
        else
            tmp.pub(stopo[idx]);
        ++idx;
    }
 
    duong[1] = 1; par[1] = 0;
    for (int u : tmp) for (int v : inp[u]) if (duong[v] && maximize(duong[u], duong[v] + 1))
        par[u] = v;
 
    if (duong[n] == 0) { cout << "IMPOSSIBLE"; return 0; }
    idx = n; vec(int) ans;
    while (idx != 0) {
        ans.pub(idx);
        idx = par[idx];
    }
    reverse(all(ans));
    cout << ans.size() << '\n';
    for (int x : ans) cout << x << " ";
 
    return 0;
}