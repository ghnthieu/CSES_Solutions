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
 
struct Data {
    int x, y;
};
 
int n;
Data a[N];
 
bool cmp(Data a, Data b) {
    if (a.x == b.x)
        return (a.y < b.y);
    return (a.x < b.x);
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    //freopen(NAME".INP","r",stdin);
    //freopen(NAME".OUT","w",stdout);
 
    cin >> n;
    for (int i=0; i<n; ++i)
        cin >> a[i].x >> a[i].y;
    sort(a, a+n, cmp);
    ll ans = 0, tmp = 0;
    for (int i=0; i<n; ++i) {
        tmp += a[i].x;
        ans += a[i].y - tmp;
    }
    cout << ans;
 
    return 0;
}