#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m;
vector<ll>graph[20];
bool visited[16][1<<16];
bool check_vis[1<<16];
ll dp[1<<16];
void cle()
{
    for(ll i=0;i<=n;i++)
    {
        graph[i].clear();
    }
    memset(visited,0,sizeof visited);
    memset(check_vis,0,sizeof check_vis);
    memset(dp,-1,sizeof dp);
}
void dfs(ll source,ll mask)
{
    visited[source][mask]=1;
    check_vis[mask]=1;
    for(ll j=0;j<graph[source].size();j++)
    {
        ll adj=graph[source][j];
        if(!visited[adj][mask|(1<<adj)])
        {
            dfs(adj,mask|(1<<adj));
        }
    }
}
ll solve(ll mask)
{
    if(mask==0)
    {
        return 0;
    }
    if(dp[mask]!=-1)
    {
        return dp[mask];
    }
    ll ans=100;
    for(ll i=mask;i>0;i=mask&(i-1))
    {
        if(check_vis[i])
        {
            ans=min(ans,1+solve(mask^i));
        }
    }
    return dp[mask]=ans;
}
int main()
{
    ll tes;
    scanf("%lld",&tes);
    for(ll cas=1;cas<=tes;cas++)
    {
        scanf("%lld%lld",&n,&m);
        cle();
        for(ll i=1;i<=m;i++)
        {
            ll u,v;
            scanf("%lld%lld",&u,&v);
            u--;
            v--;
            graph[u].push_back(v);
        }
        for(ll i=0;i<n;i++)
        {
            dfs(i,1<<i);
        }
        printf("Case %lld: %lld\n",cas,solve((1<<n)-1));
    }
    return 0;
}
