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
const int N = (int) 2e5 + 7;
 
int q, n, a[N];
ll tree[4 * N];
 
void build(int v, int l, int r) {
    if (l == r)
        tree[v] = a[l];
    else {
        int mid = l + r >> 1;
        build(2 * v, l, mid);
        build(2 * v + 1, mid + 1, r);
        tree[v] = tree[2 * v] ^ tree[2 * v + 1];
    }
}
 
ll fdxor(int v, int treel, int treer, int l, int r) {
    if (l > r)
        return 0;
    if (treel == l && treer == r)
        return tree[v];
    else {
        int treem = (treel + treer) / 2;
        return fdxor(2 * v, treel, treem, l, min(treem, r)) ^ fdxor(2 * v + 1, treem + 1, treer, max(treem + 1, l), r);
    }
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
        int l, r; cin >> l >> r;
        cout << fdxor(1, 1, n, l, r) << '\n';
    }
 
    return 0;
}