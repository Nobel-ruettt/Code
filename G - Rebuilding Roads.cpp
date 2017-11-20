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
#define MAXN                 10005
#define pii                  3.1415926536
#define mod                  1000000007
#define eps                  0.0000000001
#define inf                  200000000
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
ll n,q;
vector<ll>graph[MAXN];
ll q_l[MAXN],q_r[MAXN];
bool f;
void cle()
{
    FOR(i,n)
    {
        graph[i].clear();
        q_l[i]=1;
        q_r[i]=inf;
    }
    f=0;
}
void in_edges()
{
    ll v,u;
    for(ll i=2; i<=n; i++)
    {
        v=i;
        scl(u);
        graph[u].pb(v);
    }
}
void in_querys()
{
    ll x,w;
    char c;
    FOR(i,q)
    {
        scl(x);
        scanf(" %c",&c);
        scl(w);
        if(c=='=')
        {
            if(w<q_l[x] || w>q_r[x])
                f=1;
            q_l[x]=w;
            q_r[x]=w;
        }
        else if(c=='<')
        {
            if(q_l[x]>=w)
                f=1;
            q_r[x]=w-1;
        }
        else
        {
            if(q_r[x]<=w)
                f=1;
            q_l[x]=w+1;
        }
    }
}
void dfs(ll src)
{
    if(graph[src].size()==0)
    {
        return ;
    }
    ll left_sum=1;
    LOOP(i,graph[src].size())
    {
        ll adj=graph[src][i];
        dfs(adj);
        if(f)
        {
            return;
        }
        left_sum+=q_l[adj];
    }
    if(left_sum>q_r[src])
    {
        f=1;
        return ;
    }
    else
    {
       q_l[src]=max(left_sum,q_l[src]);
    }
}
int main()
{
    while(scanf("%lld",&n)==1)
    {
        cle();
        in_edges();
        scl(q);
        in_querys();
        if(f)
        {
            printf("Lie\n");
            continue;
        }
        dfs(1);
        if(f)
        {
            printf("Lie\n");
        }
        else
        {
            printf("True\n");
        }
    }
    return 0;
}
