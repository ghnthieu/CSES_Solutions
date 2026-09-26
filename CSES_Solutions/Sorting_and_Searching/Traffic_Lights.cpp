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
 
int x, n, a[N];
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    //freopen(NAME".INP","r",stdin);
    //freopen(NAME".OUT","w",stdout);
 
    cin >> x >> n;
    set <int> st {0, x};
    multiset <int> ms {x};
    for (int i=0; i<n; ++i) {
        int val; cin >> val;
        auto it1 = st.upper_bound(val);
        auto it2 = it1;
        --it2;
        ms.erase(ms.find(*it1 - *it2));
        ms.insert(val - *it2);
        ms.insert(*it1 - val);
        st.insert(val);
        auto ans = ms.end();
        --ans;
        cout << *ans << " ";
    }
 
    return 0;
}