#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll coins[]= {1,5,10,25,50};
ll dp[7][30003];
ll num_of_coins=5;
ll make;
ll solve(ll pos,ll cur_amount)
{
    if(pos>=num_of_coins)
    {
        if(cur_amount==0)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    if(dp[pos][cur_amount]!=-1)
    {
        return dp[pos][cur_amount];
    }
    ll res1=0,res2=0;
    if(cur_amount-coins[pos]>=0)
    {
        res1=solve(pos,cur_amount-coins[pos]);
    }
    res2=solve(pos+1,cur_amount);
    return dp[pos][cur_amount]=res1+res2;
}
int main()
{
    ll ans;
    memset(dp,-1,sizeof(dp));
    while(scanf("%lld",&make)!=EOF)
    {
        ans=solve(0,make);
        if(ans==1)
        {
            printf("There is only 1 way to produce %lld cents change.\n",make);
        }
        else
        {
            printf("There are %lld ways to produce %lld cents change.\n",ans,make);
        }
    }
    return 0;
}
