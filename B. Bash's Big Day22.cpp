#include <bits/stdc++.h>
using namespace std;
#define ll int
map<ll,map<ll,ll> >dp;
ll numbers[100005];
ll n;
int gcds(int a, int b)
{
    if (a == 0)
        return b;
    return gcds(b%a, a);
}
int solve(ll pos,ll gcd)
{
    if(pos>=n+1)
    {
        return 0;
    }
    if(dp[pos][gcd]!=0)
    {
        return dp[pos][gcd];
    }
    if(gcd==0)
    {
        ll ans3=1+solve(pos+1,numbers[pos+1]);
        ll ans4=solve(pos+1,0);
        return dp[pos][gcd]=max(ans3,ans4);
    }
    ll ggg=__gcd(gcd,numbers[pos+1]);
    ll ans1=0;
    if(ggg>1)
    {
        ans1=1+solve(pos+1,ggg);
    }
    ll ans2=solve(pos+1,gcd);
    return  dp[pos][gcd]=max(ans1,ans2);
}
int main()
{
    scanf("%d",&n);
    for(ll i=1;i<=n;i++)
    {
        scanf("%d",&numbers[i]);
    }
    int ans=solve(0,0);
    printf("%d",ans);
    return 0;
}
