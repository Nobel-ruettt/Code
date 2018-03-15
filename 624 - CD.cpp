#include <bits/stdc++.h>
using namespace std;
struct node
{
    int taken;
    vector<int>cd;
};
int make;
int num_of_coins;
int coins[30];
node solve(int pos,int cur_amount)
{
    if(pos>=num_of_coins)
    {
        node res;
        res.taken=cur_amount;
        return res;
    }
    else
    {
        node res1,res2,res3;
        res1.taken=0;
        if(cur_amount+coins[pos]<=make)
        {
            res1=solve(pos+1,cur_amount+coins[pos]);
            res1.cd.push_back(pos+1);
        }
        res2=solve(pos+1,cur_amount);
        if(res1.taken>res2.taken)
        {
            res3.taken=res1.taken;
            res3.cd.swap(res1.cd);
            return res3;
        }
        else if(res2.taken>res1.taken)
        {
            res3.taken=res2.taken;
            res3.cd.swap(res2.cd);
            return res3;
        }
        else if(res2.taken==res1.taken)
        {
            res3.taken=res2.taken;
            res3.cd.swap(res2.cd);
            return res3;
        }
    }
}
int main()
{
    while(scanf("%d",&make))
    {
        scanf("%d",&num_of_coins);
        for(int i=0;i<num_of_coins;i++)
        {
            scanf("%d",&coins[i]);
        }
        node ans=solve(0,0);
        for(int i=0;i<ans.cd.size();i++)
        {
            printf("%d ",coins[ans.cd[i]-1]);
        }
        printf("sum:%d\n",ans.taken);
    }
    return 0;
}
