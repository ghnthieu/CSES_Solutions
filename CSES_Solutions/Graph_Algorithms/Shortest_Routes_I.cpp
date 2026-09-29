#include <bits/stdc++.h>
using namespace std;
 
#define NAME ""
#define fi first
#define se second
#define fr front
#define bk back
#define pf pop_front
#define pb pop_back
#define puf push_front
#define pub push_back
#define NOT 18446744073709551615
#define __Trung_Hieu___ signed main()
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define mask(i) (1LL << (i))
#define bit(n, i) (((n) >> (i)) & 1)
#define vec(kdl) vector <kdl>
#define all(v) v.begin(), v.end()
#define rall(v, kdl) v.begin(), v.end(), greater <kdl> ()
#define ii(kdl1, kdl2) pair <kdl1,kdl2>
#define vii(kdl1, kdl2) vector <pair <kdl1,kdl2>>
#define iii(kdl1, kdl2, kdl3) pair <pair <kdl1,kdl2>,kdl3>
#define viii(kdl1, kdl2, kdl3) vector <pair <pair <kdl1,kdl2>,kdl3>>
template <typename T1, typename T2> bool minimize(T1 &a, T2 b) { if (a > b) { a = b; return true; } return false; }
template <typename T1, typename T2> bool maximize(T1 &a, T2 b) { if (a < b) { a = b; return true; } return false; }
 
typedef long long ll;
typedef unsigned long long ull;
typedef double de;
typedef long double lde;
const int MOD = (int) 1e9 + 7;
const int N = (int) 1e5 + 7;
 
class DisjointSet {
private:
    vec(int) lab;
 
public:
    DisjointSet(int n = 0) {
        lab.assign(n + 7, -1);
    }
 
    int find(int x) {
        return ((lab[x] < 0) ? x : (lab[x] = find(lab[x])));
    }
 
    bool join(int u, int v) {
        int x = find(u), y = find(v);
        if (x == y) return false;
        if (lab[x] > lab[y]) swap(x, y);
        lab[x] += lab[y];
        lab[y] = x;
        return true;
    }
 
};
 
int n, m;
ll duong[N];
vii(int, int) inp[N];
 
void dijkstra(int s) {
    memset(duong, 0x3f, sizeof(duong));
    duong[s] = 0;
    priority_queue <ii(ll, int), vii(ll, int), greater <ii(ll, int)>> pq;
    pq.push({0, s});
    while (!pq.empty()) {
        ii(ll, int) top = pq.top(); pq.pop();
        int u = top.se; ll kc = top.fi;
        if (duong[u] < kc)
            continue;
        for (ii(int, int) v : inp[u]) {
            if (minimize(duong[v.fi], duong[u] + v.se))
                pq.push({duong[v.fi], v.fi});
        }
    }
    for (int i=1; i<=n; ++i)
        cout << duong[i] << " ";
}
 
__Trung_Hieu___ {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    //freopen(NAME".INP", "r", stdin);
    //freopen(NAME".OUT", "w", stdout);
 
    cin >> n >> m;
    while (m--) {
        int x, y, w; cin >> x >> y >> w;
        inp[x].pub({y, w});
    }
 
    dijkstra(1);
 
    cerr << "Time elapsed: " << TIME << " s." << '\n';
    return (0 ^ 0);
}