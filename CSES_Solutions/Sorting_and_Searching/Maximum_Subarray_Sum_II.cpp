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
 
int n, a, b;
ll arr[N];
set <array <ll,2>> s;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    //freopen(NAME".INP","r",stdin);
    //freopen(NAME".OUT","w",stdout);
 
    cin >> n >> a >> b;
    for (int i=0; i<n; ++i) {
        cin >> arr[i+1];
        arr[i+1] += arr[i];
    }
    ll ans = -1e18;
    for (int i=0; i<=n; ++i) {
        if (i >= a)
            s.insert({arr[i-a], i-a});
        if (s.size())
            ans = max(ans, arr[i] - (*s.begin())[0]);
        if (i >= b)
            s.erase({arr[i-b], i-b});
    }
    cout << ans;
 
    return 0;
}