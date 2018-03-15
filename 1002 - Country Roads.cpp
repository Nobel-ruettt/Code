#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define max1 510
ll level [max1+3];
ll marked[max1+3];
deque<ll>que;
vector<ll>node[max1+3];
map<ll,map<ll,ll> >cost;
int main()
{
    ll tes,nodes,edges,node1,node2,weight,root,adj,source,now_up;
    scanf("%lld",&tes);
    for(int i=1;i<=tes;i++)
    {
        memset(level,-1,sizeof(level));
        memset(marked,-1,sizeof(marked));
        scanf("%lld",&nodes);
        scanf("%lld",&edges);
        for(int j=0;j<edges;j++)
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
            else if(cost[node1][node2]==0)
            {
                cost[node1][node2]=weight;
                cost[node2][node1]=weight;
            }
        }
        scanf("%lld",&root);
        level[root]=0;
        que.push_back(root);
        while(!que.empty())
        {
            source=que.front();
            que.pop_front();
            for(int j=0;j<node[source].size();j++)
            {
                adj=node[source][j];
                if(level[source]>cost[source][adj])
                {
                    now_up=level[source];
                }
                else if(level[source]<cost[source][adj])
                {
                    now_up=cost[source][adj];
                }
                else if(level[source]==cost[source][adj])
                {
                    now_up=now_up=level[source];
                }
                if(level[adj]==-1)
                {
                    level[adj]=now_up;
                    que.push_back(adj);
                }
                else if(level[adj]!=-1)
                {
                    if(level[adj]>now_up)
                    {
                        level[adj]=now_up;
                        que.push_back(adj);
                    }
                }
            }
        }
        printf("Case %d:\n",i);
        for(int j=0;j<nodes;j++)
        {
            if(level[j]==-1)
            {
                printf("Impossible\n");
            }
            else
            {
                printf("%lld\n",level[j]);
            }
        }
        que.clear();
        cost.clear();
        for(int i=0;i<nodes;i++)
        {
            node[i].clear();
        }
    }
    return 0;
}
/**                           ACCEPTED                                           */
