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
 
struct Data {
    int value, id;
};
 
int n, x;
Data a[N];
 
bool cmp(Data a, Data b) {
    return (a.value < b.value);
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    #ifdef LOCAL
    freopen(NAME".INP","r",stdin);
    freopen(NAME".OUT","w",stdout);
    #endif
 
    cin >> n >> x;
    for (int i=0; i<n; ++i) {
        cin >> a[i].value;
        a[i].id = i + 1;
    }
    sort(a, a+n, cmp);
    int l = 0, r = n - 1;
    while (l < r) {
        if (a[l].value + a[r].value == x) {
            cout << a[l].id << " " << a[r].id;
            return 0;
        }
        else if (a[l].value + a[r].value > x)
            --r;
        else
            ++l;
    }
    cout << "IMPOSSIBLE";
 
    return 0;
}
