#include <bits/stdc++.h>
using namespace std;
 
#define fi first
#define se second
#define NAME ""
 
typedef long long ll;
typedef unsigned long long ull;
typedef double de;
const int MOD = (int) 1e9 + 7;
const int N = (int) 1e5 + 7;
 
char a[8][8];
int ans = 0;
int l[15], r[15], row[7];
 
void solve(int i) {
    if (i == 8) {
        ++ans;
        return;
    }
    for (int j=0; j<8; ++j) {
        if (a[j][i] == '.' && l[j - i + 7] == 0 && r[j + i] == 0 && row[j] == 0) {
            l[j - i + 7] = 1;
            r[j + i] = 1;
            row[j] = 1;
            solve(i + 1);
            l[j - i + 7] = 0;
            r[j + i] = 0;
            row[j] = 0;
        }
    }
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    //freopen(NAME".INP","r",stdin);
    //freopen(NAME".OUT","w",stdout);
 
    for (int i=0; i<8; ++i) {
        for (int j=0; j<8; ++j)
            cin >> a[i][j];
    }
    solve(0);
    cout << ans;
 
    return 0;
}