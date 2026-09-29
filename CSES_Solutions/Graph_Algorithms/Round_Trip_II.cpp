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
#define vec(kdl) vector<kdl>
#define ii(kdl1, kdl2) pair<kdl1, kdl2>
#define vii(kdl1, kdl2) vector<pair<kdl1, kdl2>>
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
 
int n, m, start, finish, par[N], vit[N];
vec(int) inp[N], ans;
 
void dfs(int u) {
    vit[u] = true;
    for (int v : inp[u]) {
        if (vit[v] == 0) {
            par[v] = u;
            dfs(v);
            if (start) return;
        } else if (vit[v] == 1) {
            finish = u;
            start = v;
            return;
        }
    }
    vit[u] = 2;
}
 
__Trung_Hieu___ {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    //freopen("Input.txt", "r", stdin);
    //freopen("Output.txt", "w", stdout);
 
    cin >> n >> m;
    Rep(edge, m) {
        int u, v; cin >> u >> v;
        inp[u].pub(v);
    }
 
    memset(par, -1, (n + 1) * sizeof(int));
    For(i, 1, n, 1) if (!start && vit[i] == 0)
        dfs(i);
 
    if (!start) {
        cout << "IMPOSSIBLE \n";
        return 0;
    }
 
    ans.pub(start);
    for (int u = finish; u != start; u = par[u])
        ans.pub(u);
    ans.pub(start); reverse(all(ans));
 
    cout << ans.size() << '\n';
    for (int x : ans) cout << x << " ";
 
    return 0;
}