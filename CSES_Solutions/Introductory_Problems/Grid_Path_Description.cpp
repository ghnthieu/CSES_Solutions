#include <bits/stdc++.h>
using namespace std;
 
#define fi first
#define se second
#define NAME ""
 
typedef long long ll;
typedef unsigned long long ull;
typedef double de;
const int MOD = (int) 1e9 + 7;
const int N = (int) 2e5 + 7;
 
string s;
int dl[4] = {-1, 0, 1, 0},
    dr[4] = {0, 1, 0, -1};
int tmp[48];
bool check[9][9];
 
int solve(int index, int l, int r) {
    if ((check[l][r-1] && check[l][r+1]) && (!check[l-1][r] && !check[l+1][r]))
        return 0;
    if ((!check[l][r-1] && !check[l][r+1]) && (check[l-1][r] && check[l+1][r]))
        return 0;
    if (l == 7 && r == 1) {
        if (index == 48)
            return 1;
        return 0;
    }
    if (index == 48)
        return 0;
    int res = 0;
    check[l][r] = true;
    if (tmp[index] < 4) {
        int tmpl = l + dl[tmp[index]];
        int tmpr = r + dr[tmp[index]];
        if (!check[tmpl][tmpr])
            res += solve(index + 1, tmpl, tmpr);
    }
    else {
        for (int i=0; i<4; ++i) {
            int tmpl = l + dl[i];
            int tmpr = r + dr[i];
            if (check[tmpl][tmpr])
                continue;
            res += solve(index + 1, tmpl, tmpr);
        }
    }
    check[l][r] = false;
    return res;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    #ifdef LOCAL
    freopen(NAME".INP","r",stdin);
    freopen(NAME".OUT","w",stdout);
    #endif
 
    getline(cin, s);
    for (int i=0; i<48; ++i) {
        if (s[i] == 'U')
            tmp[i] = 0;
        else if (s[i] == 'R')
            tmp[i] = 1;
        else if (s[i] == 'D')
            tmp[i] = 2;
        else if (s[i] == 'L')
            tmp[i] = 3;
        else
            tmp[i] = 4;
    }
    for (int i=0; i<9; ++i) {
        check[0][i] = true;
        check[8][i] = true;
        check[i][0] = true;
        check[i][8] = true;
    }
    for (int i=1; i<=7; ++i) {
        for (int j=1; j<=7; ++j)
            check[i][j] = false;
    }
    cout << solve(0, 1, 1);
 
    return 0;
}