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
    //freopen(NAME".INP","r",stdin);
    //freopen(NAME".OUT","w",stdout);
 
    cin >> n;
    int mx = 0;
    ll sum = 0;
    for (int i=0; i<n; ++i) {
        int x; cin >> x;
        mx = max(mx, x);
        sum += x;
    }
    cout << max((ll) mx*2, sum);
 
    return 0;
}