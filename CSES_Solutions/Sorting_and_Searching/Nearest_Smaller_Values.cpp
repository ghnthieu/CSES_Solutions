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
 
int n, a[N], mn[N];
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    //freopen(NAME".INP","r",stdin);
    //freopen(NAME".OUT","w",stdout);
 
    cin >> n;
    for (int i=0; i<n; ++i) {
        cin >> a[i];
        int j = i - 1;
        while (a[j] >= a[i])
            j = mn[j];
        mn[i] = j;
        cout << mn[i] + 1 << " ";
    }
 
    return 0;
}