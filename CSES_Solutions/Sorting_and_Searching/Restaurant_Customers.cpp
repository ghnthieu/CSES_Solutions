#include <bits/stdc++.h>
using namespace std;
 
#define fi first
#define se second
#define NAME ""
 
typedef long long ll;
typedef unsigned long long ull;
typedef double de;
const int MOD = (int) 1e9 + 7;
const int N = (int) 1e5 + 7;
 
int n;
vector <pair <int,int>> vp;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    #ifdef LOCAL
    freopen(NAME".INP","r",stdin);
    freopen(NAME".OUT","w",stdout);
    #endif
 
    cin >> n;
    for (int i=0; i<n; ++i) {
        int x, y; cin >> x >> y;
        vp.push_back({x, 1});
        vp.push_back({y, -1});
    }
    sort(vp.begin(), vp.end());
    int sum = 0, mx = 0;
    for (int i=0; i<vp.size(); ++i) {
        sum += vp[i].se;
        mx = max(mx, sum);
    }
    cout << mx;
 
    return 0;
}