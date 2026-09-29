#include <bits/stdc++.h>
using namespace std;
 
#define fi first
#define se second
#define pb pop_back
#define pub push_back
#define __Trung_Hieu___ signed main()
#define mask(i) (1LL << (i))
#define bit(n, i) (((n) >> (i)) & 1)
#define all(v) v.begin(), v.end()
#define vec(kdl) vector <kdl>
#define ii(kdl1, kdl2) pair <kdl1, kdl2>
#define vii(kdl1, kdl2) vector <pair <kdl1, kdl2>>
#define For(i, l, r, up) for (int i = (l), _r = (r); i <= _r; i += up)
#define Ford(i, r, l, dw) for (int i = (r), _l = (l); i >= _l; i -= dw)
#define Rep(i, n) for (int i = 0, _n = (n); i < _n; ++i)
template <typename T1, typename T2> bool minimize(T1 &a, T2 b) { if (a > b) { a = b; return true; } return false; }
template <typename T1, typename T2> bool maximize(T1 &a, T2 b) { if (a < b) { a = b; return true; } return false; }
 
typedef long long ll;
typedef unsigned long long ull;
const int MOD = (int) 1e9 + 7;
const int N = (int) 1e5 + 7;
 
/*---------------------------------------------------------------*/
 
int city_num, flight_num;
 
struct Data {
    int pos;
    bool used;
    ll cost;
};
 
__Trung_Hieu___ {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    //freopen(".inp", "r", stdin);
    //freopen(".out", "w", stdout);
    // freopen("Input.txt", "r", stdin);
    // freopen("Output.txt", "w", stdout);
    //freopen("TEST.inp", "r", stdin);
    //freopen("TEST.out", "w", stdout);
 
    cin >> city_num >> flight_num;
 
    vec(vii(int, int)) neighbors(city_num);
    Rep(make_flight, flight_num) {
        int u, v, w; cin >> u >> v >> w;
        neighbors[--u].pub({--v, w});
    }
 
    vec(vec(ll)) min_cost(city_num, {INT64_MAX, INT64_MAX});
    min_cost[0] = {0, 0};
 
    auto cmp = [&](const Data &a, const Data &b) { return a.cost > b.cost; };
    priority_queue <Data, vec(Data), decltype(cmp)> frontier(cmp);
    frontier.push({0, false, 0});
    while (!frontier.empty()) {
        Data curr = frontier.top(); frontier.pop();
        ll curr_cost = min_cost[curr.pos][curr.used];
        if (curr_cost != curr.cost) continue;
        if (curr.pos == city_num - 1) break;
        for (auto [n, nc] : neighbors[curr.pos]) {
            if (!curr.used) {
                ll new_cost = curr_cost + nc / 2;
                if (minimize(min_cost[n][true], new_cost));
                    frontier.push(Data{n, true, new_cost});
            }
 
            if (minimize(min_cost[n][curr.used], curr_cost + nc))
                frontier.push(Data{n, curr.used, curr_cost + nc});
        }
    }
    cout << min_cost[city_num - 1][true];
 
    return 0;
}