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
    int val1, val2;
};
 
int n;
Data a[N];
 
bool cmp(Data a, Data b) {
    if (a.val2 == b.val2)
        return (a.val1 > b.val2);
    return (a.val2 < b.val2);
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    #ifdef LOCAL
    freopen(NAME".INP","r",stdin);
    freopen(NAME".OUT","w",stdout);
    #endif
 
    cin >> n;
    for (int i=0; i<n; ++i)
        cin >> a[i].val1 >> a[i].val2;
    sort(a, a+n, cmp);
    int left = -1, cnt = 0;
    for (int i=0; i<n; ++i) {
        if (a[i].val1 >= left) {
            left = a[i].val2;
            ++cnt;
        }
    }
    cout << cnt;
 
    return 0;
}
