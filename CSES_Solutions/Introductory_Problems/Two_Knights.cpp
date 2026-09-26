#include <bits/stdc++.h>
using namespace std;
 
#define fi first
#define se second
#define NAME ""
 
typedef long long ll;
typedef double de;
const int MOD = (int) 1e9+7;
 
int n;
ll a[1000011];
pair <int,int> duoi[4] = {{1,-2},{2,-1},{2,1},{1,2}};
pair <int,int> tren[4] = {{-2,1},{-1,2},{1,2},{2,1}};
 
void solve(int n) {
    a[n] = a[n-1];
    int s = n*n-1;
    for(int i=1; i<=n; ++i) {
        a[n] += s;
        --s;
        for(int j=0; j<=3; ++j) {
            int x = 1 + duoi[j].fi;
            int y = i + duoi[j].se;
            if (x > 1 && x <= n && y >= 1 && y <= n)
                --a[n];
        }
    }
    for(int i=2; i<=n; ++i) {
        a[n] += s;
        --s;
        for(int j=0; j<=3; ++j) {
            int x = i + tren[j].fi;
            int y = 1 + tren[j].se;
            if(x > 1 && x <= n && y > 1 && y <= n)
                --a[n];
        }
    }
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    //freopen(NAME".INP","r",stdin);
    //freopen(NAME".OUT","w",stdout);
 
    cin >> n;
    a[1] = 0;
    for (int i=2; i<=n; ++i)
        solve(i);
    for (int i=1; i<=n; ++i)
        cout << a[i] << endl;
 
    return 0;
}