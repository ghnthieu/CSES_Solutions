#include <bits/stdc++.h>
using namespace std;
 
#define fi first
#define se second
#define NAME ""
 
typedef long long ll;
typedef unsigned long long ull;
typedef double de;
const int MOD = (int) 1e9 + 7;
const int N = (int) 1e5 + 7;
 
int n, m, a[N];
ll dp[N][107];
 
ll solve(int n, int m, int x) {
    if (x < 1 || x > m)
        return 0;
    if (a[n] && a[n] != x)
        return 0;
    if (n == 1)
        return 1;
    if (dp[n][x] != -1)
        return dp[n][x];
    return dp[n][x] = (solve(n - 1, m, x - 1) + solve(n - 1, m, x) + solve(n - 1, m, x + 1)) % MOD;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    //freopen(NAME".INP","r",stdin);
    //freopen(NAME".OUT","w",stdout);
 
    cin >> n >> m;
    for (int i=1; i<=n; ++i)
        cin >> a[i];
    memset(dp, -1, sizeof(dp));
    ll ans = 0;
    if (a[n])
        ans = solve(n, m, a[n]);
    else {
        for (int i=1; i<=m; ++i)
            ans = (ans + solve(n, m, i)) % MOD;
    }
    cout << ans;
 
    return 0;
}