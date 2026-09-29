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
 
int q;
 
ll modulo(ll a, ll b, ll mod) {
    assert(b >= 0);
    a %= mod;
    ll res = 1;
    while (b > 0) {
        if (b%2 == 1)
            res = res * a % mod;
        a = a * a % mod;
        b /= 2;
    }
    return res;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    //freopen(NAME".INP","r",stdin);
    //freopen(NAME".OUT","w",stdout);
 
    cin >> q;
    while (q--) {
        int a, b, c; cin >> a >> b >> c;
        ll tmp = modulo(b, c, MOD - 1);
        ll ans = modulo(a, tmp, MOD);
        cout << ans << '\n';
    }
 
    return 0;
}