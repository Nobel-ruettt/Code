#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn 500005
#define inf 90000000000
ll dp[2][maxn],heights,n;
vector<ll>h;
int main()
{
    ll tes;
    scanf("%lld",&tes);
    for(ll cas=1; cas<=tes; cas++)
    {
        h.clear();
        scanf("%lld",&n);
        ll sum=0;
        for(ll i=1; i<=n; i++)
        {
            scanf("%lld",&heights);
            h.push_back(heights);
            sum+=heights;
        }
        sort(h.begin(),h.end());
        reverse(h.begin(),h.end());
        for(ll i=0; i<=sum; i++)
        {
            dp[1][i]=-inf;
            dp[0][i]=-inf;
        }
        dp[1][0]=0;
        for(ll i=0;i<h.size();i++)
        {
            if(i>0)
            {
                for(ll j=0;j<=sum;j++)
                {
                    dp[1][j]=dp[0][j];
                }
            }
            for(ll j=0;j<=sum;j++)
            {
                if(j==0)
                {
                    dp[0][j]=max(dp[1][j],h[i]+dp[1][j+h[i]]);
                    continue;
                }
                dp[0][j]=dp[1][j];
                if(j+h[i]<=sum)
                {
                    dp[0][j]=max(dp[1][j+h[i]]+h[i],dp[0][j]);
                    if(j<=h[i])
                    {
                        ll diff=labs(j-h[i]);
                        dp[0][j]=max(dp[0][j],dp[1][diff]+h[i]);
                    }
                    else if(j>h[i])
                    {
                        ll diff=labs(j-h[i]);
                        dp[0][j]=max(dp[0][j],dp[1][diff]+h[i]);
                    }
                }
                else
                {
                    if(j<=h[i])
                    {
                        ll diff=labs(j-h[i]);
                        dp[0][j]=max(dp[0][j],dp[1][diff]+h[i]);
                    }
                    else if(j>h[i])
                    {
                        ll diff=labs(j-h[i]);
                        dp[0][j]=max(dp[0][j],dp[1][diff]+h[i]);
                    }
                }
                if(dp[0][j]<0)
                {
                    dp[0][j]=-inf;
                }
            }
        }
        if(dp[0][0]<=0)
        {
            printf("Case %lld: impossible\n",cas);
        }
        else
        {
            printf("Case %lld: %lld\n",cas,dp[0][0]/2);
        }
    }
    return 0;
}
