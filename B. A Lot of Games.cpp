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
#define MAXN                 500050
#define pii                  3.1415926536
#define mod                  1000000007
#define eps                  0.0000000001
#define inf                  9000000000000000
#define mstt(a,b)            memset((a),(b),sizeof (a))
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
/***template***/
ll nextt[27][MAXN];
ll created[MAXN];
ll level[MAXN];
ll sz;
char s[MAXN];
ll n,k;
vector<ll>graph[MAXN];
ll dp1[MAXN];
ll dp2[MAXN];
void insert()
{
    ll v=0;
    for(ll i=0;i<strlen(s);i++)
    {
        ll id=s[i]-'a';
        if(created[nextt[id][v]]==0)
        {
            nextt[id][v]=++sz;
            created[nextt[id][v]]=1;
            graph[v].pb(nextt[id][v]);
        }
        v=nextt[id][v];
    }
}
void dfs(ll src,ll lev)
{
    level[src]=lev;
    LOOP(i,graph[src].size())
    {
        ll adj=graph[src][i];
        dfs(adj,lev+1);
    }
}
void dfs2(ll src)
{
    if(graph[src].size()==0)
    {
        if(level[src]%2==0)
        {
            dp1[src]=0;
            dp2[src]=1;
        }
        else
        {
            dp1[src]=1;
            dp2[src]=0;
        }
        return ;
    }
    LOOP(i,graph[src].size())
    {
        dfs2(graph[src][i]);
    }
    if(level[src]%2==0)
    {
        LOOP(i,graph[src].size())
        {
            ll adj=graph[src][i];
            dp1[src]|=dp1[adj];
        }
        if(dp1[src]==1)
        {
            dp2[src]=0;
        }
        else
        {
            dp2[src]=1;
        }
    }
    if(level[src]%2==1)
    {
        LOOP(i,graph[src].size())
        {
            ll adj=graph[src][i];
            dp2[src]|=dp2[adj];
        }
        if(dp2[src]==1)
        {
            dp1[src]=0;
        }
        else
        {
            dp1[src]=1;
        }
    }
}
int main()
{
    scl(n);
    scl(k);
    FOR(i,n)
    {
        scanf(" %s",s);
        insert();
    }
    dfs(0,0);
    dfs2(0);
    if(dp1[0]==0)
    {
        cout<<"Second"<<endl;
    }
    else
    {
        if(k%2==1)
        {
            cout<<"First"<<endl;
        }
        else
        {
            cout<<"Second"<<endl;
        }
    }
    return 0;
}

