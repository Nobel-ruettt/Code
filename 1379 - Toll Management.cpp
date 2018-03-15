#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxi 10010
#define pi pair<ll,ll>
#define pii pair<ll,pair<ll,ll> >
ll tes,nodes,edges,maxi_toll,main_source,target;
vector<pi>graph[maxi];
vector<pi>reverse_graph[maxi];
vector<pii>edge;
ll dis_source[maxi];
ll dis_target[maxi];
priority_queue<pi,vector<pi>,greater<pi> >que;
void cle()
{
    for(ll i=0;i<=nodes;i++)
    {
        graph[i].clear();
        reverse_graph[i].clear();
        dis_source[i]=LLONG_MAX;
        dis_target[i]=LLONG_MAX;
    }
    edge.clear();
}
void cle_que()
{
    while(!que.empty())
    {
        que.pop();
    }
}
void in_edges()
{
    ll node1,node2,cost;
    for(ll i=1;i<=edges;i++)
    {
        scanf("%lld%lld%lld",&node1,&node2,&cost);
        edge.push_back(make_pair(node1,make_pair(node2,cost)));
        graph[node1].push_back(make_pair(node2,cost));
        reverse_graph[node2].push_back(make_pair(node1,cost));
    }
//    for(ll i=1;i<=nodes;i++)
//    {
//        printf("Node %lld : ",i);
//        for(ll j=0;j<graph[i].size();j++)
//        {
//            printf("%lld,%lld ",graph[i][j].first,graph[i][j].second);
//        }
//        cout<<endl;
//    }
//       for(ll i=0;i<edge.size();i++)
//       {
//           cout<<edge[i].first<<" "<<edge[i].second.first<<" "<<edge[i].second.second<<endl;
//       }
}
void djixtra_from_source()
{
    ll source_node,source_dis,adj,adj_cost;
    dis_source[main_source]=0;
    que.push(make_pair(0,main_source));
    while(!que.empty())
    {
        source_node=que.top().second;
        source_dis=que.top().first;
        que.pop();
        for(ll i=0;i<graph[source_node].size();i++)
        {
            adj=graph[source_node][i].first;
            adj_cost=graph[source_node][i].second;
            if(dis_source[adj]>dis_source[source_node]+adj_cost&&(dis_source[source_node]+adj_cost)<=maxi_toll)
            {
                dis_source[adj]=dis_source[source_node]+adj_cost;
                que.push(make_pair(dis_source[adj],adj));
            }
        }
    }
//    for(ll i=1;i<=nodes;i++)
//    {
//        cout<<dis_source[i]<<endl;
//    }
}
void djixtra_from_des()
{
    ll source_node,source_dis,adj,adj_cost;
    dis_target[target]=0;
    que.push(make_pair(0,target));
    while(!que.empty())
    {
        source_node=que.top().second;
        source_dis=que.top().first;
        que.pop();
        for(ll i=0;i<reverse_graph[source_node].size();i++)
        {
            adj=reverse_graph[source_node][i].first;
            adj_cost=reverse_graph[source_node][i].second;
            if(dis_target[adj]>dis_target[source_node]+adj_cost&&(dis_target[source_node]+adj_cost)<=maxi_toll)
            {
                dis_target[adj]=dis_target[source_node]+adj_cost;
                que.push(make_pair(dis_target[adj],adj));
            }
        }
    }
//    for(ll i=1;i<=nodes;i++)
//    {
//        cout<<dis_target[i]<<endl;
//    }
}
ll solve()
{
     ll maxim=-1;
     for(ll i=0;i<edge.size();i++)
     {
         ll u=edge[i].first;
         ll v=edge[i].second.first;
         ll cost=edge[i].second.second;
         if(dis_source[u]!=LLONG_MAX && dis_target[v]!=LLONG_MAX && dis_source[u]+dis_target[v]+cost<=maxi_toll&&cost>maxim)
         {
             maxim=cost;
         }
     }
     return maxim;
}
int main()
{
    scanf("%lld",&tes);
    for(ll i=1;i<=tes;i++)
    {
        scanf("%lld%lld%lld%lld%lld",&nodes,&edges,&main_source,&target,&maxi_toll);
        cle();
        cle_que();
        in_edges();
        djixtra_from_source();
        cle_que();
        djixtra_from_des();
        ll ans=solve();
        printf("Case %lld: %lld\n",i,ans);
    }
    return 0;
}
