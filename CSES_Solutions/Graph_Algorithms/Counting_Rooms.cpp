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
const int N = (int) 1e3 + 7;
 
/*---------------------------------------------------------------*/
 
int n, m;
int dx[4] = {1, -1, 0, 0},
    dy[4] = {0, 0, 1, -1};
char a[N][N];
bool use[N][N];
 
void bfs(int i, int j) {
    use[i][j] = true;
    queue <ii(int, int)> qu; qu.push({i, j});
    while (!qu.empty()) {
        ii(int, int) top = qu.front(); qu.pop();
        Rep(k, 4) {
            int it = top.fi + dx[k], jt = top.se + dy[k];
            if (it >= 1 && it <= n && jt >= 1 && jt <= m && use[it][jt] == false && a[it][jt] == '.') {
                use[it][jt] = true;
                qu.push({it, jt});
            }
        } 
    }
}
 
__Trung_Hieu___ {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    //freopen(".inp", "r", stdin);
    //freopen(".out", "w", stdout);
    // freopen("Input.txt", "r", stdin);
    // freopen("Output.txt", "w", stdout);
    //freopen("TEST.inp", "r", stdin);
    //freopen("TEST.out", "w", stdout);
 
    cin >> n >> m;
    For(i, 1, n, 1) For(j, 1, m, 1) cin >> a[i][j];
 
    memset(use, false, sizeof(use));
    int room = 0;
    For(i, 1, n, 1) For(j, 1, m, 1) if (a[i][j] == '.' && use[i][j] == false) {
        ++room;
        bfs(i, j);
    }
    cout << room;
 
    return 0;
}