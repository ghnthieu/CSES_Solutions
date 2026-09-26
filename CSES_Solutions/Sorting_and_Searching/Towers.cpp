#include bitsstdc++.h
using namespace std;
 
#define fi first
#define se second
#define NAME 
 
typedef long long ll;
typedef unsigned long long ull;
typedef double de;
const int MOD = (int) 1e9 + 7;
const int N = (int) 2e5 + 7;
 
int n;
multiset int ms;
 
int main() {
    ios_basesync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen(NAME.INP,r,stdin);
    freopen(NAME.OUT,w,stdout);
 
    cin  n;
    for (int i=0; in; ++i) {
        int x; cin  x;
        auto it = ms.upper_bound(x);
        if (it != ms.end())
            ms.erase(it);
        ms.insert(x);
    }
    cout  ms.size();
 
    return 0;
}
