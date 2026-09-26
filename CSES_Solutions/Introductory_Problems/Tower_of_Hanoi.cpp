#include <bits/stdc++.h>
using namespace std;
 
#define fi first
#define se second
#define NAME ""
 
typedef long long ll;
typedef unsigned long long ull;
typedef double de;
const int MOD = (int) 1e9 + 7;
const int N = (int) 1e2 + 7;
 
int n;
vector <pair <int,int>> ans;
 
void solve (int n, int a, int b, int c) {
    if (n == 1) {
        ans.push_back({a, c});
        return;
    }
    solve(n - 1, a, c, b);
    solve(1, a, b, c);
    solve(n - 1, b, a, c);
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    //freopen(NAME".INP","r",stdin);
    //freopen(NAME".OUT","w",stdout);
 
    cin >> n;
    solve(n, 1, 2, 3);
    cout << ans.size() << '\n';
    for (int i=0; i<ans.size(); ++i)
        cout << ans[i].fi << " " << ans[i].se << '\n';
 
    return 0;
}