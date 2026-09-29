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
const int MOD = (int)1e9 + 7;
const int N = (int)1e6 + 7;
const ll INF = 0x3f3f3f3f3f3f3f3f;
 
vec(vii(ll, int)) edge(N);
ll dist[N];
ll num[N];
int minf[N], maxf[N];
bool v[N];
 
void dijkstra(int s) {
    priority_queue<ii(ll, int), vii(ll, int), greater<ii(ll, int)>> pq;
    memset(dist, 0x3f, sizeof(dist));
    dist[s] = 0; num[s] = 1; minf[s] = maxf[s] = 0;
    pq.push({0, s});
 
    while (!pq.empty()) {
        int vert = pq.top().se; pq.pop();
        if (v[vert]) continue;
        v[vert] = true;
 
        for (auto [cost, next] : edge[vert]) {
            ll alt = dist[vert] + cost;
            if (alt == dist[next]) {
                num[next] = (num[next] + num[vert]) % MOD;
                minimize(minf[next], minf[vert] + 1);
                maximize(maxf[next], maxf[vert] + 1);
            } else if (alt < dist[next]) {
                dist[next] = alt;
                num[next] = num[vert];
                minf[next] = minf[vert] + 1;
                maxf[next] = maxf[vert] + 1;
                pq.push({dist[next], next});
            }
        }
    }
}
 
__Trung_Hieu___ {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    //freopen("Input.txt", "r", stdin);
    //freopen("Output.txt", "w", stdout);
 
    int n, m;
    cin >> n >> m;
    Rep(i, m) {
        int start, end, cost;
        cin >> start >> end >> cost;
        edge[start].pub({cost, end});
    }
 
    dijkstra(1);
    cout << dist[n] << " " << num[n] << " " << minf[n] << " " << maxf[n] << "\n";
 
    return 0;
}