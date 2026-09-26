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
    if (n == 1)
        cout << 1;
    else if (n < 4)
        cout << "NO SOLUTION";
    else if (n == 4)
        cout << "2 4 1 3";
    else {
        for (int i=1; i<=n; i+=2)
            cout << i << " ";
        for (int i=2; i<=n; i+=2) {
            cout << i;
            if (i + 2 <= n)
                cout << " ";
        }
    }
 
    return 0;
}