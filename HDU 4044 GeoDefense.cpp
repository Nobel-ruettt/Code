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
#define ll                   int
#define dd                   double
#define scl(n)               scanf("%d",&n)
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
#define MAXN                 1010
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
ll n,m;
vector<ll>graph2[MAXN],graph[MAXN];
ll subtree[MAXN];
ll sibling[MAXN];
ll dp[MAXN][210];
vector<pi>option[MAXN];
void cle()
{
    FOR(i,n)
    {
        graph2[i].clear();
        graph[i].clear();
        subtree[i]=-1;
        sibling[i]=-1;
        option[i].clear();
    }
}
void in_edges()
{
    ll u,v;
    FOR(i,n-1)
    {
        scl(u);
        scl(v);
        graph2[u].pb(v);
        graph2[v].pb(u);
    }
}
void in_towers()
{
    ll op;
    ll cost,power;
    FOR(i,n)
    {
        scl(op);
        FOR(j,op)
        {
            scl(cost);
            scl(power);
            option[i].pb(pi(cost,power));
        }
    }
}
void dfs(ll src,ll par)
{
    LOOP(i,graph2[src].size())
    {
        ll adj=graph2[src][i];
        if(adj!=par)
        {
            graph[src].pb(adj);
            dfs(adj,src);
        }
    }
}
void making_sibling(ll src)
{
    if(graph[src].size()==0)
    {
        return ;
    }
    subtree[src]=graph[src][0];
    for(ll i=1; i<graph[src].size(); i++)
    {
        sibling[graph[src][i-1]]=graph[src][i];
    }
    LOOP(i,graph[src].size())
    {
        making_sibling(graph[src][i]);
    }
}
ll solve(ll pos,ll rem)
{
    if(dp[pos][rem]!=-1)
    {
        return dp[pos][rem];
    }
    ///zodi ekta ekta kore tower oi node e bosai
    ll ans1=0;/// tower bosaia cost
    if(option[pos].size()>0)
    {
        LOOP(i,option[pos].size())
        {
            ll now_t_cost=option[pos][i].uu;///ekhn tower cost
            ll now_t_power=option[pos][i].vv;///ekhn tower power
            if(rem-now_t_cost>=0)/// ei tower bosano zabe
            {
                ll rem_money=rem-now_t_cost;/// bosanor por kto taka thakbe
                if(subtree[pos]!=-1 && sibling[pos]!=-1)/// subtree o ase ar sibling o ase
                {
                    for(ll j=0;j<=rem_money;j++)
                    {
                        ll sub_pathabo=j;/// subtree te koto pathabo
                        ll sib_pathabo=rem_money-j;///sibling e koto pathabo
                        ll ans=min((now_t_power+solve(subtree[pos],sub_pathabo)),solve(sibling[pos],sib_pathabo));///subtree te zog kore pathabo tobe sibling e jog hobe na ar duitar moddhe minimum
                        ans1=max(ans1,ans);
                    }
                }
                else if(subtree[pos]==-1 && sibling[pos]!=-1)/// subtree nai tobe sibling ase
                {
                    ll sib_pathabo=rem_money;/// sibling te koto pathabo
                    ll ans=min(now_t_power,solve(sibling[pos],rem_money));
                    ans1=max(ans,ans1);
                }
                else if(subtree[pos]!=-1 && sibling[pos]==-1)
                {
                    ll sub_pathabo=rem_money;/// subtree te koto pathabo
                    ll ans=now_t_power+solve(subtree[pos],rem_money);
                    ans1=max(ans,ans1);
                }
                else if(subtree[pos]==-1 && sibling[pos]==-1)
                {
                    ans1=max(ans1,now_t_power);
                }
            }
        }
    }
    ///tower bosaia dekha sesh ekhn na bosaia dekhte hobe
    ll ans2=0;///tower na  bosaia dekhar maximum pabo
    if(subtree[pos]!=-1 && sibling[pos]!=-1)///zodi subtree o ase sibling o ase
    {
        for(ll i=0;i<=rem;i++)
        {
            ll sub_pathabo=i;/// subtree te koto pathabo
            ll sib_pathabo=rem-i;///sibling e koto pathabo
            ll ans=min(solve(subtree[pos],sub_pathabo),solve(sibling[pos],sib_pathabo));
            ans2=max(ans,ans2);
        }
    }
    else if(subtree[pos]!=-1 && sibling[pos]==-1)
    {
        ll sub_pathabo=rem;///subtree koto pathabo
        ll ans=solve(subtree[pos],sub_pathabo);
        ans2=max(ans,ans2);
    }
    dp[pos][rem]=max(ans1,ans2);
    return dp[pos][rem];
}
int main()
{
    ll tes;
    scl(tes);
    FOR(cas,tes)
    {
        scl(n);
        cle();
        in_edges();
        scl(m);
        in_towers();
        dfs(1,-1);
        making_sibling(1);
        mstt(dp,-1);
        ll ans=solve(1,m);
        printf("%d\n",ans);
    }
    return 0;
}
