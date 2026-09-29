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
 
int n;
ll fact[N], inv[N];
 
ll inverse(ll x) {
    ll res = 1, expo = MOD - 2;
    while (expo) {
        if (expo & 1) res = (res * x) % MOD;
        x = (x * x) % MOD;
        expo >>= 1;
    }
    return res;
}
 
void init(){
    fact[0] = inv[0] = 1;
    For(i, 1, N - 1, 1) {
        fact[i] = i * fact[i - 1] % MOD;
        inv[i] = inverse(fact[i]);
    }
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
 
    init();
    cin >> n;
    For(i, 1, n, 1) {
        int a, b; cin >> a >> b;
        cout << fact[a] * inv[b] % MOD * inv[a - b] % MOD << '\n';
    }
 
    return 0;
}