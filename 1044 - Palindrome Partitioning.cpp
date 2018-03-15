#include<bits/stdc++.h>
using namespace std;
#define ll long long
string line;
ll pl[1111][1111];
ll dp[1111];
void cle()
{
    memset(pl,-1,sizeof pl);
    memset(dp,-1,sizeof dp);
}
ll is_palindrome(ll b,ll e)
{
  if (b >= e)
    return 1;
  if (pl[b][e] != -1)
  {
     return pl[b][e];
  }
  return pl[b][e]=(line[b] == line[e]) && is_palindrome(b+1,e-1);
}
ll solve(ll starting_pos)
{
    if(starting_pos==line.size())
    {
        return 0;
    }
    if(dp[starting_pos]!=-1)
    {
        return dp[starting_pos];
    }
    ll min_partition=LLONG_MAX;
    for(ll i=starting_pos;i<line.size();i++)
    {
        if(is_palindrome(starting_pos,i))
        {
            ll ans=1+solve(i+1);
            if(ans<min_partition)
            {
                min_partition=ans;
            }
        }
    }
    return dp[starting_pos]=min_partition;
}
int main()
{

    ll tes;
    scanf("%lld",&tes);
    for(ll cas=1;cas<=tes;cas++)
    {
        cin>>line;
        cle();
        ll ans=solve(0);
        printf("Case %lld: %lld\n",cas,ans);
    }
    return 0;
}
