#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll money[103];
double dp[103][10005];
double prob[103];
int main()
{
    for(ll j=0; j<10005; j++)
    {
        dp[0][j]=2.00;
    }
    for(ll j=0; j<103; j++)
    {
        dp[j][0]=0.00;
    }
    ll tes,n,sum;
    double ff;
    scanf("%lld",&tes);
    for(ll i=1; i<=tes; i++)
    {
        scanf("%lf%lld",&ff,&n);
        sum=0;
        for(ll j=1; j<=n; j++)
        {
            scanf("%lld%lf",&money[j],&prob[j]);
            sum+=money[j];
        }
        ll res=0.00;
        for(ll j=1;j<=sum;j++)
        {
            for(ll k=1;k<=n;k++)
            {
                if(j<money[k])
                {
                    dp[k][j]=dp[k-1][j];
                }
                else
                {
                    dp[k][j]=min(dp[k-1][j],prob[k]+((1-prob[k])*dp[k-1][j-money[k]]));
                }
            }
            if(dp[n][j]-ff<-1E-7)
            {
                res=j;
            }
        }
        printf("Case %lld: %lld\n",i,res);
    }
    return 0;
}
