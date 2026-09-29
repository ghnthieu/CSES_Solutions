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
#define vec(kdl) vector <kdl>
#define ii(kdl1, kdl2) pair <kdl1, kdl2>
#define vii(kdl1, kdl2) vector <pair <kdl1, kdl2>>
#define For(i, l, r, up) for (int i = (l), _r = (r); i <= _r; i += up)
#define Ford(i, r, l, dw) for (int i = (r), _l = (l); i >= _l; i -= dw)
#define Rep(i, n) for (int i = 0, _n = (n); i < _n; ++i)
template <typename T1, typename T2> bool minimize(T1 &a, T2 b) { if (a > b) { a = b; return true; } return false; }
template <typename T1, typename T2> bool maximize(T1 &a, T2 b) { if (a < b) { a = b; return true; } return false; }
 
typedef long long ll;
typedef unsigned long long ull;
const int MOD = (int) 1e9 + 7;
const int INF = (int) 1e9 + 7;
const int N = (int) 1e5 + 7;
 
/*---------------------------------------------------------------*/
 
int n, m, duong[N], trace[N];
vec(int) inp[N];
 
void dijkstra(int s, int t) {
    memset(duong, 0x3f, (n + 1) * sizeof(int)); duong[s] = 0;
    priority_queue <ii(int, int), vii(int, int), greater<ii(int, int)>> pq; pq.push({0, s});
    while (!pq.empty()) {
        ii(int, int) u = pq.top(); pq.pop();
        if (u.fi > duong[u.se]) continue;
        for (int v : inp[u.se]) if (minimize(duong[v], duong[u.se] + 1)) {
            trace[v] = u.se;
            pq.push({duong[v], v});
        }
    }
 
    if (duong[t] >= INF) {
        cout << "IMPOSSIBLE";
        return;
    }
 
    vec(int) luu;
    do {
        luu.pub(t);
        t = trace[t];
    } while (s != t);
    luu.pub(s); reverse(all(luu));
    cout << luu.size() << '\n';
    for (int x : luu) cout << x << " ";
}
 
__Trung_Hieu___ {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    //freopen(".inp", "r", stdin);
    //freopen(".out", "w", stdout);
    // freopen("Input.txt", "r", stdin);
    // freopen("Output.txt", "w", stdout);
    //freopen("TEST.inp", "r", stdin);
    //freopen("TEST.out", "w", stdout);
 
    cin >> n >> m;
    Rep(edge, m) {
        int x, y; cin >> x >> y;
        inp[x].pub(y);
        inp[y].pub(x);
    }
 
    dijkstra(1, n);
 
    return 0;
}