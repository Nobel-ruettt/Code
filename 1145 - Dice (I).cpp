#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 100000007
ll dp[2][15004];
ll tes,n,k,s;
void cle()
{
    for(ll j=0; j<=s; j++)
    {
        dp[1][j]=dp[0][j];
        dp[0][j]=0;
    }
}
void cle2()
{
    for(ll i=0; i<=s; i++)
    {
        dp[1][i]=0;
    }
    dp[1][s]=1;
}
int main()
{
    scanf("%lld",&tes);
    for(ll cas=1; cas<=tes; cas++)
    {
        scanf("%lld%lld%lld",&n,&k,&s);
        if(s==0)
        {
            printf("Case %lld: 0\n",cas);
            continue;
        }
        cle2();
        for(ll i=1; i<=n; i++)
        {
            if(i>=2)
            {
                cle();
            }
            for(ll j=0; j<=s; j++)
            {
                if(j==0)
                {
                    if(j+k<=s)
                    {
                        dp[0][j]=(dp[1][j+k]%mod)-(dp[1][j]%mod);
                        if(dp[0][j]<0)
                        {
                            dp[0][j]+=mod;
                        }
                    }
                    else if(j+k>s)
                    {
                        dp[0][j]=(dp[1][s]%mod)-(dp[1][j]%mod);
                        if(dp[0][j]<0)
                        {
                            dp[0][j]+=mod;
                        }
                    }
                }
                else
                {
                    if(j+k<=s)
                    {
                        dp[0][j]=(dp[1][j+k]%mod)-(dp[1][j]%mod);
                        if(dp[0][j]<0)
                        {
                            dp[0][j]+=mod;
                        }
                        dp[0][j]+=dp[0][j-1];
                    }
                    else if(j+k>s)
                    {
                        dp[0][j]=(dp[1][s]%mod)-(dp[1][j]%mod);
                        if(dp[0][j]<0)
                        {
                            dp[0][j]+=mod;
                        }
                        dp[0][j]+=dp[0][j-1];
                    }
                }
            }
        }
        printf("Case %lld: %lld\n",cas,dp[0][0]);
    }
    return 0;
}
