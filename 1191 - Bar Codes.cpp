#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll tes,make,k,m;
ll dp[55][55];
ll solve(ll pos,ll length)
{
    for(ll j=1;j)
}
int main()
{
    scanf("%lld",&tes);
    for(ll cas=1;cas<=tes;cas++)
    {
        scanf("%lld%lld%lld",&make,&k,&m);
        memset(dp,-1,sizeof dp);
        ll ans=solve(1,0);
        printf("Case %lld: %lld\n",cas,ans);
    }
    return 0;
}
