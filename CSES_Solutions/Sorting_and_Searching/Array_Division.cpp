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
 
int n, k, a[N];
 
bool check(int a[], int k, ll sum) {
    int cnt = 0;
    ll summ = 0;
    for (int i=0; i<n; ++i) {
        if (a[i] > sum)
            return false;
        if (summ + a[i] > sum) {
            ++cnt;
            summ = 0;
        }
        summ += a[i];
    }
    if (summ > 0)
        ++cnt;
    return (cnt <= k);
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    //freopen(NAME".INP","r",stdin);
    //freopen(NAME".OUT","w",stdout);
 
    cin >> n >> k;
    for (int i=0; i<n; ++i)
        cin >> a[i];
    ll ans = 1, r = 1e18;
    while (ans < r) {
        ll mid = (ans + r) / 2;
        if (check(a, k, mid))
            r = mid;
        else
            ans = mid + 1;
    }
    cout << ans;
 
    return 0;
}