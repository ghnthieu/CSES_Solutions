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
 
int n, m, a[N], tree[4 * N];
 
void build(int v, int l, int r) {
    if (l == r)
        tree[v] = a[l];
    else {
        int mid = (l + r) / 2;
        build(2 * v, l, mid);
        build(2 * v + 1, mid + 1, r);
        tree[v] = max(tree[2 * v], tree[2 * v + 1]);
    }
}
 
void solve(int v, int l, int r, int value) {
    if (l == r) {
        tree[v] -= value;
        cout << l << " ";
    }
    else {
        int mid = l + r >> 1;
        if (tree[2 * v] >= value)
            solve(2 * v, l, mid, value);
        else
            solve(2 * v + 1, mid + 1, r, value);
        tree[v] = max(tree[2 * v], tree[2 * v + 1]);
    }
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    //freopen(NAME".INP","r",stdin);
    //freopen(NAME".OUT","w",stdout);
 
    cin >> n >> m;
    for (int i=1; i<=n; ++i)
        cin >> a[i];
    build(1, 1, n);
    while (m--) {
        int x; cin >> x;
        if (tree[1] < x)
            cout << 0 << " ";
        else
            solve(1, 1, n, x);
    }
 
    return 0;
}