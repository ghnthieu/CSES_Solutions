#include <bits/stdc++.h>
using namespace std;
 
#define fi first
#define se second
#define NAME ""
 
typedef long long ll;
typedef double de;
const int MOD = (int) 1e9+7;
 
int n, k, a[200011];
multiset <int> l, r;
 
void chen(int tmp) {
    int t = *l.rbegin();
    if (t    < tmp) {
        r.insert(tmp);
        if (r.size() > k/2) {
            l.insert(*r.begin());
            r.erase(r.find(*r.begin()));
        }
    }
    else {
        l.insert(tmp);
        if (l.size() > (k+1)/2) {
            r.insert(*l.rbegin());
            l.erase(l.find(*l.rbegin()));
        }
    }
}
 
void xoa(int tmp) {
    if (r.find(tmp) != r.end())
        r.erase(r.find(tmp));
    else
        l.erase(l.find(tmp));
    if (l.empty()) {
        l.insert(*r.begin());
        r.erase(r.find(*r.begin()));
    }
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    //freopen(NAME".INP","r",stdin);
    //freopen(NAME".OUT","w",stdout);
 
    cin >> n >> k;
    for (int i=0; i<n; ++i)
        cin >> a[i];
    l.insert(a[0]);
    for (int i=1; i<k; ++i)
        chen(a[i]);
    cout << *l.rbegin() << " ";
    for (int i=k; i<n; ++i) {
        if (k == 1) {
            chen(a[i]);
            xoa(a[i-k]);
        }
        else {
            xoa(a[i-k]);
            chen(a[i]);
        }
        cout << *l.rbegin() << " ";
    }
 
    return 0;
}