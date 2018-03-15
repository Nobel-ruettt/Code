#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll nodes,edges,mark;
vector<ll>graph[2010];
vector<ll>reverse_graph[2010];
stack<ll>finished_nodes;
ll colour[2010];
ll visited[2010];
void cle()
{
    for(ll i=1;i<=nodes;i++)
    {
        graph[i].clear();
        reverse_graph[i].clear();
    }
}
void in_edge()
{
    ll node1,node2,p;
    for(ll i=0;i<edges;i++)
    {
        scanf("%lld%lld%lld",&node1,&node2,&p);
        if(p==1)
        {
            graph[node1].push_back(node2);
            reverse_graph[node2].push_back(node1);
        }
        else if(p==2)
        {
            graph[node1].push_back(node2);
            graph[node2].push_back(node1);
            reverse_graph[node2].push_back(node1);
            reverse_graph[node1].push_back(node2);
        }
    }
}
void clear_visited_colour_stack()
{
    for(ll i=1;i<=nodes;i++)
    {
        colour[i]=-1;
        visited[i]=-1;
    }
    while(!finished_nodes.empty())
    {
        finished_nodes.pop();
    }
}
void dfs(ll source)
{
    ll adj;
    colour[source]=1;
    for(ll i=0;i<graph[source].size();i++)
    {
        adj=graph[source][i];
        if(colour[adj]==-1)
        {
            dfs(adj);
        }
    }
    finished_nodes.push(source);
}
void dfs2(ll source)
{
    ll adj;
    visited[source]=1;
    for(ll i=0;i<reverse_graph[source].size();i++)
    {
        adj=reverse_graph[source][i];
        if(visited[adj]==-1)
        {
            dfs2(adj);
        }
    }
}
void find_scc()
{
    for(ll i=1;i<=nodes;i++)
    {
        if(colour[i]==-1)
        {
            dfs(i);
        }
    }
    ll source;
    mark=0;
    while(!finished_nodes.empty())
    {
        source=finished_nodes.top();
        finished_nodes.pop();
        if(visited[source]==-1)
        {
            dfs2(source);
            mark++;
        }
    }
}
int main()
{
    while(scanf("%lld%lld",&nodes,&edges)==2)
    {
        if(nodes==0&&edges==0)
        {
            break;
        }
        cle();
        in_edge();
        clear_visited_colour_stack();
        find_scc();
        if(mark==1)
        {
            printf("1\n");
        }
        else
        {
            printf("0\n");
        }
    }
    return 0;
}
