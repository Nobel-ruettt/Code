#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<ll>node[10005];
vector<ll>finished_nodes;
ll colour[10005];
ll tes,nodes,edges,num;
void cle()
{
    for(ll i=1;i<=nodes;i++)
    {
        node[i].clear();
    }
    finished_nodes.clear();
}
void clear_colour()
{
    for(ll i=1;i<=nodes;i++)
    {
        colour[i]=-1;
    }
}
void in_edges()
{
    ll node1,node2;
    for(ll i=0;i<edges;i++)
    {
        scanf("%lld%lld",&node1,&node2);
        node[node1].push_back(node2);
    }
}
void main_dfs(ll source)
{
    ll adj;
    colour[source]=1;
    for(ll i=0;i<node[source].size();i++)
    {
        adj=node[source][i];
        if(colour[adj]==-1)
        {
            main_dfs(adj);
        }
    }
    finished_nodes.push_back(source);
}
void dfs()
{
    clear_colour();
    for(ll i=1;i<=nodes;i++)
    {
        if(colour[i]==-1)
        {
            main_dfs(i);
        }
    }
}
void main_dfs2(ll source)
{
    ll adj;
    colour[source]=1;
    for(ll i=0;i<node[source].size();i++)
    {
        adj=node[source][i];
        if(colour[adj]==-1)
        {
            main_dfs2(adj);
        }
    }
}
void dfs2()
{
    num=0;
    clear_colour();
    ll length=finished_nodes.size()-1;
    for(ll i=length;i>=0;i--)
    {
        if(colour[finished_nodes[i]]==-1)
        {
            main_dfs2(finished_nodes[i]);
            num++;
        }
    }
}
int main()
{
    scanf("%lld",&tes);
    for(ll i=1;i<=tes;i++)
    {
        scanf("%lld%lld",&nodes,&edges);
        cle();
        in_edges();
        dfs();
        dfs2();
        printf("Case %lld: %lld\n",i,num);
    }
    return 0;
}
