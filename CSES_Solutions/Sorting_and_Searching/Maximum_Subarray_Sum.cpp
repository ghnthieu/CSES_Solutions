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
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    #ifdef LOCAL
    freopen(NAME".INP","r",stdin);
    freopen(NAME".OUT","w",stdout);
    #endif
 
    cin >> n;
    ll sum = 0, ans = -1e18;
    for (int i=0; i<n; ++i) {
        cin >> a[i];
        sum += a[i];
        ans = max(ans, sum);
        if (sum < 0)
            sum = 0;
    }
    cout << ans;
 
    return 0;
}