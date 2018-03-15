#include <bits/stdc++.h>
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
#define sortedd(s)           sort(s.begin(),s.end(),cmp)
#define reversed(s)          reverse(s.begin(),s.end())
#define contains(a,b)        (find((a).begin(), (a).end(), (b)) != (a).end())
#define MAXN                 210
#define pii                  3.1415926536
#define mod                  1000000007
#define eps                  0.0000000001
#define inf                  1e18
#define mstt(a,b)            memset((a),(b),sizeof (a))
#define sz(x)                (ll)x.size()
/***template***/
vector<ll>graph[MAXN];
ll fl[MAXN][MAXN],cp[MAXN][MAXN];
ll dis[MAXN],ind[MAXN];
deque<ll>que;
bool bfs(ll src,ll sink)
{
    mstt(dis,-1);
    dis[src]=0;
    que.push_back(src);
    while(!que.empty())
    {
        ll u=que.front();
        que.pop_front();
        LOOP(i,sz(graph[u]))
        {
            ll adj=graph[src][i];
            if(dis[adj]==-1 &&  fl[u][adj] < cp[u][adj] )
            {
                que.push_back(adj);
                dis[adj]=dis[u]+1;
            }
        }
    }
    return dis[sink]!=-1;
}
ll dfs(ll src,ll flow,ll sink)
{
    if(!flow)return 0;
    if(src==sink)return flow;
    for(;ind[src]<sz(graph[src]); ind[src]++)
    {
        ll adj=graph[src][ind[src]];
        if(dis[adj]!=dis[src]+1) continue;
        ll curr_flow=dfs(adj,min(flow,cp[src][adj]-fl[src][adj]),sink);
        if(curr_flow)
        {
            fl[src][adj] += curr_flow;
            fl[adj][src] -= curr_flow;
            return curr_flow;
        }
    }
    return 0;
}
ll dinic(ll src,ll sink)
{
    ll tot_flow=0;
    while(1)
    {
        if(!bfs(src,sink)) break;
        mstt(ind,0);
        while(ll curr_flow=dfs(src,inf,sink))
        {
            tot_flow+=curr_flow;
        }
    }
    return tot_flow;
}
void add_edge(ll u,ll v,ll cap,ll flow)
{
    graph[u].pb(v);
    cp[u][v]+=cap;
    fl[u][v]+=flow;
}
ll tes;
ll n,m;
ll row[51],col[51];
void cle()
{
    LOOP(i,MAXN)
    {
        graph[i].clear();
    }
    mstt(fl,0);
    mstt(cp,0);
}
int main()
{
    scl(tes);
    FOR(cas,tes)
    {
       scl(n);
       scl(m);
       cle();
       ll sum_r=0,sum_c=0;
       FOR(i,n)
       {
           scl(row[i]);
           sum_r+=row[i];
       }
       FOR(i,m)
       {
           scl(col[i]);
           sum_c+=col[i];
       }
       printf("Case %lld:",cas);
       if(sum_r!=sum_c)
       {
           printf(" impossible\n");
           continue;
       }
       ll src=0;
       ll sink=n+m+1;
       FOR(i,n)
       {
           add_edge(src,i,row[i],0);
           add_edge(i,src,0,0);
       }
       FOR(i,m)
       {
           add_edge(i+n,sink,col[i],0);
           add_edge(sink,i+n,0,0);
       }

    }
    return 0;
}


