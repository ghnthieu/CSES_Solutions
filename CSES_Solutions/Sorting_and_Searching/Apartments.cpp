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
 
int n, m, k, a[N], b[N];
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    #ifdef LOCAL
    freopen(NAME".INP","r",stdin);
    freopen(NAME".OUT","w",stdout);
    #endif
 
    cin >> n >> m >> k;
    for (int i=0; i<n; ++i)
        cin >> a[i];
    for (int i=0; i<m; ++i)
        cin >> b[i];
    sort(a, a+n);
    sort(b, b+m);
    int i = 0, j = 0, ans = 0;
    while (i < n && j < m) {
        if (abs(a[i] - b[j]) <= k) {
            ++ans;
            ++i;
            ++j;
        }
        else if (a[i] < b[j])
            ++i;
        else
            ++j;
    }
    cout << ans;
 
    return 0;
}