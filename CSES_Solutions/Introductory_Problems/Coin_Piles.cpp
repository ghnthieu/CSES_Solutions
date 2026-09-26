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
        int a, b;
        cin >> a >> b;
        if ((a + b) % 3 == 0 && min(a, b) * 2 >= max(a, b))
            cout << "YES" << '\n';
        else
            cout << "NO" << '\n';
    }
 
    return 0;
}