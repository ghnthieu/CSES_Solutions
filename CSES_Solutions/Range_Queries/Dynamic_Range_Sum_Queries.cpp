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
const int N = (int) 2e5 + 7;
 
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
 
int n, q, a[N];
ll tree[4 * N];
 
void build(int id, int l, int r) {
    if (l == r)
        tree[id] = a[l];
    else {
        int m = l + r >> 1;
        build(id << 1, l, m);
        build(id << 1 | 1, m + 1, r);
        tree[id] = tree[id << 1] + tree[id << 1 | 1];
    }
}
 
ll getsum(int id, int l, int r, int u, int v) {
    if (u > v)
        return 0;
    if (l == u && r == v)
        return tree[id];
    else {
        int m = l + r >> 1;
        return (getsum(id << 1, l, m, u, min(m, v)) + getsum(id << 1 | 1, m + 1, r, max(m + 1, u), v));
    }
}
 
void update(int id, int l, int r, int idx, int val) {
    if (l == r)
        tree[id] = val;
    else {
        int m = l + r >> 1;
        if (idx <= m)
            update(id << 1, l, m, idx, val);
        else
            update(id << 1 | 1, m + 1, r, idx, val);
        tree[id] = tree[id << 1] + tree[id << 1 | 1];
    }
}
 
__Trung_Hieu___ {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    //freopen(NAME".INP", "r", stdin);
    //freopen(NAME".OUT", "w", stdout);
 
    cin >> n >> q;
    for (int i=1; i<=n; ++i)
        cin >> a[i];
    build(1, 1, n);
    while (q--) {
        int type, l, r; cin >> type >> l >> r;
        if (type == 1)
            update(1, 1, n, l, r);
        else
            cout << getsum(1, 1, n, l, r) << '\n';
    }
 
    cerr << "Time elapsed: " << TIME << " s." << '\n';
    return (0 ^ 0);
}