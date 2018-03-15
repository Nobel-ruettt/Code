#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pi pair<ll,ll>
vector <ll>node[130];
map<ll,map<ll,ll> >cost;
priority_queue<pi ,vector<pi> , greater <pi> >que;
ll dis[130];
int main()
{
    ll nodes,edges,node1,node2,weight,source_dis,source_node,adjecent,root,tes;
    scanf("%lld",&tes);
    for(int k=1; k<=tes; k++)
    {
        scanf("%lld%lld",&nodes,&edges);
        for(int i=0; i<edges; i++)
        {
            scanf("%lld%lld%lld",&node1,&node2,&weight);
            node[node1].push_back(node2);
            node[node2].push_back(node1);
            if(cost[node1][node2]!=0)
            {
                if(weight<cost[node1][node2])
                {
                    cost[node1][node2]=weight;
                    cost[node2][node1]=weight;
                }
            }
            else
            {
                 cost[node1][node2]=weight;
                 cost[node2][node1]=weight;
            }
        }
        for(int i=1; i<=nodes; i++)
        {
            dis[i]=LLONG_MAX;
        }
        pi source;
        dis[1]=0;
        source=make_pair(0,1);
        que.push(source);
        while(!que.empty())
        {
            source=que.top();
            que.pop();
            source_dis=source.first;
            source_node=source.second;
            for(int i=0; i<node[source_node].size(); i++)
            {
                adjecent=node[source_node][i];
                if(dis[source_node]+cost[source_node][adjecent]<dis[adjecent])
                {
                    dis[adjecent]=source_dis+cost[source_node][adjecent];
                    que.push(make_pair(dis[adjecent],adjecent));
                }
            }
        }
        if(dis[nodes]!=LLONG_MAX)
        {
             printf("Case %d: %lld\n",k,dis[nodes]);
        }
        else
        {
             printf("Case %d: Impossible\n",k);
        }
        for(int i=1;i<=nodes;i++)s
        {
            node[i].clear();
        }
        cost.clear();
    }
    return 0;
}
/**                   ACCEPTED                          **/
