#include <bits/stdc++.h>
using namespace std;
 
#define fi first
#define se second
#define pb pop_back
#define pub push_back
#define __Trung_Hieu___ signed main()
#define mask(i) (1LL << (i))
#define bit(n, i) (((n) >> (i)) & 1)
#define all(v) v.begin(), v.end()
#define vec(kdl) vector<kdl>
#define ii(kdl1, kdl2) pair<kdl1, kdl2>
#define vii(kdl1, kdl2) vector<pair<kdl1, kdl2>>
#define For(i, l, r, up) for (int i = (l), _r = (r); i <= _r; i += up)
#define Ford(i, r, l, dw) for (int i = (r), _l = (l); i >= _l; i -= dw)
#define Rep(i, n) for (int i = 0, _n = (n); i < _n; ++i)
template <typename T1, typename T2> bool minimize(T1 &a, T2 b) { if (a > b) { a = b; return true; } return false; }
template <typename T1, typename T2> bool maximize(T1 &a, T2 b) { if (a < b) { a = b; return true; } return false; }
 
typedef long long ll;
typedef unsigned long long ull;
const int MOD = (int) 1e9 + 7;
const int N = (int) 2e5 + 5;
 
int n, m, k;
vii(int, int) inp[N];
priority_queue <ll> best[N];
 
void dijkstra(void) {
    priority_queue <ii(ll, int), vii(ll, int), greater <ii(ll, int)>> pq;
    best[1].push(0); pq.push({0, 1});
    while (!pq.empty()) {
        ii(ll, int) u = pq.top(); pq.pop();
        if (u.fi > best[u.se].top()) continue;
        for (ii(int, int) v : inp[u.se]) {
            ll ss = u.fi + v.se;
            if (best[v.fi].size() < k) {
                best[v.fi].push(ss);
                pq.push({ss, v.fi});
            } else if (ss < best[v.fi].top()) {
                best[v.fi].pop();
                best[v.fi].push(ss);
                pq.push({ss, v.fi});
            }
        }
    }
 
    vec(ll) ans;
    while (!best[n].empty()) {
        ans.pub(best[n].top());
        best[n].pop();
    }
    reverse(all(ans));
 
    for (ll x : ans) cout << x << " ";
}
 
__Trung_Hieu___ {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    //freopen("Input.txt", "r", stdin);
    //freopen("Output.txt", "w", stdout);
 
    cin >> n >> m >> k;
    Rep(new_edge, m) {
        int u, v, w;
        cin >> u >> v >> w;
        inp[u].pub({v, w});
    }
 
    dijkstra();
 
    return 0;
}