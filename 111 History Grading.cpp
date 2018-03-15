#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MAX 30
ll dp[MAX][MAX];
ll actual_order[MAX];
ll given_order[MAX];
ll n,value;
ll longest(ll i,ll j)
{
    if(i>n||j>n)
    {
        return 0;
    }
    if(dp[i][j]!=-1)
    {
        return dp[i][j];
    }
    ll ans=0;
    if(actual_order[i]==given_order[j])
    {
        ans=1+longest(i+1,j+1);
    }
    else
    {
        ll val1=longest(i+1,j);
        ll val2=longest(i,j+1);
        ans=max(val1,val2);
    }
    dp[i][j]=ans;
    return dp[i][j];
}
int main()
{
    scanf("%lld",&n);
    for(ll i=1; i<=n; i++)
    {
        scanf("%lld",&value);
        actual_order[value]=i;
    }
    for(;;)
    {
        for(ll i = 1; i <= n; i++) {
            if(scanf("%d", &value) != 1)
            {
                return 0;
            }
            given_order[value]=i;
        }
        memset(dp,-1,sizeof(dp));
        cout<<longest(1,1)<<endl;;
    }
    return 0;
}
