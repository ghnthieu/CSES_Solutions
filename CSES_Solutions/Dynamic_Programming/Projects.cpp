#include <bits/stdc++.h>
using namespace std;
 
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
#define all(v) v.begin(), v.end()
#define rall(v, kdl) v.begin(), v.end(), greater <kdl> ()
#define vec(kdl) vector <kdl>
#define ii(kdl1, kdl2) pair <kdl1, kdl2>
#define vii(kdl1, kdl2) vector <pair <kdl1, kdl2>>
#define iii(kdl1, kdl2, kdl3) pair <pair <kdl1, kdl2>, kdl3>
#define viii(kdl1, kdl2, kdl3) vector <pair <pair <kdl1, kdl2>, kdl3>>
#define For(i, l, r, up) for (int i = (l), _r = (r); i <= _r; i += up)
#define Ford(i, r, l, dw) for (int i = (r), _l = (l); i >= _l; i -= dw)
#define Rep(i, n) for (int i = 0, _n = (n); i < _n; ++i)
template <typename T1, typename T2> bool minimize(T1 &a, T2 b) { if (a > b) { a = b; return true; } return false; }
template <typename T1, typename T2> bool maximize(T1 &a, T2 b) { if (a < b) { a = b; return true; } return false; }
 
typedef long long ll;
typedef unsigned long long ull;
const int MOD = (int) 1e9 + 7;
const int N = (int) 3e5 + 7;
 
/*-----------------------------------------------------------------------------------------------------------------*/
 
int n;
iii(int, int, int) a[N];
ll dp[N], ans[N];
 
int cnp(int l, int r, int val) {
    int res = 0;
    while (l <= r) {
        int m = l + r >> 1;
        if (a[m].fi.fi <= val) {
            res = m;
            l = m + 1;
        }
        else
            r = m - 1;
    }
    return res;
}
 
__Trung_Hieu___ {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen(".inp", "r", stdin);
    //freopen(".out", "w", stdout);
    // freopen("Input.txt", "r", stdin);
    // freopen("Output.txt", "w", stdout);
    //freopen("TEST.inp", "r", stdin);
    //freopen("TEST.out", "w", stdout);
 
    cin >> n;
    For(i, 1, n, 1) cin >> a[i].fi.se >> a[i].fi.fi >> a[i].se;
    sort(a + 1, a + n + 1);
    For(i, 1, n, 1) {
        int x = a[i].fi.se, y = a[i].fi.fi, z = a[i].se;
        int idx = cnp(1, i - 1, x - 1);
        dp[i] = ans[idx] + z;
        ans[i] = max(ans[i - 1], dp[i]);
    }
    cout << ans[n];
 
    cerr << "Time elapsed: " << TIME << " s." << '\n';
    return 0;
}