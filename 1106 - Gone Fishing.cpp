#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll dp[30][1004][990];
ll profit[30];
ll decu[30];
ll highest[30];
ll ex[30];
ll n,make,h;
ll solve(ll pos,ll now_taken,ll now_weight)
{
    if(pos>=n+1)
    {
        return 0;
    }
    if(dp[pos][now_taken][now_weight]!=-1)
    {
        return dp[pos][now_taken][now_weight];
    }
    ll ans1=0,ans2=0;
    if(now_taken+1<=highest[pos])
    {
        if(now_weight+5<=make)
        {
            ans1=(profit[pos]-(decu[pos]*now_taken))+solve(pos,now_taken+1,now_weight+5);
        }
    }
    ans2=solve(pos+1,0,now_weight+ex[pos]);
    return dp[pos][now_taken][now_weight]=max(ans1,ans2);
}
int main()
{
    ll tes;
    scanf("%lld",&tes);
    for(ll cas=1;cas<=tes;cas++)
    {
        scanf("%lld%lld",&n,&h);
        make=h*60;
        for(ll i=1;i<=n;i++)
        {
            scanf("%lld",&profit[i]);
        }
        for(ll i=1;i<=n;i++)
        {
            scanf("%lld",&decu[i]);
        }
        for(ll i=1;i<n;i++)
        {
          scanf("%lld",&ex[i]);
        }
        for(ll i=1;i<=n;i++)
        {
            if(decu[i]==0)
            {
                highest[i]=1000;
                continue;
            }
            if(profit[i]%decu[i]==0)
            {
                highest[i]=profit[i]/decu[i];
            }
            else
            {
                highest[i]=profit[i]/decu[i];
                highest[i]++;
            }
        }
        ex[n]=0;
        memset(dp,-1,sizeof(dp));
        ll ans=solve(1,0,0);
        cout<<ans<<endl;
    }
    return 0;
}
