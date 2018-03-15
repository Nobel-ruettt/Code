#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pi pair<ll, pair<ll,ll> >
#define pii pair<ll,ll>
ll nodes,edges,new_edges,highest,node1,node2,weight,source_dis,source_node,yet_proposed,yet,adjecent,adjecent_cost;
vector<ll>node[10006];
vector<pii>cost[10006];
ll dis[10006][11];
bool marked[10006];
priority_queue<pi ,vector<pi> , greater <pi> >lis;
void clearr()
{
    for(int i=0; i<nodes; i++)
    {
        for(int j=0; j<=highest; j++)
        {
            dis[i][j]=LLONG_MAX;
        }
        node[i].clear();
        cost[i].clear();
        marked[i]=false;
    }
   while(!lis.empty())
   {
       lis.pop();
   }
}
void edge_input()
{
    for(int i=0; i<edges; i++)
    {
        scanf("%lld%lld%lld",&node1,&node2,&weight);
        node[node1].push_back(node2);
        cost[node1].push_back(make_pair(weight,0));
    }
    for(int i=0; i<new_edges; i++)
    {
        scanf("%lld%lld%lld",&node1,&node2,&weight);
        node[node1].push_back(node2);
        cost[node1].push_back(make_pair(weight,1));
    }
}
int main()
{
    ll tes;
    scanf("%lld",&tes);
    for(int i=1; i<=tes; i++)
    {
        scanf("%lld%lld%lld%lld",&nodes,&edges,&new_edges,&highest);
        clearr();
        edge_input();
        dis[0][0]=0;
        pi source;
        source.first=0;
        source.second.first=0;
        source.second.second=0;
        lis.push(source);
        while(!lis.empty())
        {
            source=lis.top();
            lis.pop();
            source_dis=source.first;
            source_node=source.second.first;
            yet_proposed=source.second.second;
            for(int j=0; j<node[source_node].size(); j++)
            {
                adjecent=node[source_node][j];
                adjecent_cost=cost[source_node][j].first;
                if(cost[source_node][j].second==1)
                {
                    yet=yet_proposed+1;
                }
                else
                {
                    yet=yet_proposed;
                }
                if(yet<=highest)
                {
                    if(dis[adjecent][yet]>source_dis+adjecent_cost)
                    {
                        dis[adjecent][yet]=source_dis+adjecent_cost;
                        lis.push(make_pair(dis[adjecent][yet],make_pair(adjecent,yet)));
                    }
                }
            }
        }
        ll minimum=LLONG_MAX;
        for(int j=0;j<=highest;j++)
        {
            if(dis[nodes-1][j]<minimum)
            {
                minimum=dis[nodes-1][j];
            }
        }
        if(minimum!=LLONG_MAX)
        {
            printf("Case %d: %lld\n",i,minimum);
        }
        else
        {
            printf("Case %d: Impossible\n",i);
        }
    }
    return 0;
}
