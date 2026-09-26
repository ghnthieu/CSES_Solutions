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
 
int n, ans[N];
priority_queue <pair <int,int>> pq;
vector <pair <pair <int,int>, int>> vpp(N);
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    //freopen(NAME".INP","r",stdin);
    //freopen(NAME".OUT","w",stdout);
 
    cin >> n;
    vpp.resize(n);
    for (int i=0; i<n; ++i) {
        cin >> vpp[i].fi.fi >> vpp[i].fi.se;
        vpp[i].se = i;
    }
    sort(vpp.begin(), vpp.end());
    int last = 0, cnt = 0;
    for (int i=0; i<n; ++i) {
        if (pq.empty()) {
            ++last;
            pq.push(make_pair(-vpp[i].fi.se, last));
            ans[vpp[i].se] = last;
        }
        else {
            pair <int,int> mn = pq.top();
            if (-mn.fi < vpp[i].fi.fi) {
                pq.pop();
                pq.push(make_pair(-vpp[i].fi.se, mn.se));
                ans[vpp[i].se] = mn.se;
            }
            else {
                ++last;
                pq.push(make_pair(-vpp[i].fi.se, last));
                ans[vpp[i].se] = last;
            }
        }
        cnt = max(cnt, (int) pq.size());
    }
    cout << cnt << '\n';
    for (int i=0; i<n; ++i)
        cout << ans[i] << " ";
 
    return 0;
}