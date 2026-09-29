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
const int N = (int) 1e3 + 7;
 
int q, n, a[N][N], sum[N][N];
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    //freopen(NAME".INP","r",stdin);
    //freopen(NAME".OUT","w",stdout);
 
    cin >> n >> q;
    for (int i=1; i<=n; ++i) {
        for (int j=1; j<=n; ++j) {
            char ch; cin >> ch;
            if (ch == '.')
                a[i][j] = 0;
            else
                a[i][j] = 1;
            sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + a[i][j];
 
        }
    }
 
    while (q--) {
        int h1, c1, h2, c2; cin >> h1 >> c1 >> h2 >> c2;
        cout << sum[h2][c2] - sum[h1-1][c2] - sum[h2][c1-1] + sum[h1-1][c1-1] << '\n';
    }
 
    return 0;
}