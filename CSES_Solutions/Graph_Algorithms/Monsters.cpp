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
#define vec(kdl) vector<kdl>
#define ii(kdl1, kdl2) pair<kdl1, kdl2>
#define vii(kdl1, kdl2) vector<pair<kdl1, kdl2>>
#define For(i, l, r, up) for (int i = (l), _r = (r); i <= _r; i += up)
#define Ford(i, r, l, dw) for (int i = (r), _l = (l); i >= _l; i -= dw)
#define Rep(i, n) for (int i = 0, _n = (n); i < _n; ++i)
template <typename T1, typename T2> bool minimize(T1 &a, T2 b) { if (a > b) { a = b; return true; } return false; }
template <typename T1, typename T2> bool maximize(T1 &a, T2 b) { if (a < b) { a = b; return true; } return false; }
 
typedef long long ll;
typedef unsigned long long ull;
const int MOD = (int)1e9 + 7;
const int maxN = 1000;
const int INF = 0x3f3f3f3f;
 
int N, M, sx, sy;
bool vis[maxN][maxN];
char ans[maxN * maxN], c[maxN][maxN], p[maxN][maxN];
int d1[maxN][maxN], d2[maxN][maxN];
int h[] = {1, -1, 0, 0};
int v[] = {0, 0, 1, -1};
queue<ii(int, int)> Q;
 
bool inbounds(int x, int y) {
    return (0 <= x && x < N && 0 <= y && y < M);
}
 
void printsolution(int x, int y) {
    int D = d2[x][y];
    cout << "YES\n" << D << "\n";
    Ford(i, D - 1, 0, 1) {
        ans[i] = p[x][y];
        if (ans[i] == 'D') x--;
        else if (ans[i] == 'U') x++;
        else if (ans[i] == 'R') y--;
        else if (ans[i] == 'L') y++;
    }
    Rep(i, D) cout << ans[i];
    cout << "\n";
}
 
__Trung_Hieu___ {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    //freopen("Input.txt", "r", stdin);
    //freopen("Output.txt", "w", stdout);
 
    cin >> N >> M;
    Rep(i, N) {
        Rep(j, M) {
            cin >> c[i][j];
            if (c[i][j] == '#') vis[i][j] = true;
            else if (c[i][j] == 'M') {
                vis[i][j] = true;
                Q.push({i, j});
            } else if (c[i][j] == 'A') {
                sx = i; sy = j;
            }
        }
    }
 
    while (!Q.empty()) {
        auto [x, y] = Q.front(); Q.pop();
        Rep(i, 4) {
            int nx = x + h[i], ny = y + v[i];
            if (inbounds(nx, ny) && !vis[nx][ny]) {
                d1[nx][ny] = d1[x][y] + 1;
                vis[nx][ny] = true;
                Q.push({nx, ny});
            }
        }
    }
 
    Rep(i, N) Rep(j, M) if (!vis[i][j]) d1[i][j] = INF;
    memset(vis, 0, sizeof(vis));
    vis[sx][sy] = true;
    Q.push({sx, sy});
 
    while (!Q.empty()) {
        auto [x, y] = Q.front(); Q.pop();
        Rep(i, 4) {
            int nx = x + h[i], ny = y + v[i];
            if (inbounds(nx, ny) && !vis[nx][ny] && d2[x][y] + 1 < d1[nx][ny]) {
                p[nx][ny] = "DURL"[i];
                d2[nx][ny] = d2[x][y] + 1;
                vis[nx][ny] = true;
                Q.push({nx, ny});
            }
        }
    }
 
    Rep(i, N) {
        if (c[i][0] != '#' && c[i][0] != 'M' && vis[i][0]) {
            printsolution(i, 0);
            return 0;
        }
        if (c[i][M-1] != '#' && c[i][M-1] != 'M' && vis[i][M-1]) {
            printsolution(i, M-1);
            return 0;
        }
    }
 
    Rep(i, M) {
        if (c[0][i] != '#' && c[0][i] != 'M' && vis[0][i]) {
            printsolution(0, i);
            return 0;
        }
        if (c[N-1][i] != '#' && c[N-1][i] != 'M' && vis[N-1][i]) {
            printsolution(N-1, i);
            return 0;
        }
    }
 
    cout << "NO\n";
    return 0;
}