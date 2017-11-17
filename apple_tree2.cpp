#include <iostream>
#include <cstdio>
#include <stdio.h>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <stack>
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
ll n,k;
vector<ll>graph[MAXN];
ll dp[MAXN][MAXN][2];
ll apple[MAXN];
void cle()
{
    FOR(i,n)
    {
        graph[i].clear();
    }
}
void in_apples()
{
    FOR(i,n)
    {
        scl(apple[i]);
    }
}
void in_edges()
{
    ll u,v;
    FOR(i,n-1)
    {
        scl(u);
        scl(v);
        graph[u].pb(v);
        graph[v].pb(u);
    }
}
void dfs(ll src,ll par)
{
    LOOP(i,k+3)
    {
        dp[src][i][0]=apple[src];
        dp[src][i][1]=apple[src];
    }

    LOOP(i,graph[src].size())
    {
        ll adj=graph[src][i];
        if(adj!=par)
        {
            dfs(adj,src);
            for(ll j=k; j>=0; j--)
            {
                for(ll kk=0; kk<=j; kk++)
                {
                    dp[src][j+1][0]=max(dp[src][j+1][0],dp[adj][kk][0]+dp[src][j-kk][1]);
                    dp[src][j+2][0]=max(dp[src][j+2][0],dp[adj][kk][1]+dp[src][j-kk][0]);
                    dp[src][j+2][1]=max(dp[src][j+2][1],dp[adj][kk][1]+dp[src][j-kk][1]);
                }
            }
        }
    }
//    if(src==1)
//    {
//        FOR(i,k+2)
//        {
//           cout<<dp[src][i][0]<<" "<<dp[src][i][1]<<endl;
//        }
//    }
}
ll solve()
{
    dfs(1,-1);
    return max(dp[1][k][0],dp[1][k][1]);
}
int main()
{
    while(scanf("%lld%lld",&n,&k)==2)
    {
        cle();
        in_apples();
        in_edges();
        ll ans=solve();
        printf("%lld\n",ans);
    }
    return 0;
}
