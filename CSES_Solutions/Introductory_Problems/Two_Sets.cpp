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
 
int n;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    //freopen(NAME".INP","r",stdin);
    //freopen(NAME".OUT","w",stdout);
 
    cin >> n;
    if (n%4 == 1 || n%4 == 2)
        cout << "NO";
    else if (n%4 == 3) {
        cout << "YES" << '\n' << n/2 << '\n';
        for (int i=2; i<=n/2; i+=2)
            cout << i << " " << n-i << " ";
        cout << n << '\n' << n/2+1 << '\n';
        for (int i=1; i<=n/2; i+=2)
            cout << i << " " << n-i << " ";
    }
    else {
        cout << "YES" << '\n' << n/2 << '\n';
        for (int i=2; i<=n/2; i+=2)
            cout << i << " " << n-i+1 << " ";
        cout << '\n' << n/2 << '\n';
        for (int i=1; i<=n/2; i+=2)
            cout << i << " " << n-i+1 << " ";
    }
 
    return 0;
}