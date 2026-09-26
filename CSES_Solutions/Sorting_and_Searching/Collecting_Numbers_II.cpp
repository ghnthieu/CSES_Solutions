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
 
int n, m;
map <int,int> mp;
vector <pair <int,int>> a;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    //freopen(NAME".INP","r",stdin);
    //freopen(NAME".OUT","w",stdout);
 
    cin >> n >> m;
    a.push_back({0, 0});
    for (int i=1; i<=n; ++i) {
        int x; cin >> x;
        a.push_back({x,0});
        a[i].se = i;
    }
    sort(a.begin() + 1, a.end());
    for (int i=1; i<=n; ++i)
        mp[a[i].se] = i;
    int res = 1;
    for (int i=1; i<=n; ++i) {
        if (a[i].se < a[i-1].se)
            ++res;
    }
    while (m--) {
        int x, y; cin >> x >> y;
        auto it1 = mp.find(x);
        auto it2 = mp.find(y);
        int i = it1 -> se, j = it2 -> se, mn = min(i, j), mx = max(i, j);
        if (a[mn].se < a[mn-1].se) {
            if (a[mx].se > a[mn-1].se)
                --res;
        }
        else {
            if (a[mx].se < a[mn-1].se)
                ++res;
        }
        if (a[mx+1].se < a[mx].se) {
            if (a[mx+1].se > a[mn].se)
                --res;
        }
        else {
            if (a[mx+1].se < a[mn].se)
                ++res;
        }
        if (mx - mn == 1) {
            if (a[mx].se < a[mn].se) {
                if (a[mn].se > a[mx].se)
                    --res;
            }
            else {
                if (a[mn].se < a[mx].se)
                    ++res;
            }
        }
        else {
            if (a[mx].se < a[mx-1].se) {
                if (a[mn].se > a[mx-1].se)
                    --res;
            }
            else {
                if (a[mn].se < a[mx-1].se)
                    ++res;
            }
            if (a[mn+1].se < a[mn].se) {
                if (a[mn+1].se > a[mx].se)
                    --res;
            }
            else {
                if (a[mn+1].se < a[mx].se)
                    ++res;
            }
        }
        swap(a[mn].se, a[mx].se);
        swap(it1 -> se, it2 -> se);
        cout << res << '\n';
    }
 
    return 0;
}