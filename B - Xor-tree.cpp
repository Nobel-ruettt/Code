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
#define LL                   long long
#define dd                   double
#define scl(n)               scanf("%lld",&n)
#define sl(n)                scanf("%lld",&n)
#define scd(n)               scanf("%lf",&n)
#define pi                   pair<ll,ll>
#define pll                  pair<ll,ll>
#define pb                   push_back
#define mp                   make_pair
#define uu                   first
#define vv                   second
#define fr                   first
#define sc                   second
#define FOR(i,n)             for(ll i=1;i<=n;i++)
#define LOOP(i,n)            for(ll i=0;i<n;i++)
#define FOOR(i,a,b)          for(ll i=a;i<=b;i++)
#define LOP(i,a,b)           for(ll i=a;i<b;i++)
#define sorted(s)            sort(s.begin(),s.end())
#define sortedd(s)           sort(s.begin(),s.end(),cmp)
#define reversed(s)          reverse(s.begin(),s.end())
#define contains(a,b)        (find((a).begin(), (a).end(), (b)) != (a).end())
#define MAXN                 100005
#define pii                  3.1415926536
#define mod                  1000000007
#define eps                  0.0000000001
#define inf                  9000000000000000
#define INF                  (1LL<<62)
#define mstt(a,b)            memset((a),(b),sizeof (a))
#define sz(x)                (ll)x.size()
ll Set(ll n,ll pos)
{
    return n=n|(1LL<<pos);
}
ll reset(ll n,ll pos)
{
    return n=n&~(1LL<<pos);
}
bool check(ll n,ll pos)
{
    return (bool)(n&(1LL<<pos));
}
ll mul(ll a,ll b)
{
    ll c;
    c = (a%mod * b%mod)%mod;
    return c;
}
ll add(ll a,ll b)
{
    ll c;
    c = (a%mod + b%mod)%mod;
    return c;
}
ll sub(ll a,ll b)
{
    ll c;
    c = ((a%mod - b%mod)%mod + mod)%mod;
    return c;
}
ll power(ll x,ll y,ll p)
{
    ll res = 1;
    x = x % p;
    while (y > 0)
    {
        if (y & 1)
            res = (res*x) % p;
        y = y>>1;
        x = (x*x) % p;
    }
    return res;
}
ll s2, s1, t2, t1;
ll egcd(ll a, ll b)
{
    ll temp;
    if (a%b == 0)
    {
        return s1;
    }
    temp = s2 - (a/b)*s1;
    s2 = s1;
    s1 = temp;
    temp = t2 - (a/b)*t1;
    t2 = t1;
    t1 = temp;
    return egcd(b, a%b);
}
/***template***/
ll n;
vector<ll>graph[100005];
ll init[100005];
ll goal[100005];
ll level[100005];
vector<ll>ans;
void dfs(ll src,ll par,ll zor_level,ll bizor_level)
{
    if(level[src]%2==0)
    {
        ll now_ase=init[src];
        ll pore_hobe=goal[src];
        if(zor_level%2==0)
        {
            now_ase=now_ase;
        }
        else
        {
            now_ase^=1;
        }
        if(now_ase==pore_hobe)
        {
            LOOP(i,graph[src].size())
            {
                ll adj=graph[src][i];
                if(adj!=par)
                {
                    dfs(adj,src,zor_level,bizor_level);
                }
            }
        }
        else if(now_ase!=pore_hobe)
        {
            ans.pb(src);
            LOOP(i,graph[src].size())
            {
                ll adj=graph[src][i];
                if(adj!=par)
                {
                    dfs(adj,src,zor_level+1,bizor_level);
                }
            }
        }
    }
    else if(level[src]%2==1)
    {
        ll now_ase=init[src];
        ll pore_hobe=goal[src];
        if(bizor_level%2==0)
        {
            now_ase=now_ase;
        }
        else
        {
            now_ase^=1;
        }
        if(now_ase==pore_hobe)
        {
            LOOP(i,graph[src].size())
            {
                ll adj=graph[src][i];
                if(adj!=par)
                {
                    dfs(adj,src,zor_level,bizor_level);
                }
            }
        }
        else if(now_ase!=pore_hobe)
        {
            ans.pb(src);
            LOOP(i,graph[src].size())
            {
                ll adj=graph[src][i];
                if(adj!=par)
                {
                    dfs(adj,src,zor_level,bizor_level+1);
                }
            }
        }
    }
}
void dfs2(ll src,ll par,ll dis)
{
    level[src]=dis;
    LOOP(i,graph[src].size())
    {
        ll adj=graph[src][i];
        if(adj!=par)
        {
            dfs2(adj,src,dis+1);
        }
    }
}
int main()
{
    scl(n);
    FOR(i,n-1)
    {
        ll u,v;
        scl(u);
        scl(v);
        graph[u].pb(v);
        graph[v].pb(u);
    }
    FOR(i,n)
    {
        scl(init[i]);
    }
    FOR(i,n)
    {
        scl(goal[i]);
    }
    dfs2(1,-1,0);
    dfs(1,-1,0,0);
    cout<<ans.size()<<endl;
    LOOP(i,ans.size())
    {
        cout<<ans[i]<<endl;
    }
    return 0;
}

