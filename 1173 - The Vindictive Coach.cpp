#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
ll n,m;
ull dp[55][55][2];
ll visited[55][55][2];
ll taken[55];
void cle()
{
    memset(taken,0,sizeof taken);
    memset(visited,0,sizeof visited);
}
ull solve(ll pos,ll num_taken,ll is_big)
{
    if(pos==n)
    {
        return 1;
    }
    if(visited[pos][num_taken][is_big]==1)
    {
        return dp[pos][num_taken][is_big];
    }
    ull sum=0;
    if(is_big==1)
    {
        for(ll i=1;i<num_taken;i++)
        {
            if(taken[i]==0)
            {
               taken[i]=1;
               sum+=solve(pos+1,i,0);
               taken[i]=0;
            }
        }
    }
    else
    {
        for(ll i=num_taken+1;i<=n;i++)
        {
            if(taken[i]==0)
            {
               taken[i]=1;
               sum+=solve(pos+1,i,1);
               taken[i]=0;
            }
        }
    }
    visited[pos][num_taken][is_big]=1;
    return dp[pos][num_taken][is_big]=sum;
}
int main()
{
    ll tes;
    scanf("%lld",&tes);
    for(ll cas=1;cas<=tes;cas++)
    {
       scanf("%lld%lld",&n,&m);
       if(n<3)
       {
           printf("Case %lld: 1\n",cas);
           continue;
       }
       cle();
       if(m>1)
       {
          taken[m]=1;
          ull ans=solve(1,m,1);
          printf("Case %lld: %llu\n",cas,ans);
          continue;
       }
       else
       {
           taken[1]=1;
           taken[3]=1;
           ull ans=solve(2,3,1);
           printf("Case %lld: %llu\n",cas,ans);
           continue;
       }
    }
    return 0;
}
