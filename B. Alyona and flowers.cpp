#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<ll>arrr[110];
ll arr[110];
int main()
{
    ll n,m,left,right;
    cin>>n>>m;
    for(ll i=1;i<=n;i++)
    {
        scanf("%lld",&arr[i]);
    }
    ll maxi=0;
    for(ll i=1;i<=m;i++)
    {
        scanf("%lld%lld",&left,&right);
        ll ans=0;
        for(ll j=left;j<=right;j++)
        {
            ans+=arr[j];
        }
        if(ans>0)
        {
            maxi+=ans;
        }
    }
    cout<<maxi<<endl;
    return 0;
}
