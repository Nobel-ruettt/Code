#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll nodes,edges,mark;
char c;
string s,s1,s2;
vector<string>node;
map<string,vector<string> >graph;
map<string,vector<string> >reverse_graph;
vector<string>components[1100];
map<string,ll>colour;
map<string,ll>visited;
stack<string>finished_nodes;
void cle()
{
    node.clear();
    graph.clear();
    reverse_graph.clear();
    colour.clear();
    visited.clear();
    for(ll i=0;i<nodes;i++)
    {
        components[i].clear();
    }
}
void clear_stack_visited_colour()
{
    for(ll i=0;i<node.size();i++)
    {
        colour[node[i]]=-1;
        visited[node[i]]=-1;
    }
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
    mark=0;
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
    while(cin>>nodes>>edges)
    {
        if(nodes==0&&edges==0)
        {
            break;
        }
        scanf("%*c",&c);
        ios::sync_with_stdio(false);
        cle();
        for(ll i=0; i<nodes; i++)
        {
            getline(cin,s);
            node.push_back(s);
        }
        for(ll i=0;i<edges;i++)
        {
            getline(cin,s1);
            getline(cin,s2);
            graph[s1].push_back(s2);
            reverse_graph[s2].push_back(s1);
        }
        clear_stack_visited_colour();
        find_scc();
        cout<<mark<<endl;
    }
    return 0;
}
