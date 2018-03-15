#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxi 100005
bool comp(ll a,ll b)
{
    if(a>b)
    {
        return 1;
    }
    return 0;
}
vector<ll>main_graph[maxi];
vector<ll>auxi_graph[maxi];
vector<ll>components[maxi];
vector<ll>ase;
deque<ll>q;
stack<ll>finished_nodes;
ll which_component[maxi];
ll visited[maxi],colour[maxi],at_component;
ll n,m;
void in_edges()
{
    ll u,v;
    for(ll i=1;i<=m;i++)
    {
        scanf("%lld%lld",&u,&v);
        main_graph[u].push_back(v);
        auxi_graph[u].push_back(v);
        auxi_graph[v].push_back(u);
    }
    at_component=1;
//    for(ll i=1;i<=n;i++)
//    {
//        sort(main_graph[i].begin(),main_graph[i].end(),comp);
//        printf("Node %lld : ",i);
//        for(ll j=0;j<main_graph[i].size();j++)
//        {
//            cout<<main_graph[i][j]<<" ";
//        }
//        cout<<endl;
//    }
}
void bfs(ll m_source,ll now_component)
{
    ase.clear();
    visited[m_source]=1;
    which_component[m_source]=now_component;
    ase.push_back(m_source);
    q.push_back(m_source);
    while(!q.empty())
    {
        ll source=q.front();
        q.pop_front();
        for(ll i=0;i<auxi_graph[source].size();i++)
        {
            ll adj=auxi_graph[source][i];
            if(visited[adj]==0)
            {
                which_component[adj]=now_component;
                visited[adj]=1;
                ase.push_back(adj);
                q.push_back(adj);
            }
        }
    }
    sort(ase.begin(),ase.end(),comp);
}
void main_dfs(ll at_component)
{

}
int main()
{
    scanf("%lld%lld",&n,&m);
    in_edges();
    for(ll i=1;i<=n;i++)
    {
        if(visited[i]==0)
        {
            bfs(i,at_component);
            main_dfs(at_component);
            at_component++;
        }
    }
    return 0;
}
