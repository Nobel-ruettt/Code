#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<ll>graph[2010];
vector<ll>reverse_graph[2010];
vector<ll>component_graph[2010];
vector<ll>components[2010];
map<ll,ll>node_track;
vector<ll>nodes;
ll tes,manush,edges,zero,mark;
ll visited[2010];
ll colour[2010];
ll component_visited[2010];
ll component_indegree[2010];
ll component_outdegree[2010];
ll mark_component[2010];
stack<ll>finished_nodes;
deque<ll>que;
void cle()
{
    node_track.clear();
    nodes.clear();
    for(ll i=0; i<2010; i++)
    {
        graph[i].clear();
        reverse_graph[i].clear();
        components[i].clear();
    }
    zero=0;
}
void in_edges()
{
    ll node1,node2;
    for(ll i=0; i<edges; i++)
    {
        scanf("%lld%lld",&node1,&node2);
        if(node1==0)
        {
            zero=1;
        }
        if(node_track[node1]==0)
        {
            nodes.push_back(node1);
            node_track[node1]=1;
        }
        if(node_track[node2]==0)
        {
            nodes.push_back(node2);
            node_track[node2]=1;
        }
        graph[node1].push_back(node2);
        reverse_graph[node2].push_back(node1);
    }
}
//void check_ad_list()
//{
//    for(ll j=0; j<nodes.size(); j++)
//    {
//        printf("Node %lld : ",nodes[j]);
//        for(ll k=0; k<graph[nodes[j]].size(); k++)
//        {
//            cout<<graph[nodes[j]][k]<<" ";
//        }
//        cout<<endl;
//    }
//}
void clear_vis_colour_stack()
{
    for(ll i=0; i<nodes.size(); i++)
    {
        visited[nodes[i]]=-1;
        colour[nodes[i]]=-1;
    }
    while(!finished_nodes.empty())
    {
        finished_nodes.pop();
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
    for(ll i=0; i<nodes.size(); i++)
    {
        if(colour[nodes[i]]==-1)
        {
            dfs(nodes[i]);
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
void clearr()
{
    for(ll i=1;i<mark;i++)
    {
        component_graph[i].clear();
        component_visited[i]=-1;
        component_outdegree[i]=0;
        component_indegree[i]=0;
    }
}
void make_component_graph_and_indegree()
{
    for(ll i=1;i<mark;i++)
    {
        sort(components[i].begin(),components[i].end());
        for(ll j=0;j<components[i].size();j++)
        {
            mark_component[components[i][j]]=i;
        }
    }
    ///component_check();
    ll source,adj;
    for(ll i=0;i<nodes.size();i++)
    {
        source=nodes[i];
        for(ll j=0;j<graph[source].size();j++)
        {
            adj=graph[source][j];
            if(mark_component[source]!=mark_component[adj])
            {
                component_indegree[mark_component[adj]]++;
                component_outdegree[mark_component[source]]++;
                component_graph[mark_component[source]].push_back(mark_component[adj]);
            }
        }
    }
//    for(ll i=1;i<mark;i++)
//    {
//        printf("Node %lld : ",i);
//        for(ll j=0;j<component_graph[i].size();j++)
//        {
//            cout<<component_graph[i][j]<<" ";
//        }
//        cout<<endl;
//    }
}
int find_the_source_and_do_bfs()
{
    ll main_source,source,adj;
    for(ll i=1;i<mark;i++)
    {
        if(components[i][0]==0)
        {
            main_source=i;
        }
    }
    ///cout<<main_source<<endl;
    que.clear();
    component_visited[main_source]=1;
    que.push_back(main_source);
    while(!que.empty())
    {
        source=que.front();
        que.pop_front();
        for(ll i=0;i<component_graph[source].size();i++)
        {
            adj=component_graph[source][i];
            if(component_visited[adj]==-1)
            {
                component_visited[adj]=1;
                que.push_back(adj);
            }
        }
    }
    for(ll i=1;i<mark;i++)
    {
        if(component_visited[i]==-1)
        {
            return 0;
        }
    }
    return 1;
}
int that_is_enough_ar_code_korum_na()
{
    for(ll i=1;i<mark;i++)
    {
        if(component_outdegree[i]>1)
        {
            return 0;
        }
    }
    return 1;
}
int main()
{
    scanf("%lld",&tes);
    for(ll i=1; i<=tes; i++)
    {
        scanf("%lld",&manush);
        cle();
        for(ll j=1; j<=manush; j++)
        {
            scanf("%lld",&edges);
            in_edges();
        }
        if(zero==0)
        {
            printf("Case %lld: NO\n",i);
            continue;
        }
        clear_vis_colour_stack();
        find_scc();
        ///component_check();
        clearr();
        ///cout<<"gaba"<<endl;
        make_component_graph_and_indegree();
        ///cout<<"gaba"<<endl;
        ll check=find_the_source_and_do_bfs();
        ///cout<<"gaba"<<endl;
        if(check==0)
        {
            printf("Case %lld: NO\n",i);
            continue;
        }
        check=that_is_enough_ar_code_korum_na();
        ///cout<<"gaba"<<endl;
        if(check==0)
        {
            printf("Case %lld: NO\n",i);
            continue;
        }
        printf("Case %lld: YES\n",i);
    }
    return 0;
}
