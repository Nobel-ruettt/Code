#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<ll>graph[20];
vector<ll>reverse_graph[20];
vector<ll>components[20];
vector<ll>component_graph[20];
stack<ll>finished_nodes;
ll visited[20];
ll colour[20];
ll mark_component[20];
ll com_visited[20];
ll tes,nodes,edges,mark,ans1;
void cle()
{
    for(ll i=1; i<=nodes; i++)
    {
        graph[i].clear();
        reverse_graph[i].clear();
        components[i].clear();
        visited[i]=-1;
        colour[i]=-1;
    }
    while(!finished_nodes.empty())
    {
        finished_nodes.pop();
    }
}
void in_edges()
{
    ll node1,node2;
    for(ll i=0;i<edges;i++)
    {
        scanf("%lld%lld",&node1,&node2);
        graph[node1].push_back(node2);
        reverse_graph[node2].push_back(node1);
    }
}
void check_ad_list()
{
    for(ll j=1; j<=nodes; j++)
    {
        printf("Node %lld : ",j);
        for(ll k=0; k<graph[j].size(); k++)
        {
            cout<<graph[j][k]<<" ";
        }
        cout<<endl;
    }
}
void dfs(ll source)
{
    colour[source]=1;
    for(ll i=0; i<graph[source].size(); i++)
    {
        if(colour[graph[source][i]]==-1)
        {
            dfs(graph[source][i]);
        }
    }
    finished_nodes.push(source);
}
void dfs2(ll source,ll mark)
{
    ll adj;
    visited[source]=1;
    for(ll i=0; i<reverse_graph[source].size(); i++)
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
    for(ll i=1; i<=nodes; i++)
    {
        if(colour[i]==-1)
        {
            dfs(i);
        }
    }
    ll source;
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
void component_check()
{
    for(ll j=1; j<mark; j++)
    {
        printf("Components %lld : ",j);
        for(ll k=0; k<components[j].size(); k++)
        {
            printf("%lld ",components[j][k]);
        }
        cout<<endl;
    }
}
void cler()
{
    for(ll i=1;i<mark;i++)
    {
        component_graph[i].clear();
        colour[i]=-1;
        com_visited[i]=-1;
    }
    while(!finished_nodes.empty())
    {
        finished_nodes.pop();
    }
}
void make_remodeled_graph()
{
    for(ll i=1;i<mark;i++)
    {
        for(ll j=0;j<components[i].size();j++)
        {
            mark_component[components[i][j]]=i;
        }
    }
    ll source,adj;
    for(ll i=1;i<=nodes;i++)
    {
        source=i;
        for(ll j=0;j<graph[source].size();j++)
        {
            adj=graph[source][j];
            if(mark_component[source]!=mark_component[adj])
            {
                component_graph[mark_component[source]].push_back(mark_component[adj]);
            }
        }
    }
    for(ll i=1;i<mark;i++)
    {
        printf("Node %lld : ",i);
        for(ll j=0;j<component_graph[i].size();j++)
        {
            cout<<component_graph[i][j]<<" ";
        }
        cout<<endl;
    }
}
void dfs3(ll source)
{
    colour[source]=1;
    for(ll i=0; i<component_graph[source].size(); i++)
    {
        if(colour[component_graph[source][i]]==-1)
        {
            dfs3(component_graph[source][i]);
        }
    }
    finished_nodes.push(source);
}
void make_top_order_of_remodeled_graph()
{
    for(ll i=1;i<mark;i++)
    {
        if(colour[i]==-1)
        {
            dfs3(i);
        }
    }
}
deque<ll>que;
ll level[20];
ll parent[20];
void bfs(ll main_source)
{
    que.empty();
    memset(level,-1,sizeof(level));
    memset(parent,-1,sizeof(parent));
    ll source,adj;
    level[main_source]=0;
    parent[main_source]=-1;
    que.push_back(main_source);
    while(!que.empty())
    {
        source=que.front();
        que.pop_front();
        for(ll i=0;i<component_graph[source].size();i++)
        {
            adj=component_graph[source][i];
            if(level[adj]==-1&&com_visited[adj]==-1)
            {
                parent[adj]=source;
                level[adj]=level[source]+1;
                que.push_back(adj);
            }
        }
    }
    ll maxi=-1;
    ll max_pos;
    for(ll i=1;i<mark;i++)
    {
       if(level[i]>maxi)
       {
           maxi=level[i];
           max_pos=i;
       }
    }
    ll l=max_pos;
    while(1)
    {
        if(parent[l]==-1)
        {
            com_visited[l]=1;
            break;
        }
        com_visited[l]=1;
        l=parent[l];
    }
    for(ll i=1;i<mark;i++)
    {
        printf("Com visited %lld: %lld\n",i,com_visited[i]);
    }
}
void bfs_on_remodeled_graph()
{
    ll top;
    ans1=0;
    while(!finished_nodes.empty())
    {
        top=finished_nodes.top();
        finished_nodes.pop();
        if(com_visited[top]==-1)
        {
            ans1++;
            cout<<"top "<<top<<endl;
            bfs(top);
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
        check_ad_list();
        find_scc();
        component_check();
        cler();
        make_remodeled_graph();
        make_top_order_of_remodeled_graph();
        bfs_on_remodeled_graph();
        printf("Case %lld: %lld\n",i,ans1);
    }
    return 0;
}
//1
//9 11
//1 2
//2 3
//3 4
//4 1
//3 5
//5 8
//8 9
//4 9
//5 6
//6 7
//7 5
//1
//9 9
//1 2
//2 3
//3 1
//3 4
//3 5
//4 6
//7 6
//7 9
//7 8

