#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll dp[1005][35];
ll cost[1005];
ll weight[1005];
ll num_of_objects;
ll tot_weight;
ll solve(ll pos,ll cur_weight)
{
    if(pos>num_of_objects)
    {
        return 0;
    }
    else if(dp[pos][cur_weight]!=-1)
    {
        return dp[pos][cur_weight];
    }
    else
    {
        ll res1=0,res2=0;
        if(weight[pos]+cur_weight<=tot_weight)
        {
            res1=cost[pos]+solve(pos+1,weight[pos]+cur_weight);
        }
        res2=solve(pos+1,cur_weight);
        return dp[pos][cur_weight]=max(res1,res2);
    }
}
int main()
{
    ll tes,peo_fam,total;
    scanf("%lld",&tes);
    for(int k=1;k<=tes;k++)
    {
        scanf("%lld",&num_of_objects);
        for(int i=1;i<=num_of_objects;i++)
        {
            scanf("%lld%lld",&cost[i],&weight[i]);
        }
        scanf("%lld",&peo_fam);
        total=0;
        for(int i=1;i<=peo_fam;i++)
        {
            memset(dp,-1,sizeof(dp));
            scanf("%lld",&tot_weight);
            total=total+solve(1,0);
        }
        printf("%lld\n",total);
    }
    return 0;
}
