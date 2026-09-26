#include <bits/stdc++.h>
using namespace std;
 
#define fi first
#define se second
#define NAME ""
 
typedef long long ll;
typedef unsigned long long ull;
typedef double de;
const int MOD = (int) 1e9 + 7;
const int N = (int) 3e1 + 7;
 
int n, a[N];
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    //freopen(NAME".INP","r",stdin);
    //freopen(NAME".OUT","w",stdout);
 
    cin >> n;
    ll sum = 0;
    for (int i=0; i<n; ++i) {
        cin >> a[i];
        sum += a[i];
    }
    ll ans = INT_MAX;
    for (int i=0; i<1<<n; ++i) {
        ll tmp = 0;
        for (int j=0; j<n; ++j) {
            if (i & 1 << j)
                tmp += a[j];
        }
        ans = min(ans, abs((sum - tmp) - tmp));
    }
    cout << ans;
 
    return 0;
}