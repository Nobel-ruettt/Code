#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll nodes,edges,mark;
string node1,node2;
map<string,vector<string> >graph;
map<string,vector<string> >reverse_graph;
map<ll,vector<string> >components;
vector<string>node;
map<string,ll>colour;
map<string,ll>visited;
stack<string>finished_nodes;
void cle()
{
    graph.clear();
    reverse_graph.clear();
    components.clear();
    colour.clear();
    visited.clear();
    node.clear();
}
void in_edges()
{
    for(ll i=0; i<edges; i++)
    {
        cin>>node1>>node2;
        colour[node1]=-1;
        colour[node2]=-1;
        visited[node1]=-1;
        visited[node2]=-1;
        graph[node1].push_back(node2);
        reverse_graph[node2].push_back(node1);
    }
}
void nodess()
{
    map<string,ll>::iterator it;
    for(it=colour.begin();it!=colour.end();it++)
    {
         node.push_back(it->first);
    }
}
void clear_stack()
{
    while(!finished_nodes.empty())
    {
        finished_nodes.pop();
    }
}
void dfs(string source)
{
    string adj;
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
void dfs2(string source,ll mark)
{
    string adj;
    visited[source]=1;
    for(ll i=0;i<reverse_graph[source].size();i++)
    {
        adj=reverse_graph[source][i];
        if(visited[adj]==-1)
        {
            dfs2(adj,mark);
        }
    }
    components[mark].push_back(source);
}
void find_scc()
{
    for(ll i=0;i<node.size();i++)
    {
        if(colour[node[i]]==-1)
        {
            dfs(node[i]);
        }
    }
    string source;
    mark=1;
    while(!finished_nodes.empty())
    {
        source=finished_nodes.top();
        finished_nodes.pop();
        if(visited[source]==-1)
        {
            dfs2(source,mark);
            mark++;
        }
    }
}
int main()
{
    char c;
    ll cases=1;
    while(scanf("%lld%lld",&nodes,&edges)==2)
    {
        scanf("%*c",&c);
        if(nodes==0&&edges==0)
        {
            break;
        }
        cle();
        in_edges();
        nodess();
        clear_stack();
        find_scc();
        printf("Calling circles for data set %lld:\n",cases);
        for(ll i=1;i<mark;i++)
        {
            reverse(components[i].begin(),components[i].end());
            cout<<components[i][0];
            for(ll j=1;j<components[i].size();j++)
            {
                cout<<","<<components[i][j];
            }
            cout<<endl;
        }
        cases++;
    }
    return 0;
}
