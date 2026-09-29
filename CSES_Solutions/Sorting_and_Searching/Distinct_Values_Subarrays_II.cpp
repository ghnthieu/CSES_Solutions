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
map <int,int> mp;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    //freopen(NAME".INP","r",stdin);
    //freopen(NAME".OUT","w",stdout);
 
    cin >> n >> k;
    for (int i=0; i<n; ++i)
        cin >> a[i];
    int l = 0, r = 0;
    ll sum = 0, ans = 0;
    while (l < n) {
        while (r < n && sum + (mp[a[r]] == 0) <= k) {
            ++mp[a[r]];
            sum += (mp[a[r]] == 1);
            ++r;
        }
        ans += r - l;
        sum -= (mp[a[l]] == 1);
        --mp[a[l]];
        ++l;
    }
    cout << ans;
 
    return 0;
}