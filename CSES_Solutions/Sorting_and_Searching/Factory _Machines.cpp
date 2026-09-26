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
 
int n, t, a[N];
 
bool check(int a[], int n, int ans, ll inp) {
    ll sum = 0;
    for (int i=0; i<n; ++i) {
        sum += inp / a[i];
        if (sum >= ans)
            return true;
    }
    return false;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    //freopen(NAME".INP","r",stdin);
    //freopen(NAME".OUT","w",stdout);
 
    cin >> n >> t;
    for (int i=0; i<n; ++i)
        cin >> a[i];
    ll l = 1, r = 1e18, ans = 0;
    while (l <= r) {
        ll mid = (l + r) / 2;
        if (check(a, n, t, mid)) {
            ans = mid;
            r = mid - 1;
        }
        else
            l = mid + 1;
    }
    cout << ans;
 
    return 0;
}