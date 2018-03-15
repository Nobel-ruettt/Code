#include <bits/stdc++.h>
using namespace std;
int floors;
int lefty[1005];
int righty[1005];
int lf_righty[1005];
int rt_lefty[1005];
long long dp_lefty[1005][2];
long long dp_righty[1005][2];
long long solve_lefty(int pos,int state)
{
    if(pos>=floors)
    {
        return 0;
    }
    if(dp_lefty[pos][state]!=-1)
    {
        return dp_lefty[pos][state];
    }
    long long res1=0,res2=0;
    if(state==0)
    {
        res1=lefty[pos]+solve_lefty(pos+1,0);
        res2=righty[pos]+lf_righty[pos]+solve_lefty(pos+1,1);
        dp_lefty[pos][state]=min(res1,res2);
        return dp_lefty[pos][state];
    }
    else if(state==1)
    {
        res1=lefty[pos]+rt_lefty[pos]+solve_lefty(pos+1,0);
        res2=righty[pos]+solve_lefty(pos+1,1);
        dp_lefty[pos][state]=min(res1,res2);
        return dp_lefty[pos][state];
    }
}
long long solve_righty(int pos,int state)
{
    if(pos>=floors)
    {
        return 0;
    }
    if(dp_righty[pos][state]!=-1)
    {
        return dp_righty[pos][state];
    }
    long long res1=0,res2=0;
    if(state==0)
    {
        res1=lefty[pos]+solve_righty(pos+1,0);
        res2=righty[pos]+lf_righty[pos]+solve_righty(pos+1,1);
        dp_righty[pos][state]=min(res1,res2);
        return dp_righty[pos][state];
    }
    else if(state==1)
    {
        res1=lefty[pos]+rt_lefty[pos]+solve_righty(pos+1,0);
        res2=righty[pos]+solve_righty(pos+1,1);
        dp_righty[pos][state]=min(res1,res2);
        return dp_righty[pos][state];
    }
}
int main()
{
    int tes;
    long long ans;
    scanf("%d",&tes);
    for(int i=1;i<=tes;i++)
    {
        scanf("%d",&floors);
        for(int j=0;j<floors;j++)
        {
            scanf("%d",&lefty[j]);
        }
        for(int j=0;j<floors;j++)
        {
            scanf("%d",&righty[j]);
        }
        for(int j=1;j<floors;j++)
        {
            scanf("%d",&lf_righty[j]);
        }
        for(int j=1;j<floors;j++)
        {
            scanf("%d",&rt_lefty[j]);
        }
        for(int j=0;j<=floors;j++)
        {
            for(int k=0;k<=2;k++)
            {
                dp_lefty[j][k]=-1;
                dp_righty[j][k]=-1;
            }
        }
        long long ans=lefty[0]+solve_lefty(1,0);
        long long ans2=righty[0]+solve_righty(1,1);
        printf("Case %d: %lld\n",i,min(ans,ans2));
    }
    return 0;
}
