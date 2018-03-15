#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll dp[1100][4100];
ll load[1100];
ll weight[1100];
ll n;
ll solve(ll pos,ll cur_load)
{
    if(pos>=n)
    {
        return 0;
    }
    if(dp[pos][cur_load]!=-1)
    {
        return dp[pos][cur_load];
    }
    if(cur_load==4000)
    {
        ll ans1=1+solve(pos+1,load[pos+1]);
        ll ans2=solve(pos+1,cur_load);
        return dp[pos][cur_load]=max(ans1,ans2);
    }
    ll ans1=0;
    if(weight[pos+1]<=cur_load)
    {
        ans1=1+solve(pos+1,min(cur_load-weight[pos+1],load[pos+1]));
    }
    ll ans2=solve(pos+1,cur_load);
    return dp[pos][cur_load]=max(ans1,ans2);
}
int main()
{
    while(scanf("%lld",&n))
    {
        if(n==0)
        {
            break;
        }
        for(ll i=0;i<=n;i++)
        {
            for(ll j=0;j<=4000;j++)
            {
                dp[i][j]=-1;
            }
        }
        for(ll i=1;i<=n;i++)
        {
            scanf("%lld%lld",&weight[i],&load[i]);
        }
        ll ans=solve(0,4000);
        printf("%lld\n",ans);
    }
    return 0;
}
