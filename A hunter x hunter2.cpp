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
struct edge
{
    ll u,v,w;
    edge() {}
    edge(ll a,ll b,ll c)
    {
        u=a;
        v=b;
        w=c;
    }
    bool operator<(const edge& p) const
    {
        return w < p.w;
    }
};
ll n,m;
vector<pi>graph[200];
vector<edge>edges;
ll vis[210];
ll pr[210];
vector<ll>edge_main;
vector<edge>now_edges;
void cle()
{
    FOR(i,n)
    {
        vis[i]=0;
        graph[i].clear();
    }
    edge_main.clear();
    edges.clear();
}
void dfs(ll src)
{
    vis[src]=1;
    LOOP(i,graph[src].size())
    {
        ll adj=graph[src][i].uu;
        if(vis[adj]==0)
        {
            dfs(adj);
        }
    }
}
void in_edges()
{
    FOR(i,m)
    {
        ll u,v,c;
        scl(u);
        scl(v);
        scl(c);
        edges.pb(edge(u,v,c));
        graph[u].pb(pi(v,c));
        graph[v].pb(pi(u,c));
    }
}
int find(int r)
{
    return (pr[r] == r) ? r : pr[r]=find(pr[r]);
}
ll mst()
{
    sort(edges.begin(), edges.end());
    FOR(i,n)
    {
        pr[i]=i;
    }
    ll s=0;
    for (ll i = 0; i < (ll)edges.size(); i++)
    {
        ll u = find(edges[i].u);
        ll v = find(edges[i].v);
        if (u != v)
        {
            edge_main.pb(i);
            pr[u] = v;
            s += edges[i].w;
        }
    }
    return s;
}
ll mst2(ll pos)
{
    now_edges.clear();
    LOOP(i,edges.size())
    {
        if(i==pos)
        {
            continue;
        }
        now_edges.pb(edges[i]);
    }
    sort(now_edges.begin(),now_edges.end());
    FOR(i,n)
    {
        pr[i]=i;
    }
    ll s=0;
    ll cnt=0;
    for (ll i = 0; i < (ll)now_edges.size(); i++)
    {
        ll u = find(now_edges[i].u);
        ll v = find(now_edges[i].v);
        if (u != v)
        {
            pr[u] = v;
            s += now_edges[i].w;
            cnt++;
        }
    }
    if(cnt==n-1)
    {
        return s;
    }
    else
    {
        return inf;
    }
}
int main()
{
    ll tes;
    scl(tes);
    FOR(cas,tes)
    {
        scl(n);
        scl(m);
        cle();
        in_edges();
        dfs(1);
        bool f=0;
        FOR(i,n)
        {
            if(vis[i]==0)
            {
                f=1;
                break;
            }
        }
        if(f)
        {
            printf("Case #%lld : No way\n",cas);
            continue;
        }
        if(m==n-1)
        {
            printf("Case #%lld : No second way\n",cas);
            continue;
        }
        ll best=mst();
        ll second_best=inf;
        LOOP(i,edge_main.size())
        {
            ll ans=mst2(edge_main[i]);
            second_best=min(second_best,ans);
        }
        printf("Case #%lld : %lld\n",cas,second_best);
    }
    return 0;
}
