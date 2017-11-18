#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <string>
#include <map>
#include <stack>
#include <vector>
#include <set>
#include <queue>
using namespace std;
/***template***/
#define ll                   long long
#define dd                   double
#define scl(n)               scanf("%lld",&n)
#define sci(n)               scanf("%d",&n)
#define scd(n)               scanf("%lf",&n)
#define pi                   pair<ll,ll>
#define pb                   push_back
#define mp                   make_pair
#define uu                   first
#define vv                   second
#define FOR(i,n)             for(ll i=1;i<=n;i++)
#define LOOP(i,n)            for(ll i=0;i<n;i++)
#define FOOR(i,a,b)          for(ll i=a;i<=b;i++)
#define LOP(i,a,b)           for(ll i=a;i<b;i++)
#define sorted(s)            sort(s.begin(),s.end())
#define reversed(s)          reverse(s.begin(),s.end())
#define contains(a,b)        (find((a).begin(), (a).end(), (b)) != (a).end())
#define MAXN                 10004
#define pii                  3.1415926536
#define mod                  1000000007
#define eps                  0.0000000001
#define inf                  900000000000000000
#define mstt(a,b)            memset((a),(b),sizeof (a))
ll Set(ll n,ll pos)
{
    return n=n|(1<<pos);
}
ll reset(ll n,ll pos)
{
    return n=n&~(1<<pos);
}
bool check(ll n,ll pos)
{
    return (bool)(n&(1<<pos));
}
/***template***/
ll n,s,k;
vector<pi>graph[MAXN];
vector<pi>graph2[MAXN];
ll sizee[MAXN];
ll dp[MAXN][20];
void cle()
{
    FOR(i,n)
    {
        graph[i].clear();
        graph2[i].clear();
        sizee[i]=0;
    }
}
void in_edges()
{
    ll u,v,c;
    FOR(i,n-1)
    {
        scl(u);
        scl(v);
        scl(c);
        graph2[u].pb(mp(v,c));
        graph2[v].pb(mp(u,c));
    }
}
ll dfs(ll src,ll par)
{
    LOOP(i,graph2[src].size())
    {
        ll adj=graph2[src][i].uu;
        ll cost=graph2[src][i].vv;
        if(adj!=par)
        {
            graph[src].pb(mp(adj,cost));
            sizee[src]+=(cost+dfs(adj,src));
        }
    }
    return sizee[src];
}
void solve(ll src)
{
    for(ll i=0;i<=k;i++)
    {
        dp[src][i]=0;
    }
    if(graph[src].size()==0)
    {
        return ;
    }
    LOOP(i,graph[src].size())
    {
        ll adj=graph[src][i].uu;
        ll cost=graph[src][i].vv;
        solve(adj);
        for(ll j=k;j>=0;j--)
        {
            dp[src][j]+=dp[adj][0]+2*cost;
            for(ll kk=0;kk<=j;kk++)
            {
                dp[src][j]=min(dp[src][j],dp[adj][kk]+dp[src][j-kk]+kk*cost);
            }
        }
    }
}
int main()
{
    while(scanf("%lld%lld%lld",&n,&s,&k)==3)
    {
        cle();
        in_edges();
        dfs(s,-1);
        solve(s);
        printf("%lld\n",dp[s][k]);
    }
    return 0;
}
