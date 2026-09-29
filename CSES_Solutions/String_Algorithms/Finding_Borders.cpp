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
const int N = (int) 1e6 + 7;
const int base = (int) 31;
 
/*-----------------------------------------------------------------------------------------------------------------*/
 
string s;
ll pw[N], hash_s[N];
 
ll get_hash(int l, int r) {
    return (hash_s[r] - hash_s[l - 1] * pw[r - l + 1] + MOD * MOD) % MOD;
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
 
    cin >> s; int len = s.length(); s = "l" + s;
 
    pw[0] = 1;
    For(i, 1, len, 1) pw[i] = (pw[i - 1] * base) % MOD;
    For(i, 1, len, 1) hash_s[i] = (hash_s[i - 1] * base + s[i] - 'a' + 1) % MOD;
 
    ll ss = 0;
    For(i, 1, len - 1, 1) {
        ss = (ss * base + s[i] - 'a' + 1) % MOD;
        if (get_hash(1, i) == ss && get_hash(len - i + 1, len) == ss)
            cout << i << " ";
    }
 
    return 0;
}