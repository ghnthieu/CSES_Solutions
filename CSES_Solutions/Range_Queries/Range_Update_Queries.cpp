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
#define all(v) v.begin(), v.end()
#define rall(v, kdl) v.begin(), v.end(), greater <kdl> ()
#define ii(kdl1, kdl2) pair <kdl1,kdl2>
#define vii(kdl1, kdl2) vector <pair <kdl1,kdl2>>
#define iii(kdl1, kdl2, kdl3) pair <pair <kdl1,kdl2>,kdl3>
#define viii(kdl1, kdl2, kdl3) vector <pair <kdl1,kdl2>,kdl3>>
 
typedef long long ll;
typedef unsigned long long ull;
typedef double de;
const int MOD = (int) 1e9 + 7;
const int N = (int) 1e6 + 7;
 
int q, n, a[N];
ll tree[4 * N], lazy[4 * N];
 
void build(int v, int l, int r) {
    if (l == r)
        tree[v] = a[l];
    else {
        int mid = l + r >> 1;
        build(2 * v, l, mid);
        build(2 * v + 1, mid + 1, r);
    }
}
 
void fix(int v, int l, int r) {
    if (!lazy[v])
        return;
    tree[v] += lazy[v];
    if (l != r) {
        lazy[2 * v] += lazy[v];
        lazy[2 * v + 1] += lazy[v];
    }
    lazy[v] = 0;
}
 
void update(int id, int l, int r, int u, int v, int val) {
    fix(id, l, r);
    if (l > v || r < u)
        return;
    if (l >= u && r <= v) {
        lazy[id] += val;
        fix(id, l, r);
        return;
    }
    int mid = l + r >> 1;
    update(2 * id, l, mid, u, v, val);
    update(2 * id + 1, mid + 1, r, u, v, val);
}
 
ll findindex(int v, int treel, int treer, int index) {
    while (treel <= treer) {
        fix(v, treel, treer);
        if (treel == treer)
            break;
        int treem = treel + treer >> 1;
        if (index <= treem) {
            v <<= 1;
            treer = treem;
        }
        else {
            v = v << 1 | 1;
            treel = treem + 1;
        }
    }
    return tree[v];
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    //freopen(NAME".INP","r",stdin);
    //freopen(NAME".OUT","w",stdout);
 
    cin >> n >> q;
    for (int i=1; i<=n; ++i)
        cin >> a[i];
    build(1, 1, n);
    while (q--) {
        int type; cin >> type;
        if (type == 1) {
            int l, r, value; cin >> l >> r >> value;
            update(1, 1, n, l, r, value);
        }
        else {
            int index; cin >> index;
            cout << findindex(1, 1, n, index) << '\n';
        }
    }
 
    return 0;
}