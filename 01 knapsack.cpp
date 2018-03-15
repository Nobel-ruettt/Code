#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll weight[200];///1 120 //প্রতিটা জিনিসের ওজন এবং দাম
//4 280
//3 150
//4 200
ll cost[200];
ll dp[200][200];
ll tot_weight;
ll num_of_objects;
ll solve(ll pos,ll cur_weight)
{
    if(pos>num_of_objects)
    {
        return 0;
    }
    else if(dp[pos][cur_weight]!=0)
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
    scanf("%lld",&num_of_objects);
    for(int i=1;i<=num_of_objects;i++)
    {
        scanf("%lld%lld",&weight[i],&cost[i]);
    }
    scanf("%lld",&tot_weight);
    printf("%lld\n",solve(1,0));
}
