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
 
string s;
map <char,int> mp;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    //freopen(NAME".INP","r",stdin);
    //freopen(NAME".OUT","w",stdout);
 
    cin >> s;
    for (int i=0; i<s.length(); ++i)
        ++mp[s[i]];
    int cnt = 0;
    for (auto x:mp) {
        if (x.se%2 != 0)
            ++cnt;
    }
    if (cnt > 1)
        cout << "NO SOLUTION";
    else {
        char ch;
        bool check = false;
        string tmp1 = "", tmp2 = "";
        for (auto x:mp) {
            int tmp = x.se;
            if (tmp%2 != 0) {
                --tmp;
                ch = x.fi;
                check = true;
            }
            while (tmp) {
                tmp1 += x.fi;
                tmp2 += x.fi;
                tmp -= 2;
            }
        }
        reverse(tmp2.begin(), tmp2.end());
        if (check)
            tmp1 += ch;
        cout << tmp1 << tmp2;
    }
 
    return 0;
}