#include <bits/stdc++.h>
using namespace std;
 
#define NAME ""
#define fi first
#define se second
#define bk back
#define fr front
#define pb pop_back
#define pf pop_front
#define pub push_back
#define puf push_front
#define __Trung_Hieu___ signed main()
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define mask(i) (1LL << (i))
#define bit(n, i) (((n) >> (i)) & 1)
#define all(v) v.begin(), v.end()
#define rall(v, kdl) v.begin(), v.end(), greater <kdl> ()
#define vec(kdl) vector <kdl>
#define ii(kdl1, kdl2) pair <kdl1, kdl2>
#define vii(kdl1, kdl2) vector <pair <kdl1, kdl2>>
#define iii(kdl1, kdl2, kdl3) pair <pair <kdl1, kdl2>, kdl3>
#define viii(kdl1, kdl2, kdl3) vector <pair <pair <kdl1, kdl2>, kdl3>>
#define For(i, l, r) for (int i = (l), _r = (r); i <= _r; ++i)
#define Ford(i, l, r) for (int i = (r), _l = (l); i >= _l; --i)
#define Rep(i, n) for (int i = 0, _n = (n); i < _n; ++i)
template <typename T1, typename T2> bool minimize(T1 &a, T2 b) { if (a > b) { a = b; return true; } return false; }
template <typename T1, typename T2> bool maximize(T1 &a, T2 b) { if (a < b) { a = b; return true; } return false; }
 
typedef long long ll;
typedef unsigned long long ull;
const int MOD = (int) 1e9 + 7;
const int N = (int) 1e6 + 7;
 
/*-----------------------------------------------------------------------------------------------------------------*/
 
int n, ans = 0;
 
//i = xúc xắc thứ i
//sum = tổng các chấm của xúc xắc trước đó
void sub1(int i, ll sum, vec(int) luu) {
    if (i == n || sum == n) {
        ans += ((sum == n) ? 1 : 0);
        // if (sum == n) {
        //     for (int x : luu) cout << x << " ";
        //     cout << '\n';
        // }
        return;
    }
 
    For(j, 1, 6) {
        sum += j;
        luu.pub(j);
        sub1(i + 1, sum, luu);
        sum -= j;
        luu.pb();
    }
}
 
int dp[N];
 
void sub2(void) {
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    dp[4] = 8;
    dp[5] = 16;
    dp[6] = 32;
    For(i, 7, n) {
        int sum = 0;
        For(j, 1, 6) { 
            sum += dp[i - j];
            sum %= MOD;
        }
        dp[i] = sum;
    }
    cout << dp[n];
}
 
__Trung_Hieu___ {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    //freopen(NAME".INP", "r", stdin);
    //freopen(NAME".OUT", "w", stdout);
 
    cin >> n;
 
    if (n <= 9) {
        vec(int) tmp;
        sub1(0, 0, tmp);
        cout << ans;
    }
    else
        sub2();
 
    cerr << "Time elapsed: " << TIME << " s." << '\n';
    return (0 ^ 0);
}