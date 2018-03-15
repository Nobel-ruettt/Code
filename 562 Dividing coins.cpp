#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll num_of_coins;
ll make;
ll coins[105];
ll dp[105][25100];
ll solve(ll pos,ll cur_amount)
{
    if(pos>=num_of_coins+1)
    {
        return cur_amount;
    }
    if(dp[pos][cur_amount]!=-1)
    {
        return dp[pos][cur_amount];
    }
    ll res1=0,res2=0;
    if(coins[pos]+cur_amount<=make)
    {
        res1=solve(pos+1,coins[pos]+cur_amount);
    }
    res2=solve(pos+1,cur_amount);
    return dp[pos][cur_amount]=max(res1,res2);
}
int main()
{
    ll tes,sum,ans1,ans2;
    scanf("%lld",&tes);
    for(int k=1;k<=tes;k++)
    {
        sum=0;
        memset(dp,-1,sizeof(dp));
        scanf("%lld",&num_of_coins);
        for(int i=1;i<=num_of_coins;i++)
        {
            scanf("%lld",&coins[i]);
            sum=sum+coins[i];
        }
        make=sum/2;
        ans1=solve(1,0);
        ans2=sum-ans1;
        printf("%lld\n",ans2-ans1);
    }
    return 0;
}
