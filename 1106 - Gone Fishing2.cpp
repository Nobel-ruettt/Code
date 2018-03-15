#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll dp[30][198][198];
ll dir[30][198][198];
ll profit[30];
ll decu[30];
ll solution[30];
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
        if(now_weight+1<=make)
        {
            ans1=(profit[pos]-(decu[pos]*now_taken))+solve(pos,now_taken+1,now_weight+1);
        }
    }
    ans2=solve(pos+1,0,now_weight+ex[pos]);
    if(ans1>ans2)
    {
        dir[pos][now_taken][now_weight]=1;
        dp[pos][now_taken][now_weight]=ans1;
    }
    else if(ans1<ans2)
    {
        dir[pos][now_taken][now_weight]=2;
        dp[pos][now_taken][now_weight]=ans2;
    }
    else if(ans1==ans2)
    {
        if(ans1!=0)
        {
          dir[pos][now_taken][now_weight]=1;
          dp[pos][now_taken][now_weight]=ans1;
        }
        else
        {
            dir[pos][now_taken][now_weight]=2;
            dp[pos][now_taken][now_weight]=ans2;
        }
    }
    return dp[pos][now_taken][now_weight];
}
void sol(ll pos,ll now_taken,ll now_weight)
{
    if(now_taken>0)
    {
        solution[pos]+=1;
    }
    if(dir[pos][now_taken][now_weight]==1)
    {
        sol(pos,now_taken+1,now_weight+1);
    }
    else if(dir[pos][now_taken][now_weight]==2)
    {
        sol(pos+1,0,now_weight+ex[pos]);
    }
    else if(dir[pos][now_taken][now_weight]==-1)
    {
        return ;
    }
}
int main()
{
    ll tes;
    scanf("%lld",&tes);
    for(ll cas=1;cas<=tes;cas++)
    {
        scanf("%lld%lld",&n,&h);
        make=(h*60)/5;
        cout<<"make "<<make<<endl;
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
                highest[i]=196;
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
        for(ll i=0;i<=n+2;i++)
        {
            for(ll j=0;j<198;j++)
            {
                for(ll k=0;k<=make;k++)
                {
                    dp[i][j][k]=-1;
                    dir[i][j][k]=-1;
                }
            }
            solution[i]=0;
        }
        ll ans=solve(1,0,0);
        printf("Case %lld:\n",cas);
        sol(1,0,0);
        ll sum=0;
        for(ll i=1;i<=n;i++)
        {
            sum+=solution[i]+ex[i];
        }
        if((make-sum)>0)
        {
            solution[1]+=(make-sum);
        }
        printf("%lld",solution[1]*5);
        for(ll i=2;i<=n;i++)
        {
            printf(", %lld",solution[i]*5);
        }
        printf("\n");
        printf("Number of fish expected: %lld\n",ans);
cout<<endl;
    }
    return 0;
}
