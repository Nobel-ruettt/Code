#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll tes,nodes,edges;
vector<ll>graph[1100];
ll visited[1100];
ll rich[1100];
void cle()
{
    for(ll i=1;i<=nodes;i++)
    {
        graph[i].clear();
        visited[i]=-1;
    }
}
void in_riches()
{
    for(ll i=1;i<=nodes;i++)
    {
        scanf("%lld",&rich[i]);
    }
}
void in_edges()
{
    ll node1,node2;
    for(ll i=1;i<=edges;i++)
    {
        scanf("%lld%lld",&node1,&node2);
        graph[node1].push_back(node2);
        graph[node2].push_back(node1);
    }
}
ll main_bfs(ll main_source)
{
    ll source,adj;
    vector<ll>visited_nodes;
    deque<ll>q;
    visited[main_source]=1;
    q.push_back(main_source);
    visited_nodes.push_back(main_source);
    while(!q.empty())
    {
        source=q.front();
        q.pop_front();
        for(ll i=0;i<graph[source].size();i++)
        {
            adj=graph[source][i];
            if(visited[adj]==-1)
            {
                visited_nodes.push_back(adj);
                visited[adj]=1;
                q.push_back(adj);
            }
        }
    }
    ll sum=0;
    for(ll i=0;i<visited_nodes.size();i++)
    {
        sum+=rich[visited_nodes[i]];
    }
    if(sum%visited_nodes.size()==0)
    {
        return sum/visited_nodes.size();
    }
    else
    {
        return LLONG_MAX;
    }
}
vector<ll>eq;
ll bfs()
{
    eq.clear();
    for(ll i=1;i<=nodes;i++)
    {
        if(visited[i]==-1)
        {
            eq.push_back(main_bfs(i));
        }
    }
    ll falsee=0;
    ll first;
    for(ll i=0;i<eq.size();i++)
    {
        if(eq[i]!=LLONG_MAX)
        {
            first=eq[i];
            falsee=1;
            break;
        }
    }
    if(falsee==0)
    {
        return 0;
    }
    for(ll i=0;i<eq.size();i++)
    {
        if(eq[i]!=first)
        {
            return 0;
        }
    }
    return 1;
}
int main()
{
    scanf("%lld",&tes);
    for(ll i=1;i<=tes;i++)
    {
        scanf("%lld%lld",&nodes,&edges);
        cle();
        in_riches();
        in_edges();
        ll ans=bfs();
        if(ans==0)
        {
            printf("Case %lld: No\n",i);
        }
        else
        {
            printf("Case %lld: Yes\n",i);
        }
    }
    return 0;
}
