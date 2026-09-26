#include <bits/stdc++.h>
using namespace std;
 
#define fi first
#define se second
#define NAME ""
 
typedef long long ll;
typedef unsigned long long ull;
typedef double de;
const int MOD = (int) 1e9 + 7;
const int N = (int) 3e1 + 7;
 
int t;
 
ll ltbinary(int a, int b) {
    if (b == 0)
        return 1;
    ll x = ltbinary(a, b/2);
    if (b%2 == 1)
        return x * x * a;
    else
        return x * x;
}
 
void solve(ll n) {
    if (n < 9) {
        cout << n + 1 << '\n';
        return;
    }
    int length = 1;
    while (9 * ltbinary(10, length - 1) * length < n) {
        n -= 9 * ltbinary(10, length - 1) * length;
        ++length;
    }
    string s = to_string(ltbinary(10, length - 1) + n / length);
    cout << (int) s[n % length] - '0' << '\n';
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    //freopen(NAME".INP","r",stdin);
    //freopen(NAME".OUT","w",stdout);
 
    cin >> t;
    while (t--) {
        ll n; cin >> n;
        solve(n - 1);
    }
 
    return 0;
}