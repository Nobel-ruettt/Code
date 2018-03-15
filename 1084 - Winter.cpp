#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define inf 100000000
ll n,k,co;
vector<ll>co_ordinates;
ll dp[100005];
ll binary_lower(ll number)
{
    ll low=0;
    ll high=co_ordinates.size();
    ll mid;
    while(low<=high)
    {
        mid=(low+high)/2;
        if(co_ordinates[mid]<number)
        {
            low=mid+1;
        }
        else if(co_ordinates[mid]>number)
        {
            high=mid-1;
        }
        else if(co_ordinates[mid]==number)
        {
            return mid;
        }
    }
    return high;
}
ll solve(ll pos)
{
    if(pos==co_ordinates.size())
    {
        return 0;
    }
    if(dp[pos]!=-1)
    {
        return dp[pos];
    }
    ll upper=binary_lower(co_ordinates[pos]+2*k);
    if((upper-pos+1)<3)
    {
        return dp[pos]=inf;
    }
    if((upper-pos+1)>=3)
    {
        ll mini=inf;
        upper++;
        ll lower=pos+3;
        for(ll i=lower;i<=upper;i++)
        {
            ll ans=1+solve(i);
            if(ans<mini)
            {
                mini=ans;
            }
        }
        return dp[pos]=mini;
    }
}
int main()
{
    ll tes;
    scanf("%lld",&tes);
    for(ll cas=1;cas<=tes;cas++)
    {
        co_ordinates.clear();
        scanf("%lld%lld",&n,&k);
        for(ll i=1;i<=n;i++)
        {
            scanf("%lld",&co);
            co_ordinates.push_back(co);
        }
        sort(co_ordinates.begin(),co_ordinates.end());
        memset(dp,-1,sizeof dp);
        ll ans=solve(0);
        if(ans==inf)
        {
            printf("Case %lld: -1\n",cas);
        }
        else
        {
            printf("Case %lld: %lld\n",cas,ans);
        }
    }
    return 0;
}
