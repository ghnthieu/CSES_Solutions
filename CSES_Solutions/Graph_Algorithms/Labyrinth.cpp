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
const int INF = (int) 1e9 + 7;
const int N = (int) 1e3 + 7;
 
/*---------------------------------------------------------------*/
 
int n, m, duong[N][N], trace[N][N];
int dx[4] = {-1, 1, 0, 0},
    dy[4] = {0, 0, 1, -1};
char matrix[N][N];
string gogo = "UDRL";
 
void bfs(int i, int j) {
    memset(duong, 0x3f, sizeof(duong)); duong[i][j] = 0;
    queue <ii(int, int)> qu; qu.push({i, j});
    while (!qu.empty()) {
        ii(int, int) top = qu.front(); qu.pop();
        Rep(k, 4) {
            int it = top.fi + dx[k], jt = top.se + dy[k];
            if (it >= 1 && it <= n && jt >= 1 && jt <= m && matrix[it][jt] != '#' && minimize(duong[it][jt], duong[top.fi][top.se] + 1)) {
                qu.push({it, jt});
                trace[it][jt] = k;
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
    ii(int, int) st, en;
    For(i, 1, n, 1) For(j, 1, m, 1) {
        cin >> matrix[i][j];
        if (matrix[i][j] == 'A') st = {i, j};
        if (matrix[i][j] == 'B') en = {i, j};
    }
 
    bfs(st.fi, st.se);
 
    if (duong[en.fi][en.se] >= INF) {
        cout << "NO";
        return 0;
    }
 
    cout << "YES" << '\n' << duong[en.fi][en.se] << '\n';
    vec(int) luu;
    while (en != st) {
        int trce = trace[en.fi][en.se];
        luu.pub(trce);
        en = {en.fi - dx[trce], en.se - dy[trce]};
    }
    reverse(all(luu));
    for (int x : luu) cout << gogo[x];
 
    return 0;
}