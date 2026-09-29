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
 
int n, s, a[N];
map <ll,int> mp;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    //freopen(NAME".INP","r",stdin);
    //freopen(NAME".OUT","w",stdout);
 
    cin >> n >> s;
    for (int i=0; i<n; ++i)
        cin >> a[i];
    mp[0] = 1;
    ll sum = 0, ans = 0;
    for (int i=0; i<n; ++i) {
        sum += a[i];
        ans += mp[sum - s];
        ++mp[sum];
    }
    cout << ans;
 
    return 0;
}