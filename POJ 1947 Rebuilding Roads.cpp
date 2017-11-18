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
#define MAXN                 210
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
ll n,p;
vector<ll>graph2[MAXN];
vector<ll>graph[MAXN];
ll dp[MAXN][MAXN];
void in_edges()
{
    ll u,v;
    FOR(i,n-1)
    {
        scl(u);
        scl(v);
        graph2[u].pb(v);
        graph2[v].pb(u);
    }
}
void dfs1(ll src,ll par)
{
    LOOP(i,graph2[src].size())
    {
        ll adj=graph2[src][i];
        if(adj!=par)
        {
            graph[src].pb(adj);
            dfs1(adj,src);
        }
    }
}
void dfs(ll src)
{
    for(ll i=0; i<=p; i++)
    {
        dp[src][i]=inf;
    }
    dp[src][1]=0;
    LOOP(i,graph[src].size())
    {
        ll adj=graph[src][i];
        dfs(adj);
        ll temp;
        for(ll j=p; j>=1; j--)
        {
            temp=dp[src][j]+1;
            for(ll k=1; k<j; k++)
            {
                temp=min(temp,(dp[adj][j-k]+dp[src][k]));
            }
            dp[src][j]=temp;
        }
    }
}
int main()
{
    scl(n);
    scl(p);
    in_edges();
    dfs1(1,-1);
    dfs(1);
    ll ans=dp[1][p];
    for(ll i=2;i<=n;i++)
    {
        ans=min(ans,dp[i][p]+1);
    }
    cout<<ans<<endl;
    return 0;
}
