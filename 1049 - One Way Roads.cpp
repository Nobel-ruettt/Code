#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll tes,nodes;
vector<ll>node[110];
ll edge_visited[110][110];
ll edge_visited2[110][110];
ll visited[110];
void cle()
{
    for(ll i=1;i<=nodes;i++)
    {
        node[i].clear();
    }
    memset(edge_visited,-1,sizeof(edge_visited));
    memset(edge_visited2,-1,sizeof(edge_visited2));
}
void cle_visit()
{
    memset(visited,-1,sizeof(visited));
}
void in_edges()
{
    ll node1,node2,cost;
    for(ll i=1;i<=nodes;i++)
    {
        scanf("%lld%lld%lld",&node1,&node2,&cost);
        node[node1].push_back(node2);
        node[node2].push_back(node1);
        edge_visited[node1][node2]=cost;
        edge_visited[node2][node1]=cost;
        edge_visited2[node1][node2]=1;
    }
//    ll adj;
//    for(ll i=1;i<=nodes;i++)
//    {
//        printf("Node %lld : \n",i);
//        for(ll j=0;j<node[i].size();j++)
//        {
//            adj=node[i][j];
//            cout<<adj<<" "<<edge_visited[i][adj]<<" "<<edge_visited2[i][adj]<<endl;
//        }
//        cout<<endl;
//    }
}
deque<ll>que;
ll bfs()
{
    cle_visit();
    ll main_source=1;
    visited[main_source]=1;
    ll first=node[main_source][0];
    ll sum1=0;
    if(edge_visited2[main_source][first]==-1)
    {
        sum1+=edge_visited[main_source][first];
    }
    visited[first]=1;
    que.clear();
    que.push_back(first);
    ll source;
    ll adj;
    while(!que.empty())
    {
        source=que.front();
        que.pop_front();
       /// cout<<"Source "<<source<<endl;
        for(ll i=0;i<node[source].size();i++)
        {
            adj=node[source][i];
            if(visited[adj]==-1)
            {
                if(edge_visited2[source][adj]==-1)
                {
                    sum1+=edge_visited[source][adj];
                }
                visited[adj]=1;
                que.push_back(adj);
            }
        }
    }
    if(edge_visited2[source][main_source]==-1)
    {
        sum1+=edge_visited[source][main_source];
    }
    cle_visit();
    main_source=1;
    visited[main_source]=1;
    ll second=node[main_source][1];
    ll sum2=0;
    if(edge_visited2[main_source][second]==-1)
    {
        sum2+=edge_visited[main_source][second];
    }
    visited[second]=1;
    que.clear();
    que.push_back(second);
    while(!que.empty())
    {
        source=que.front();
        que.pop_front();
       /// cout<<"Source "<<source<<endl;
        for(ll i=0;i<node[source].size();i++)
        {
            adj=node[source][i];
            if(visited[adj]==-1)
            {
                if(edge_visited2[source][adj]==-1)
                {
                    sum2+=edge_visited[source][adj];
                }
                visited[adj]=1;
                que.push_back(adj);
            }
        }
    }
    if(edge_visited2[source][main_source]==-1)
    {
        sum2+=edge_visited[source][main_source];
    }
    return min(sum1,sum2);
}
int main()
{
    scanf("%lld",&tes);
    for(ll i=1;i<=tes;i++)
    {
        scanf("%lld",&nodes);
        cle();
        in_edges();
        ll ans=bfs();
        printf("Case %lld: %lld\n",i,ans);
    }
    return 0;
}
