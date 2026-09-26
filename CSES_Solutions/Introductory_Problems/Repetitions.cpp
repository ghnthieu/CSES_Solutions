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
 
string s;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    //freopen(NAME".INP","r",stdin);
    //freopen(NAME".OUT","w",stdout);
 
    cin >> s;
    int mx = 1, tmp = s[0], cnt = 1;
    for (int i=1; i<s.length(); ++i) {
        if (s[i] == tmp)
            ++cnt;
        else {
            mx = max(mx, cnt);
            cnt = 1;
            tmp = s[i];
        }
    }
    mx = max(mx, cnt);
    cout << mx;
 
    return 0;
}