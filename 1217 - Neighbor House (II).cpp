#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxi 1004
ll dp[maxi][2];
ll value[maxi];
ll n;
ll solve(ll pos,ll one)
{
    if(pos>=n+1)
    {
        return 0;
    }
    if(pos==n&&one==1)
    {
        return 0;
    }
    if(dp[pos][one]!=-1)
    {
        return dp[pos][one];
    }
    ll x=solve(pos+1,one);
    if(pos==1)
    {
        one=1;
    }
    ll y=value[pos]+solve(pos+2,one);
    return dp[pos][one]=max(x,y);
}
int main()
{
    ll tes;
    scanf("%lld",&tes);
    for(ll cas=1;cas<=tes;cas++)
    {
        scanf("%lld",&n);
        memset(dp,-1,sizeof(dp));
        for(ll i=1;i<=n;i++)
        {
            scanf("%lld",&value[i]);
        }
        ll ans=solve(1,0);
        printf("Case %lld: %lld\n",cas,ans);
    }
    return 0;
}
