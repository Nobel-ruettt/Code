#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<ll>banana[300];
ll n,tes,make;
ll dp[300][300];
void cle()
{
    for(ll i=0; i<2*n; i++)
    {
        banana[i].clear();
    }
    for(ll i=0;i<=2*n-1;i++)
    {
        for(ll j=0;j<=n;j++)
        {
            dp[i][j]=-1;
        }
    }
}
void in_grid()
{
    ll ban;
    for(ll i=0;i<n;i++)
    {
        for(ll j=0;j<=i;j++)
        {
            scanf("%lld",&ban);
            banana[i].push_back(ban);
        }
    }
    ll count1=n-1;
    for(ll i=n;i<2*n-1;i++)
    {
        for(ll j=count1;j>=1;j--)
        {
            scanf("%lld",&ban);
            banana[i].push_back(ban);
        }
        count1--;
    }
//    for(ll i=0;i<=2*n-2;i++)
//    {
//        for(ll j=0;j<banana[i].size();j++)
//        {
//            printf("%lld ",banana[i][j]);
//        }
//        printf("\n");
//    }
    make=2*n-2;
}
ll solve(ll row,ll column)
{
    if(row>=make)
    {
        return banana[row][0];
    }
    ll ans1=0,ans2=0;
    if(dp[row][column]!=-1)
    {
        return dp[row][column];
    }
    if(banana[row+1].size()>banana[row].size())
    {
        ans1=banana[row][column]+solve(row+1,column);
        ans2=banana[row][column]+solve(row+1,column+1);
        return dp[row][column]=max(ans1,ans2);
    }
    if(banana[row+1].size()<banana[row].size())
    {
        if(column-1>=0)
        {
            ans1=banana[row][column]+solve(row+1,column-1);
        }
        if(column<banana[row+1].size())
        {
            ans2=banana[row][column]+solve(row+1,column);
        }
        return dp[row][column]=max(ans1,ans2);
    }
}
int main()
{
    scanf("%lld",&tes);
    for(ll i=1; i<=tes; i++)
    {
        scanf("%lld",&n);
        cle();
        in_grid();
        ll ans=solve(0,0);
        printf("Case %lld: %lld\n",i,ans);
    }
    return 0;
}
