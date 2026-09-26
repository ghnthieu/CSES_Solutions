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
 
int n, m;
multiset <int> ms;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    //freopen(NAME".INP","r",stdin);
    //freopen(NAME".OUT","w",stdout);
 
    cin >> n >> m;
    for (int i=0; i<n; ++i) {
        int x; cin >> x;
        ms.insert(x);
    }
    for (int i=0; i<m; ++i) {
        int x; cin >> x;
        auto it = ms.upper_bound(x);
        if (it == ms.begin())
            cout << -1 << '\n';
        else {
            cout << *(--it) << '\n';
            ms.erase(it);
        }
    }
 
    return 0;
}