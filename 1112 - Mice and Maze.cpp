#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pi pair<ll,ll>
vector<pi>node[110];
priority_queue<pi,vector<pi>,greater<pi> >que;
ll dis[110];
int main()
{
    ll tes,nodes,somoi,edges,target,node1,node2,cost;
    scanf("%lld",&tes);
    for(ll k=1;k<=tes;k++)
    {
        scanf("%lld%lld%lld%lld",&nodes,&target,&somoi,&edges);
        for(ll i=0;i<=nodes;i++)
        {
            node[i].clear();
            dis[i]=LLONG_MAX;
        }
        while(!que.empty())
        {
            que.pop();
        }
        for(ll i=0;i<edges;i++)
        {
            scanf("%lld%lld%lld",&node1,&node2,&cost);
            node[node2].push_back(make_pair(node1,cost));
        }
        ll main_source=target;
        pi source;
        ll source_node,source_dis,adj_node,adj_cost;
        dis[main_source]=0;
        que.push(make_pair(0,main_source));
        while(!que.empty())
        {
            source=que.top();
            que.pop();
            source_node=source.second;
            source_dis=source.first;
            for(ll i=0;i<node[source_node].size();i++)
            {
                adj_node=node[source_node][i].first;
                adj_cost=node[source_node][i].second;
                if(source_dis+adj_cost<dis[adj_node])
                {
                    dis[adj_node]=source_dis+adj_cost;
                    que.push(make_pair(dis[adj_node],adj_node));
                }
            }
        }
        ll count1=0;
        for(ll i=1;i<=nodes;i++)
        {
            if(dis[i]<=somoi)
            {
                count1++;
            }
        }
        printf("%lld\n",count1);
        puts("");
    }
    return 0;
}
