#include <bits/stdc++.h>
using namespace std;
 
#define NAME ""
#define fi first
#define se second
#define bk back
#define fr front
#define pb pop_back
#define pf pop_front
#define pub push_back
#define puf push_front
#define __Trung_Hieu___ signed main()
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define mask(i) (1LL << (i))
#define bit(n, i) (((n) >> (i)) & 1)
#define vec(kdl) vector <kdl>
#define all(v) v.begin(), v.end()
#define rall(v, kdl) v.begin(), v.end(), greater <kdl> ()
#define ii(kdl1, kdl2) pair <kdl1,kdl2>
#define vii(kdl1, kdl2) vector <pair <kdl1,kdl2>>
#define iii(kdl1, kdl2, kdl3) pair <pair <kdl1,kdl2>,kdl3>
#define viii(kdl1, kdl2, kdl3) vector <pair <pair <kdl1,kdl2>,kdl3>>
template <typename T1, typename T2> bool minimize(T1 &a, T2 b) { if (a > b) { a = b; return true; } return false; }
template <typename T1, typename T2> bool maximize(T1 &a, T2 b) { if (a < b) { a = b; return true; } return false; }
 
typedef long long ll;
typedef unsigned long long ull;
const int MOD = (int) 1e9 + 7;
const int N = (int) 2e5 + 7;
 
int n;
vec(int) inp[N];
ll dp[N], ans[N];
 
void dfs1(int u, int par, ll tmp) {
    ans[1] += tmp;
    dp[u] = 1;
    for (int v : inp[u]) {
        if (v != par) {
            dfs1(v, u, tmp + 1);
            dp[u] += dp[v];
        }
    }
}
 
void dfs2(int u, int par) {
    for (int v : inp[u]) {
        if (v != par) {
            ans[v] = ans[u] + n - 2 * dp[v];
            dfs2(v, u);
        }
    }
}
 
void solve(void) {
    dfs1(1, 0, 0);
    dfs2(1, 0);
    for (int i=1; i<=n; ++i)
        cout << ans[i] << " ";
}
 
__Trung_Hieu___ {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    //freopen(NAME".INP", "r", stdin);
    //freopen(NAME".OUT", "w", stdout);
 
    cin >> n;
    for (int i=1; i<n; ++i) {
        int x, y; cin >> x >> y;
        inp[x].pub(y);
        inp[y].pub(x);
    }
 
    solve();
 
    cerr << "Time elapsed: " << TIME << " s." << '\n';
    return (0 ^ 0);
}