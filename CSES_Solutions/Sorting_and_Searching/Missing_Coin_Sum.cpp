#include <bits/stdc++.h>
using namespace std;
 
#define fi first
#define se second
#define NAME ""
 
typedef long long ll;
typedef unsigned long long ull;
typedef double de;
const int MOD = (int) 1e9 + 7;
const int N = (int) 2e5 + 7;
 
int n, a[N];
ll dp[N];
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    #ifdef LOCAL
    freopen(NAME".INP","r",stdin);
    freopen(NAME".OUT","w",stdout);
    #endif
 
    cin >> n;
    for (int i=1; i<=n; ++i)
        cin >> a[i];
    sort(a+1, a+n+1);
    dp[0] = 1;
    for (int i=1; i<=n; ++i) {
        if (dp[i-1] < a[i]) {
            cout << dp[i-1];
            return 0;
        }
        dp[i] = dp[i-1] + a[i];
    }
    cout << dp[n];
 
    return 0;
}
