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
const ll MOD = (ll) 1e9 + 7;
const ll MODD = (ll) 1e9 + 2207;
const int N = (int) 1e6 + 7;
const int base = (int) 31;
 
/*---------------------------------------------------------------*/
 
string a, b;
ll pw[N], pww[N], hash_a[N], hash_aa[N];
 
ll get_hash_a(int l, int r) {
    return (hash_a[r] - hash_a[l - 1] * pw[r - l + 1] + MOD * MOD) % MOD;
}
 
ll get_hash_aa(int l, int r) {
    return (hash_aa[r] - hash_aa[l - 1] * pww[r - l + 1] + MODD * MODD) % MODD;
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
 
    getline(cin, a);
    getline(cin, b);
 
    int len_a = a.length(), len_b = b.length(); a = "l" + a; b = "h" + b;
    pw[0] = 1;
    For(i, 1, len_a, 1) pw[i] = (pw[i - 1] * base) % MOD;
    For(i, 1, len_a, 1) hash_a[i] = (hash_a[i - 1] * base + a[i] - 'a' + 1) % MOD;
 
    pww[0] = 1;
    For(i, 1, len_a, 1) pww[i] = (pww[i - 1] * base) % MODD;
    For(i, 1, len_a, 1) hash_aa[i] = (hash_aa[i - 1] * base + a[i] - 'a' + 1) % MODD;
 
    ll ss = 0;
    For(i, 1, len_b, 1) ss = (ss * base + b[i] - 'a' + 1) % MOD;
 
    ll sss = 0;
    For(i, 1, len_b, 1) sss = (sss * base + b[i] - 'a' + 1) % MODD;
 
    int ans = 0;
    For(i, 1, len_a - len_b + 1, 1) if (get_hash_a(i, i + len_b - 1) == ss && get_hash_aa(i, i + len_b - 1) == sss)
        ++ans;
    cout << ans;
 
    return 0;
}