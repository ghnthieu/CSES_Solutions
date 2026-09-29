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
const int N = (int) 1e6 + 7;
 
/*-----------------------------------------------------------------------------------------------------------------*/
 
int n, q, a[N];
 
struct Node {
    ll sum, best_pre, best_suf, best_sum;
 
    Node (int val = 0) {
        sum = best_pre = best_suf = best_sum = val;
    }
 
} tree[4 * N];
 
Node merge(Node left, Node right) {
    Node res;
    res.sum = left.sum + right.sum;
    res.best_pre = max(left.best_pre, left.sum + right.best_pre);
    res.best_suf = max(right.best_suf, right.sum + left.best_suf);
    res.best_sum = max({left.best_sum, right.best_sum, left.best_suf + right.best_pre});
    return res;
}
 
void build(int id, int l, int r) {
    if (l == r)
        tree[id] = Node(a[l]);
    else {
        int m = l + r >> 1;
        build(id << 1, l, m);
        build(id << 1 | 1, m + 1, r);
        tree[id] = merge(tree[id << 1], tree[id << 1 | 1]);
    }
}
 
void update(int id, int l, int r, int pos, int val) {
    if (l == r)
        tree[id] = val;
    else {
        int m = l + r >> 1;
        if (pos <= m)
            update(id << 1, l, m, pos, val);
        else
            update(id << 1 | 1, m + 1, r, pos, val);
        tree[id] = merge(tree[id << 1], tree[id << 1 | 1]);
    }
}
 
Node get(int id, int l, int r, int u, int v) {
    if (l > v || u > r) return 0;
    if (l >= u && v >= r) return tree[id];
    int m = l + r >> 1;
    return merge(get(id << 1, l, m, u, v), get(id << 1 | 1, m + 1, r, u, v));
}
 
__Trung_Hieu___ {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    //freopen(".inp", "r", stdin);
    //freopen(".out", "w", stdout);
    //freopen("Input.txt", "r", stdin);
    //freopen("Output.txt", "w", stdout);
    //freopen("TEST.inp", "r", stdin);
    //freopen("TEST.out", "w", stdout);
 
    cin >> n >> q;
    For(i, 1, n, 1) cin >> a[i];
 
    build(1, 1, n);
    Rep(query, q) {
        int idx, val; cin >> idx >> val;
        update(1, 1, n, idx, val);
        cout << max(0ll, get(1, 1, n, 1, n).best_sum) << '\n';
    }
 
    return 0;
}