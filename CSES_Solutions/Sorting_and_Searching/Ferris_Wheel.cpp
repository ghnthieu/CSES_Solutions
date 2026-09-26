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
 
int n, x, a[N];
bool check[N];
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    //freopen(NAME".INP","r",stdin);
    //freopen(NAME".OUT","w",stdout);
 
    cin >> n >> x;
    for (int i=0; i<n; ++i)
        cin >> a[i];
    sort(a, a+n);
    memset(check, false, sizeof(check));
    int l = 0, r = n - 1, cnt = 0;
    while (l < r) {
        if (a[l] + a[r] > x)
            --r;
        else {
            ++cnt;
            check[l] = check[r] = true;
            ++l;
            --r;
        }
    }
    for (int i=0; i<n; ++i)
        cnt += check[i] == false;
    cout << cnt;
 
    return 0;
}