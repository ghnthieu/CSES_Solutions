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
const int N = (int) 1e2 + 7;
const int MAX_SUM_COIN = (int) 1e5 + 7;
 
/*---------------------------------------------------------------*/
 
int n, coin[N];
bool dp[N][MAX_SUM_COIN];
 
__Trung_Hieu___ {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    //freopen(".inp", "r", stdin);
    //freopen(".out", "w", stdout);
    // freopen("Input.txt", "r", stdin);
    // freopen("Output.txt", "w", stdout);
    //freopen("TEST.inp", "r", stdin);
    //freopen("TEST.out", "w", stdout);
 
    cin >> n;
    Rep(i, n) cin >> coin[i];
 
    dp[0][0] = true;
    For(i, 1, n, 1) For(sum, 0, MAX_SUM_COIN - 7, 1) {
        dp[i][sum] = dp[i - 1][sum];
        int tmp = sum - coin[i - 1];
        if (tmp >= 0 && dp[i - 1][tmp]) dp[i][sum] = true;
    }
 
    vec(int) luu;
    For(sum, 1, MAX_SUM_COIN - 7, 1) if (dp[n][sum])
        luu.pub(sum);
    cout << luu.size() << '\n';
    for (int x : luu) cout << x << " ";
 
    return 0;
}