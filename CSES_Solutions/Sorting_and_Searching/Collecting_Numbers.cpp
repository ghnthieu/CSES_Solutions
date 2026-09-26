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
 
int n, indx[N];
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    #ifdef LOCAL
    freopen(NAME".INP","r",stdin);
    freopen(NAME".OUT","w",stdout);
    #endif
 
    cin >> n;
    for (int i=1; i<=n; ++i) {
        int x; cin >> x;
        indx[x] = i;
    }
    int cnt = 1, left = 1;
    for (int i=1; i<=n; ++i) {
        if (left > indx[i])
            ++cnt;
        left = indx[i];
    }
    cout << cnt;
 
    return 0;
}
