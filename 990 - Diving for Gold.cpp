#include <bits/stdc++.h>
using namespace std;
#define ll long long
struct node
{
    ll taken;
    ll at_taken_gold;
    vector<int>positions;
};
node dp[40][1100];
ll coins[40];
ll depth[40];
ll times[40];
ll  make;
ll treasures;
node solve(ll pos,ll taken1,ll gold,ll time)
{
    if(pos>=treasures)
    {
        node res;
        res.taken=gold;
        res.at_taken_gold=gold;
        if(taken1==1)
        {
            res.positions.push_back(pos);
        }
        return dp[pos][time]=res;
    }
    node res1,res2,res3;
    res1.taken=0;
    res1.positions.clear();
    res2.taken=0;
    res2.positions.clear();
    if(time+times[pos]<=make)
    {
        res1=solve(pos+1,1,gold+coins[pos],time+times[pos]);
    }
    res2=solve(pos+1,0,gold,time);
    if(res2.taken>res1.taken)
    {
        res3.taken=res2.taken;
        res3.positions.swap(res2.positions);
        res3.at_taken_gold=gold;
        if(taken1==1)
        {
            res3.positions.push_back(pos);
        }
        return dp[pos][res3;
    }
    else if(res2.taken<res1.taken)
    {
        res3.taken=res1.taken;
        res3.positions.swap(res1.positions);
        res3.at_taken_gold=gold;
        if(taken1==1)
        {
            res3.positions.push_back(pos);
        }
        return res3;
    }
    else if(res2.taken==res1.taken)
    {
        res3.taken=res1.taken;
        res3.positions.swap(res1.positions);
        res3.at_taken_gold=gold;
        if(taken1==1)
        {
            res3.positions.push_back(pos);
        }
        return res3;
    }
}
int main()
{
    ll w;
    while(scanf("%lld%lld",&make,&w))
    {
        scanf("%lld",&treasures);
        for(int i=0;i<=treasures;i++)
        {
            for(int j=0;j<=make;j++)
            {
                dp[i][j].taken=-1;
                dp[i][j].positions.clear();
            }
        }
        for(int i=0;i<treasures;i++)
        {
            scanf("%lld%lld",&depth[i],&coins[i]);
            times[i]=(3*w)*depth[i];
        }
        node ans=solve(0,0,0,0);
    }
    return 0;
}
