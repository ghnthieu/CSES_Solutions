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
 
string s;
set <string> ans;
 
void solve(string s1, string s2) {
    if (s2.length() == 0) {
        ans.insert(s1);
        return;
    }
    for (int i=0; i<s2.length(); ++i)
        solve(s1 + s2[i], s2.substr(0, i) + s2.substr(i + 1));
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    //freopen(NAME".INP","r",stdin);
    //freopen(NAME".OUT","w",stdout);
 
    cin >> s;
    solve("", s);
    cout << ans.size() << '\n';
    for (auto x:ans)
        cout << x << '\n';
 
    return 0;
}