#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define dd double
#define maxi 100005
dd dp[maxi];
int main()
{
    ll tes,n;
    dd tot_size;
    scanf("%lld",&tes);
    for(ll cas=1;cas<=tes;cas++)
    {
        scanf("%lld",&n);
        dp[0]=0.000;
        tot_size=(double)n;
        for(ll i=1;i<=n;i++)
        {
            dp[i]=(tot_size/(double)i)+dp[i-1];
        }
        printf("Case %lld: %0.9lf\n",cas,dp[n]);
    }
    return 0;
}
