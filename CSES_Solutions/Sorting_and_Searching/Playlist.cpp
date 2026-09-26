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
 
int n, a[N];
set <int> st;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    //freopen(NAME".INP","r",stdin);
    //freopen(NAME".OUT","w",stdout);
 
    cin >> n;
    for (int i=0; i<n; ++i)
        cin >> a[i];
    int left = 0, mx = 0, i = 0;
    while (i < n) {
        if (st.count(a[i]) == 1) {
            mx = max(mx, i - left);
            while (a[left] != a[i] && left < n - 1) {
                st.erase(a[left]);
                ++left;
            }
            ++left;
        }
        else
            st.insert(a[i]);
        mx = max(mx, i - left + 1);
        ++i;
    }
    cout << mx;
 
    return 0;
}