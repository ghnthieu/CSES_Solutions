#include <bits/stdc++.h>
using namespace std;
 
#define fi first
#define se second
#define pb push_back
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
const ll INF = 1e15;
const int N = 2501;
 
vii(ll, ll) graph[N];
ll dist[N], par[N], cnt[N], n, m, x;
bool in_queue[N], visited[N];
 
bool spfa(ll start) {
    fill(dist, dist + n + 1, INF);
    fill(par, par + n + 1, -1);
    fill(cnt, cnt + n + 1, 0);
    fill(in_queue, in_queue + n + 1, false);
 
    dist[start] = 0;
    queue<ll> q;
    q.push(start);
    in_queue[start] = true;
 
    while (!q.empty()) {
        ll ele = q.front(); q.pop();
        visited[ele] = true;
        in_queue[ele] = false;
 
        for (auto child : graph[ele]) {
            if (minimize(dist[child.fi], dist[ele] + child.se)) {
                par[child.fi] = ele;
                cnt[child.fi]++;
                if (cnt[child.fi] > n) {
                    x = child.fi;
                    return false;
                }
                if (!in_queue[child.fi]) {
                    q.push(child.fi);
                    in_queue[child.fi] = true;
                }
            }
        }
    }
    return true;
}
 
__Trung_Hieu___ {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("Input.txt", "r", stdin);
    // freopen("Output.txt", "w", stdout);
 
    cin >> n >> m;
    vec(vec(ll)) edges(m, vec(ll)(3));
    Rep(i, m) {
        cin >> edges[i][0] >> edges[i][1] >> edges[i][2];
        graph[edges[i][0]].pb({edges[i][1], edges[i][2]});
    }
 
    For(i, 1, n, 1) {
        if (!spfa(i)) {
            cout << "YES\n";
            ll ele = x;
            stack<ll> st;
            bool is_stack[N] = {};
 
            while (!is_stack[ele]) {
                is_stack[ele] = true;
                st.push(ele);
                ele = par[ele];
            }
            cout << ele << " ";
            while (st.top() != ele) {
                cout << st.top() << " ";
                st.pop();
            }
            cout << ele << "\n";
            return 0;
        }
    }
    cout << "NO\n";
    return 0;
}