#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod  100000007
ll coin[55];
ll koto[55];
ll dp[55][1005];
ll make;
ll num_of_coins;
ll solve(ll pos, ll cur_amount)
{
    if(pos>=num_of_coins+1)
    {
        if(cur_amount==make)
        {
            ///printf("base first pos %lld kotobar %lld cur_amount %lld\n",pos,taken,cur_amount);
            return 1;
        }
        else
        {
            ///printf("base 2nd pos %lld kotobar %lld cur_amount %lld\n",pos,taken,cur_amount);
            return 0;
        }
    }
    if(dp[pos][cur_amount]!=-1)
    {
        ///printf("agei paia gese pos %lld kotobar %lld cur_amount %lld\n",pos,taken,cur_amount);
        return dp[pos][cur_amount];
    }
    else
    {
        ll res1=0;
        ll res2=0;
        ///printf("maintate dhukse pos %lld kotobar %lld cur_amount %lld\n",pos,taken,cur_amount);
        ///printf("coin[pos]=%lld cur_amount=%lld make=%lld taken=%lld koto[pos]=%lld\n\n\n",coin[pos],cur_amount,make,taken,koto[pos]);

        for (ll gaba = 1; gaba <= koto[pos]; gaba++)
        {
            if (gaba*coin[pos] + cur_amount > make)
                break;
            if(gaba*coin[pos]+cur_amount<=make)
            {
                /// printf("arek balll er ball pos %lld kotobar %lld cur_amount %lld\n",pos,taken,cur_amount);
                res1 = (res1 + solve(pos + 1, coin[pos]*gaba+cur_amount))%mod;
            }
        }
        res2=solve(pos+1,cur_amount);
        ////printf("pos %lld taken %lld amount %lld\n",pos,taken,cur_amount);
        //printf("res1   %lld res2   %lld\n",res1,res2);
        return dp[pos][cur_amount]=((res1%mod+res2%mod)%mod);
    }
}
int main()
{
    ll tes;
    scanf("%lld",&tes);
    for(int i=1; i<=tes; i++)
    {
        scanf("%lld%lld",&num_of_coins,&make);
        memset(dp,-1,sizeof(dp));
        for(int j=1; j<=num_of_coins; j++)
        {
            scanf("%lld",&coin[j]);
        }
        for(int j=1; j<=num_of_coins; j++)
        {
            scanf("%lld",&koto[j]);
        }
        printf("Case %d: %lld\n",i,solve(1,0)%mod);
    }
    return 0;
}
