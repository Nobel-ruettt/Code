#include <iostream>
#include <vector>
#include <map>
#include <stdio.h>
#include <cstdio>
#include <algorithm>
using namespace std;
/***template***/
#define ll                   int
#define dd                   double
#define scl(n)               scanf("%d",&n)
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
#define MAXN                 100100
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
vector<ll>graph[MAXN];
ll son_size[MAXN],mxson[MAXN];
bool vis[MAXN];
ll n,root,q;
ll parent[MAXN];
ll par[17][MAXN];
ll depth[MAXN];
ll min_dis_of_red[MAXN];
void dfs0(ll u,ll prev,ll d)
{
    depth[u]=d;
    par[0][u]=prev;
    ll z=graph[u].size();
    for(ll i=0; i<z; i++)
    {
        if(graph[u][i]!=prev)
        {
            dfs0(graph[u][i],u,d+1);
        }
    }
}
void preL()
{
    for(int i=1; i<17; i++)
    {
        for(int j=1; j<=n; j++)
        {
            if(par[i-1][j] != -1)
            {
                par[i][j] = par[i-1][par[i-1][j]];
            }
        }
    }
}
ll lca(ll u,ll v)
{
    if(depth[u] < depth[v]) swap(u,v);
    ll diff = depth[u] - depth[v];
    for(ll i=0; i<17; i++)
    {
        if( (diff>>i)&1 )
        {
           u = par[i][u];
        }
    }
    if(u == v)
    {
        return u;
    }
    for(ll i=17-1; i>=0; i--)
    {
        if(par[i][u] != par[i][v])
        {
            u = par[i][u];
            v = par[i][v];
        }
    }
    return par[0][u];
}
void in_edges()
{
    ll u,v,c;
    FOR(i,n-1)
    {
        scl(u);
        scl(v);
        graph[u].pb(v);
        graph[v].pb(u);
    }
}
void dfssize(ll src,ll par)
{
    son_size[src]=1;
    mxson[src]=0;
    LOOP(i,graph[src].size())
    {
        ll adj=graph[src][i];
        if(adj!=par && vis[adj]==0)
        {
            dfssize(adj,src);
            son_size[src]+=son_size[adj];
            mxson[src]=max(mxson[src],son_size[adj]);
        }
    }
}
void dfsroot(ll main_source,ll source,ll par)
{
    if(son_size[main_source]-son_size[source]>mxson[source])
    {
        mxson[source]=son_size[main_source]-son_size[source];
    }
    if(mxson[source]<mxson[root])
    {
        root=source;
    }
    LOOP(i,graph[source].size())
    {
        ll adj=graph[source][i];
        if(adj!=par && vis[adj]==0)
        {
            dfsroot(main_source,adj,source);
        }
    }
}
ll dfs(ll source)
{
    dfssize(source,-1);
    root=0;
    mxson[0]=n;
    dfsroot(source,source,-1);
    vis[root]=1;
    ll now_root=root;
    LOOP(i,graph[now_root].size())
    {
        ll adj=graph[now_root][i];
        if(vis[adj]==0)
        {
            parent[dfs(adj)]=now_root;
        }
    }
    return now_root;
}
ll dis(ll a,ll b)
{
    ll lcaa=lca(a,b);
    ll tot_dis=(depth[a]-depth[lcaa])+(depth[b]-depth[lcaa]);
    return tot_dis;
}
void update(ll now_node,ll red_node)
{
   ll distance=dis(now_node,red_node);
   min_dis_of_red[now_node]=min(min_dis_of_red[now_node],distance);
   if(parent[now_node]!=0)
   {
       update(parent[now_node],red_node);
   }
}
ll query(ll now_node,ll blue_node)
{
    ll distance=dis(now_node,blue_node);
    ll min_dis=distance+min_dis_of_red[now_node];
    if(parent[now_node]!=0)
    {
        return min(min_dis,query(parent[now_node],blue_node));
    }
    else
    {
        return min_dis;
    }
}
int main()
{
    scl(n);
    scl(q);
    in_edges();
    dfs(1);
    dfs0(1,-1,0);
    preL();
    FOR(i,n)
    {
        min_dis_of_red[i]=90000000;
    }
    update(1,1);
    FOR(i,q)
    {
        ll ty;
        scl(ty);
        if(ty==1)
        {
            ll ver;
            scl(ver);
            update(ver,ver);
        }
        else if(ty==2)
        {
            ll ver;
            scl(ver);
            printf("%d\n",query(ver,ver));
        }
    }
    return 0;
}
/*
15 3
1 2
3 2
4 2
5 2
6 5
7 6
5 8
8 9
9 10
9 13
10 11
10 12
13 14
13 15
*/


