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
 
int n;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    //freopen(NAME".INP","r",stdin);
    //freopen(NAME".OUT","w",stdout);
 
    cin >> n;
    vector <int> v(n);
    for (int i=0; i<n; ++i)
        v[i] = i + 1;
    while (v.size() > 1) {
        vector <int> vt;
        for (int i=0; i<v.size(); ++i) {
            if (i%2 == 0)
                vt.push_back(v[i]);
            else
                cout << v[i] << " ";
        }
        if (v.size()%2 == 0)
            v = vt;
        else {
            int tmp = vt.back();
            vt.pop_back();
            v.clear();
            v.push_back(tmp);
            for (int x:vt)
                v.push_back(x);
        }
    }
    cout << v[0];
 
    return 0;
}
