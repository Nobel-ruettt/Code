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
#define MAXN                 6004
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
ll n,root;
ll rat[MAXN];
ll in[MAXN];
vector<ll>graph[MAXN];
ll dp[MAXN][2];
void cle()
{
    FOR(i,n)
    {
        in[i]=0;
        graph[i].clear();
        dp[i][0]=dp[i][1]=0;
    }
}
void in_ratings()
{
    FOR(i,n)
    {
        scl(rat[i]);
    }
}
void in_edges()
{
    ll u,v;
    while(1)
    {
        scl(v);
        scl(u);
        if(v==0 && u==0)
        {
            return;
        }
        graph[u].pb(v);
        in[v]++;
    }
}
void dfs(ll src)
{
    if(graph[src].size()==0)
    {
        dp[src][0]=0;
        dp[src][1]=rat[src];
        return ;
    }
    dp[src][1]+=rat[src];
    LOOP(i,graph[src].size())
    {
        ll adj=graph[src][i];
        dfs(adj);
        dp[src][0]+=max(dp[adj][0],dp[adj][1]);
        dp[src][1]+=dp[adj][0];
    }
}
int main()
{
    while(scl(n)==1)
    {
        cle();
        in_ratings();
        in_edges();
        FOR(i,n)
        {
            if(in[i]==0)
            {
                root=i;
            }
        }
        dfs(root);
        cout<<max(dp[root][0],dp[root][1])<<endl;
    }
    return 0;
}
