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
#define MAXN                 100005
#define pii                  3.1415926536
#define mod                  1000000007
#define eps                  0.0000000001
#define inf                  9000000000000000
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
vector<ll>graph[MAXN];
ll son_size[MAXN],mxson[MAXN],col[MAXN];
bool vis[MAXN];
ll n,root,ans;
ll freq[32][2];
ll tp[32];
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
void calc(ll src,ll par,ll dis=0)
{
//    cout<<"src "<<src<<" dis "<<dis<<endl;
    LOOP(i,26)
    {
        ll now_zog=freq[i][check(dis,i)^1]*tp[i];
//        if(now_zog>0)
//        {
//            cout<<"i "<<i<<" now_zog "<<now_zog<<endl;
//        }
        ans+=now_zog;
    }
    LOOP(i,graph[src].size())
    {
        ll adj=graph[src][i];
        if(vis[adj]==0 && adj!=par)
        {
            calc(adj,src,dis^col[adj]);
        }
    }
}
void dfsdis(ll src,ll par,ll dis=0)
{
//    cout<<"src of dfsdis "<<src<<" dis "<<dis<<endl;
    LOOP(i,26)
    {
        freq[i][check(dis,i)]++;
//        if(i<=4)
//        {
//            cout<<freq[i][0]<<" "<<freq[i][1]<<endl;
//        }
    }
    LOOP(i,graph[src].size())
    {
        ll adj=graph[src][i];
        if(vis[adj]==0 && adj!=par)
        {
            dfsdis(adj,src,dis^col[adj]);
        }
    }
}
void dfs(ll source)
{
    dfssize(source,-1);
    root=0;
    mxson[0]=n;
    dfsroot(source,source,-1);
    ll now_root=root;
//    cout<<"now root"<<now_root<<endl;
    LOOP(i,26)
    {
        freq[i][0]=freq[i][1]=0;
        freq[i][check(col[now_root],i)]++;
//        if(i<=4)
//        {
//            cout<<freq[i][0]<<" "<<freq[i][1]<<endl;
//        }
    }
    LOOP(i,graph[now_root].size())
    {
        ll adj=graph[now_root][i];
        if(vis[adj]==0)
        {
            calc(adj,now_root,col[adj]);
            dfsdis(adj,now_root,col[now_root]^col[adj]);
        }
    }
    vis[now_root]=1;
    LOOP(i,graph[now_root].size())
    {
        ll adj=graph[now_root][i];
        if(vis[adj]==1)
        {
            continue;
        }
        dfs(adj);
    }
}
int main()
{
    tp[0]=1;
    FOR(i,30)
    {
        tp[i]=tp[i-1]*2;
    }
    scl(n);
    FOR(i,n)
    {
        scl(col[i]);
        ans+=col[i];
    }
//    cout<<ans<<endl;
    FOR(i,n-1)
    {
        ll u,v;
        scl(u);
        scl(v);
        graph[u].pb(v);
        graph[v].pb(u);
    }
    dfs(1);
    cout<<ans<<endl;
    return 0;
}

