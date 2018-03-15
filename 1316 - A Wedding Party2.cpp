#include <bits/stdc++.h>
#define ll long long
#define pi pair<ll,ll>
#define MAXN 503
#define MAXS 15
using namespace std;
inline bool bitcheck(ll x,ll pos)
{
    return (x>>pos) & 1;
}
inline int biton(ll x,ll pos)
{
    return x | (1<<pos);
}
vector<vector<pi> >graph;
vector<bitset<MAXN> >reachability;
bitset<MAXN> visited;
vector<ll> shop_pos;
map<pi,ll>djixtra_memo;
pi memo[1<<MAXS][MAXS];
ll shops[MAXS];
ll n,m,s,shop_cnt;
void cle()
{
    graph.clear();
    reachability.clear();
    visited.reset();
    shop_pos.clear();
    djixtra_memo.clear();
    graph.resize(n);
    reachability.resize(n);
    memset(memo,-1,sizeof memo);
}
void in_shops()
{
    for(ll i=0; i<s; i++)
    {
        scanf("%lld",&shops[i]);
    }
}
void in_edges()
{
    ll u,v,c;
    for(ll i=1; i<=m; i++)
    {
        scanf("%lld%lld%lld",&u,&v,&c);
        graph[u].push_back(make_pair(v,c));
    }
}
void dfs(ll source)
{
    visited[source]=true;
    reachability[source][source]=true;
    for(ll i=0; i<graph[source].size(); i++)
    {
        ll adj=graph[source][i].first;
        if(!visited[adj])
        {
            dfs(adj);
        }
        reachability[source][adj]=true;
        reachability[source]|=reachability[adj];
    }
}
void getting_real_shop_pos()
{
    for(ll i=0; i<s; i++)
    {
        if(reachability[0][shops[i]]&&reachability[shops[i]][n-1])
        {
            shop_pos.push_back(shops[i]);
        }
    }
    shop_cnt=shop_pos.size();
}
ll djixtra(ll source,ll target)
{
    if(source==target)
    {
        return 0;
    }
    ll ret =djixtra_memo[make_pair(source,target)];
    if(ret!=0)
    {
        return ret;
    }
    priority_queue<pi,vector<pi>,greater<pi> > q;
    q.push(make_pair(0,source));
    ll dis[n];
    fill(dis,dis+n,INT_MAX);
    dis[source] = 0;
    while(!q.empty())
    {
        ll source_node= q.top().second;
        q.pop();
        if(source_node==target)
        {
            djixtra_memo[make_pair(source,target)]=dis[target];
            return dis[target];
        }
        for(ll i=0; i < graph[source_node].size(); ++i)
        {
            ll adj_node= graph[source_node][i].first;
            ll adj_cost= graph[source_node][i].second;
            if(dis[source_node]+adj_cost < dis[adj_node])
            {
                dis[adj_node] = dis[source_node] + adj_cost;
                q.push(make_pair(dis[adj_node],adj_node));
            }
        }
    }
}
pi fn(ll mask,ll shop_idx)
{
    if(memo[mask][shop_idx].first!=-1)
    {
        return memo[mask][shop_idx];
    }
    ll min_time=djixtra(shop_pos[shop_idx],n-1);
    ll max_shops=0;
    ll distance,node_count;
    for(ll i=0;i<shop_cnt;i++)
    {
        if(bitcheck(mask,i)==0 && reachability[shop_pos[shop_idx]][shop_pos[i]])
        {
            pi pr=fn(biton(mask,i),i);
            distance=pr.second+djixtra(shop_pos[shop_idx],shop_pos[i]);
            node_count=pr.first+1;
            if(node_count==max_shops)
            {
                min_time=min(min_time,distance);
            }
            else if(node_count>max_shops)
            {
                min_time=distance;
                max_shops=node_count;
            }
        }
    }
    return memo[mask][shop_idx]=make_pair(max_shops,min_time);
}
int main()
{
    ll tes;
    scanf("%lld",&tes);
    for(ll cas=1; cas<=tes; cas++)
    {
        scanf("%lld%lld%lld",&n,&m,&s);
        cle();
        in_shops();
        in_edges();
        dfs(0);
        visited.reset();
        dfs(0);
        visited.reset();
        dfs(0);
        if(reachability[0][n-1]==0)
        {
            printf("Case %lld: Impossible\n",cas);
            continue;
        }
        getting_real_shop_pos();
        ll min_time=djixtra(0,n-1);
        ll max_shops=0;
        ll distance,node_count;
        for(ll i=0;i<shop_cnt;i++)
        {
            pi pr=fn(biton(0,i),i);
            distance=pr.second+djixtra(0,shop_pos[i]);
            node_count=pr.first+1;
            if(max_shops==node_count)
            {
                min_time=min(min_time,distance);
            }
            else if(node_count>max_shops)
            {
                min_time=distance;
                max_shops=node_count;
            }
        }
        printf("Case %lld: %lld %lld\n",cas,max_shops,min_time);
    }
    return 0;
}
