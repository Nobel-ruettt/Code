#include <iostream>
#include <vector>
#include <map>
#include <stdio.h>
#include <cstdio>
#include <algorithm>
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
/***template***/
vector<pi>graph[MAXN];
ll son_size[MAXN],mxson[MAXN];
bool vis[MAXN];
ll n,root;
ll parent[MAXN];
void cle()
{
    FOR(i,n)
    {
        graph[i].clear();
        vis[i]=0;
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
        graph[u].pb(mp(v,c));
        graph[v].pb(mp(u,c));
    }
}
void dfssize(ll src,ll par)
{
    son_size[src]=1;
    mxson[src]=0;
    LOOP(i,graph[src].size())
    {
        ll adj=graph[src][i].uu;
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
        ll adj=graph[source][i].uu;
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
        ll adj=graph[now_root][i].uu;
        ll adj_cost=graph[now_root][i].vv;
        if(vis[adj]==0)
        {
            parent[dfs(adj)]=now_root;
        }
    }
    return now_root;
}
int main()
{
    scl(n);
    cle();
    in_edges();
    dfs(1);
    return 0;
}
/*
15
1 2 1
3 2 1
4 2 1
5 2 1
6 5 1
7 6 1
5 8 1
8 9 1
9 10 1
9 13 1
10 11 1
10 12 1
13 14 1
13 15 1
*/
