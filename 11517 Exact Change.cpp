#include <bits/stdc++.h>
using namespace std;
#define ll long long
struct node
{
    int amount;
    int taken;
};
node dp[110][2][12000];
int coins[110];
int make;
int num_of_coins;
node solve(int pos,int state,int cur_amount)
{
    if(pos>=num_of_coins)
    {
        node res;
        if(cur_amount<make)
        {
            res.amount=INT_MAX;
            res.taken=state;
        }
        if(cur_amount>=make)
        {
            res.amount=cur_amount;
            res.taken=state;
        }
        return res;
    }
    if(dp[pos][state][cur_amount].amount!=-1 && dp[pos][state][cur_amount].taken!=-1)
    {
        return dp[pos][state][cur_amount];
    }
    if(cur_amount>=make)
    {
        node res1;
        res1.amount=cur_amount;
        res1.taken=state;
        return res1;
    }
    node res2,res3;
    res2=solve(pos+1,1,cur_amount+coins[pos]);
    res3=solve(pos+1,0,cur_amount);
    if(res2.amount<res3.amount)
    {
        res2.taken=res2.taken+state;
        return dp[pos][state][cur_amount]=res2;
    }
    else if(res3.amount<res2.amount)
    {
        res3.taken=res3.taken+state;
        return dp[pos][state][cur_amount]=res3;
    }
    else if(res3.amount==res2.amount)
    {
        if(res3.taken<res2.taken)
        {
            res3.taken=res3.taken+state;
            return dp[pos][state][cur_amount]=res3;
        }
        if(res2.taken<res3.taken)
        {
            res2.taken=res2.taken+state;
            return dp[pos][state][cur_amount]=res2;
        }
        if(res2.taken==res3.taken)
        {
            res2.taken=res2.taken+state;
            return dp[pos][state][cur_amount]=res2;
        }
    }
}
int main()
{
    int tes;
    scanf("%d",&tes);
    for(int k=1;k<=tes;k++)
    {
        scanf("%d",&make);
        scanf("%d",&num_of_coins);
        for(int i=0;i<=num_of_coins;i++)
        {
             for(int j=0;j<2;j++)
             {
                 for(int k=0;k<12000;k++)
                 {
                     dp[i][j][k].amount=-1;
                     dp[i][j][k].taken=-1;
                 }
             }
        }
        for(int i=0;i<num_of_coins;i++)
        {
            scanf("%d",&coins[i]);
        }
        node ans=solve(0,0,0);
        printf("%d %d\n",ans.amount,ans.taken);
    }
    return 0;
}
