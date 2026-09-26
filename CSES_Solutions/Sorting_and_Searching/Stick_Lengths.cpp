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
    for (int i=0; i<n; ++i)
        cin >> a[i];
    sort(a, a+n);
    ll sum = 0;
    int mid = a[n/2];
    for (int i=0; i<n; ++i)
        sum += abs(a[i] - mid);
    cout << sum;
 
    return 0;
}