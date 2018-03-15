#include <bits/stdc++.h>
using namespace std;
#define ll long long
double dp[110][10010];
double per[110];
ll percentage[110];
ll n,x;
double solve(ll pos,ll per_now)
{
    if(pos>=n)
    {
        if(per_now>5000)
        {
            return dp[pos][per_now]=(((double)percentage[1]/(double)per_now)*(100.00));
        }
        else
        {
            return 0.00;
        }
    }
    if(dp[pos][per_now]!=-1.00)
    {
        return dp[pos][per_now];
    }
    if(per_now>5000)
    {
        return dp[pos][per_now]=(((double)percentage[1]/(double)per_now)*(100.00));
    }
    double ans1=solve(pos+1,per_now+percentage[pos+1]);
    double ans2=solve(pos+1,per_now);
    if((ans1-ans2)>0.00)
    {
        return dp[pos][per_now]=ans1;
    }
    else
    {
        return dp[pos][per_now]=ans2;
    }
}
int main()
{
    while(scanf("%lld%lld",&n,&x))
    {
        if(n==0&&x==0)
        {
            break;
        }
        for(ll i=1;i<=n;i++)
        {
            scanf("%lf",&per[i]);
        }
        percentage[1]=(ll)(per[x]*100.00);
        ll count1=2;
        for(ll i=1;i<=n;i++)
        {
            if(i==x)
            {
                continue;
            }
            else
            {
                percentage[count1]=(ll)(per[i]*100.00);
                count1++;
            }
        }
        for(ll i=0;i<=n;i++)
        {
            for(ll j=0;j<=10000;j++)
            {
                dp[i][j]=-1.00;
            }
        }
        double ans=solve(1,percentage[1]);
        printf("%0.2lf\n",ans);
    }
    return 0;
}
