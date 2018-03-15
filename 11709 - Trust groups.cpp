#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll nodes,edges,mark;
vector<ll>graph[1100];
vector<ll>reverse_graph[1100];
map<string,ll>node;
stack<ll>finished_nodes;
ll visited[1100];
ll colour[1100];
void cle()
{
    node.clear();
    for(ll i=1;i<=nodes;i++)
    {
        graph[i].clear();
        reverse_graph[i].clear();
    }
}
void in_nodes()
{
    string s1;
    for(ll i=1;i<=nodes;i++)
    {
        getline(cin,s1);
        node[s1]=i;
    }
}
void in_edges()
{
    string s1,s2;
    ll node1,node2;
    for(ll i=0;i<edges;i++)
    {
        getline(cin,s1);
        getline(cin,s2);
        node1=node[s1];
        node2=node[s2];
        graph[node1].push_back(node2);
        reverse_graph[node2].push_back(node1);
    }
}
void clear_stack_visited_colour()
{
    for(ll i=1;i<=nodes;i++)
    {
        visited[i]=-1;
        colour[i]=-1;
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
    char c;
    while(scanf("%lld%lld",&nodes,&edges)==2)
    {
        if(nodes==0&&edges==0)
        {
            break;
        }
        scanf("%*c",&c);
        cle();
        in_nodes();
        in_edges();
        clear_stack_visited_colour();
        find_scc();
        printf("%lld\n",mark);
    }
    return 0;
}
