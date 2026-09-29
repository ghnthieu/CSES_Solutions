#include <bits/stdc++.h>
using namespace std;
 
#define fi first
#define se second
#define pub push_back
#define pb pop_back
#define mask(i) (1ll << (i))
#define bit(n, i) (((n) >> (i)) & 1)
#define all(v) v.begin(), v.end()
#define vec(kdl) vector <kdl>
#define ii(kdl1, kdl2) pair <kdl1, kdl2>
#define vii(kdl1, kdl2) vector <pair <kdl1, kdl2>>
#define For(i, l, r, up) for (int i = (l), _r = (r); i <= _r; i += up)
#define Ford(i, r, l, dw) for (int i = (r), _l = (l); i >= _l; i -= dw)
#define Rep(i, n) for (int i = 0, _n = (n); i < _n; ++i)
template <typename T1, typename T2> bool maximize(T1 &x, T2 y) { if (x < y) { x = y; return true; } return false; }
template <typename T1, typename T2> bool minimize(T1 &x, T2 y) { if (x > y) { x = y; return true; } return false; }
 
typedef long long ll;
typedef unsigned long long ull;
const int MOD = (int) 1e9 + 7;
const int N = (int) 1e3 + 7;
 
int n;
char a[N][N];
ll dp[N][N];
 
void add(ll &x, ll y) {
    x += y;
    x -= ((x >= MOD) ? MOD : 0);
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    //freopen(".inp", "r", stdin);
    //freopen(".out", "w", stdout);
    //freopen("Input.txt", "r", stdin);
    //freopen("Output.txt", "w", stdout);
    //freopen("TEST.inp", "r", stdin);
    //freopen("TEST.out", "w", stdout);
 
    cin >> n;
    For(i, 1, n, 1) For(j, 1, n, 1) cin >> a[i][j];
 
    dp[1][1] = 1;
    For(i, 1, n, 1) For(j, 1, n, 1) {
        if (a[i][j] == '*') dp[i][j] = 0;
        else {
            add(dp[i][j], dp[i - 1][j]);
            add(dp[i][j], dp[i][j - 1]);
        }
    }
    cout << dp[n][n];
 
    return 0;
}