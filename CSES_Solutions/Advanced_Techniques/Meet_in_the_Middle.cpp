#include <bits/stdc++.h>
using namespace std;
 
#define fi first
#define se second
#define pub push_back
#define pb pop_back
#define mask(i) (1ll << (i))
#define bit(n, i) (((n) >> (i)) & 1)
#define all(v) v.begin(), v.end()
#define vec(kdl) vector <kdl>
#define ii(kdl1, kdl2) pair <kdl1, kdl2>
#define vii(kdl1, kdl2) vector <pair <kdl1, kdl2>>
#define For(i, l, r, up) for (int i = (l), _r = (r); i <= _r; i += up)
#define Ford(i, r, l, dw) for (int i = (r), _l = (l); i >= _l; i -= dw)
#define Rep(i, n) for (int i = 0, _n = (n); i < _n; ++i)
template <typename T1, typename T2> bool maximize(T1 &x, T2 y) { if (x < y) { x = y; return true; } return false; }
template <typename T1, typename T2> bool minimize(T1 &x, T2 y) { if (x > y) { x = y; return true; } return false; }
 
typedef long long ll;
typedef unsigned long long ull;
const int MOD = (int) 1e9 + 7;
const int N = (int) 2e5 + 7;
 
int n, s, a[N];
vec(int) luu_1, luu_2;
 
void backtrack_1(int i, int sum) {
    if (sum > s) return;
    if (sum <= s) {
        luu_1.pub(sum);
        if (sum == s) return;
    }
 
    For(j, i + 1, n / 2, 1) {
        ll tmp = sum;
        sum += a[j];
        backtrack_1(j, sum);
        sum = tmp;
    }
}
 
void backtrack_2(int i, int sum) {
    if (sum > s) return;
    if (sum <= s) {
        luu_2.pub(sum);
        if (sum == s) return;
    }
 
    For(j, i + 1, n, 1) {
        ll tmp = sum;
        sum += a[j];
        backtrack_2(j, sum);
        sum = tmp;
    }
}
 
map <int, int> cnt;
 
void solve(void) {
    sort(all(luu_2)); for (int x : luu_2) ++cnt[x];
    ll ans = 0;
    For(i, 0, luu_1.size() - 1, 1) {
        int tk = s - luu_1[i];
        int l = 0, r = luu_2.size() - 1, res = -1;
        while (l <= r) {
            int m = l + r >> 1;
            if (luu_2[m] == tk) {
                res = m;
                break;
            }
            else if (luu_2[m] < tk)
                l = m + 1;
            else
                r = m - 1;
        }
        if (res != -1) ans += cnt[tk];
    }
    cout << ans;
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    //freopen(".inp", "r", stdin);
    //freopen(".out", "w", stdout);
    // freopen("Input.txt", "r", stdin);
    // freopen("Output.txt", "w", stdout);
    //freopen("TEST.inp", "r", stdin);
    //freopen("TEST.out", "w", stdout);
 
    cin >> n >> s;
    For(i, 1, n, 1) cin >> a[i];
 
    backtrack_1(0, 0);
    backtrack_2(n / 2, 0);
    solve();
 
    return 0;
}