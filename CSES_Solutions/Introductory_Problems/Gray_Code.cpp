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
vector <string> ans;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    //freopen(NAME".INP","r",stdin);
    //freopen(NAME".OUT","w",stdout);
 
    cin >> n;
    ans.push_back("");
    for (int i=0; i<n; ++i) {
        int sz = ans.size();
        for (int j=sz-1; j>=0; --j)
            ans.push_back(ans[j]);
        sz *= 2;
        for (int j=0; j<sz; ++j) {
            if (j < ans.size() / 2)
                ans[j] += "0";
            else
                ans[j] += "1";
        }
    }
    for (int i=0; i<ans.size(); ++i)
        reverse(ans[i].begin(), ans[i].end());
    for (int i=0; i<ans.size(); ++i)
        cout << ans[i] << '\n';
 
    return 0;
}