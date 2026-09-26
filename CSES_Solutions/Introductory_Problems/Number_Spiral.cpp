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
 
int t;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    //freopen(NAME".INP","r",stdin);
    //freopen(NAME".OUT","w",stdout);
 
    cin >> t;
    while (t--) {
        ll x, y; cin >> x >> y;
        if (x < y) {
            if (y%2 == 0)
                cout << (y - 1) * (y - 1) + 1 + x - 1;
            else
                cout << y * y - x + 1;
        }
        else {
            if (x%2 == 0)
                cout << x * x - y + 1;
            else
                cout << (x - 1) * (x - 1) + 1 + y - 1;
        }
        cout << '\n';
    }
 
    return 0;
}