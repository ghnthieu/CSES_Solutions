#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll tknp(ll n,pair<ll,ll> a[],ll be,ll gt)
{
    ll l=be,r=n;
    while(l<=r)
    {
        ll mid=(l+r)/2;
        if(a[mid].first==gt) return mid;
        else if(a[mid].first>gt) r=mid-1;
        else l=mid+1;
    }
    return -1;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll n,s;
    cin>>n>>s;
    pair<ll,ll> a[n+1];
    for(int i=1;i<=n;i++)
    {
        cin>>a[i].first;
        a[i].second=i;
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n-2;i++)
    {
        ll t=s-a[i].first;
        for(int j=i+1;j<=n-1;j++)
        {
            ll l=tknp(n,a,j+1,t-a[j].first);
            if(l!=-1)
            if(a[l].first==t-a[j].first)
            {
                cout<<a[i].second<<" "<<a[j].second<<" "<<a[l].second;
                return 0;
            }
        }
    }
    cout<<"IMPOSSIBLE";
    return 0;
}