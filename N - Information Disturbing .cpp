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
#define MAXN                 2004
#define pii                  3.1415926536
#define mod                  1000000007
#define eps                  0.0000000001
#define inf                  90000000000000
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
ll n,m,low,high,mid;
vector<pi>graph[MAXN];
ll dp[MAXN];
void cle()
{
    FOR(i,n)
    {
        graph[i].clear();
    }
}
void in_edges()
{
    ll u,v,c;
    low=inf;
    high=-1;
    FOR(i,n-1)
    {
        scl(u);
        scl(v);
        scl(c);
        low=min(low,c);
        high=max(high,c);
        graph[u].pb(mp(v,c));
    }
}
void dfs(ll src)
{
    if(graph[src].size()==0)
    {
        dp[src]=inf;
        return ;
    }
    dp[src]=0;
    LOOP(i,graph[src].size())
    {
        ll adj=graph[src][i].uu;
        ll ad_c=graph[src][i].vv;
        dfs(adj);
        if(ad_c>mid)
        {
            dp[src]+=dp[adj];
        }
        else
        {
            dp[src]+=min(dp[adj],ad_c);
        }
    }
}
int main()
{
    while(scanf("%lld%lld",&n,&m)==2)
    {
        if(n==0 && m==0)
        {
            break;
        }
        cle();
        in_edges();
        ll ans=-1;
        while(low<=high)
        {
            mid=(low+high)/2;
            dfs(1);
            if(dp[1]<=m)
            {
                ans=mid;
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}
