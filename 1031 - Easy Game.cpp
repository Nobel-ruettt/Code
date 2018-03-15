#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll main_arr[110];
ll cumsum_arr[110];
ll dp[110][110];
ll n;
void cle()
{
    for(ll i=0;i<=n;i++)
    {
        cumsum_arr[i]=0;
    }
    memset(dp,-1,sizeof(dp));
}
ll solve(ll left,ll right)
{
    if(left==right)
    {
        return main_arr[left];
    }
    if(dp[left][right]!=-1)
    {
        return dp[left][right];
    }
    ll max_sum=cumsum_arr[right]-cumsum_arr[left-1];
    ll ans;
    for(ll i=left+1;i<=right;i++)
    {
        ans=(cumsum_arr[i-1]-cumsum_arr[left-1]-solve(i,right));
        if(ans>max_sum)
        {
            max_sum=ans;
        }
    }
    for(ll i=right-1;i>=left;i--)
    {
        ans=(cumsum_arr[right]-cumsum_arr[i])-solve(left,i);
        if(ans>max_sum)
        {
            max_sum=ans;
        }
    }
    return dp[left][right]=max_sum;
}
int main()
{
    ll tes;
    scanf("%lld",&tes);
    for(ll cas=1;cas<=tes;cas++)
    {
        scanf("%lld",&n);
        cle();
        for(ll i=1;i<=n;i++)
        {
            scanf("%lld",&main_arr[i]);
            cumsum_arr[i]=cumsum_arr[i-1]+main_arr[i];
        }
        ll ans=solve(1,n);
        printf("Case %lld: %lld\n",cas,ans);
    }
    return 0;
}
