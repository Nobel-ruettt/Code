#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sc(n) scanf("%lld",&n)
#define maxn 110
ll n,m,ans;
vector<ll>graph[maxn];
deque<ll>q;
vector<ll>nodes;
ll parent[maxn];
ll visited[maxn];
void cle()
{
    for(ll i=0; i<maxn; i++)
    {
        graph[i].clear();
        parent[i]=-1;
        visited[i]=0;
    }
    ans=0;
    nodes.clear();
}
void in_edge()
{
    ll u,v;
    for(ll i=1; i<=m; i++)
    {
        sc(u);
        sc(v);
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
}
ll bfs(ll source)
{
    nodes.clear();
    ll maxi_node=0;
    ll count1=0;
    visited[source]=1;
    q.push_back(source);
    nodes.push_back(source);
    while(!q.empty())
    {
        ll s=q.front();
        q.pop_front();
        if(graph[s].size()>maxi_node)
        {
            maxi_node=graph[s].size();
            count1=1;
        }
        else if(graph[s].size()==maxi_node)
        {
            count1++;
        }
        for(ll i=0; i<graph[s].size(); i++)
        {
            ll adj=graph[s][i];
            if(visited[adj]==0)
            {
                visited[adj]=1;
                nodes.push_back(adj);
                q.push_back(adj);
            }
        }
    }
//    cout<<maxi_node<<" "<<count1<<endl;
//    for(ll i=0;i<nodes.size();i++)
//    {
//        cout<<nodes[i]<<" ";
//    }
//    cout<<endl;
    if(count1==1 || count1>2)
    {
        return 0;
    }
    if(count1==2)
    {
        if(nodes.size()==2 && maxi_node==1)
        {
            return 1;
        }
    }
    ll now_selected_source;
    for(ll i=0; i<nodes.size(); i++)
    {
        if(graph[nodes[i]].size()<(maxi_node-1))
        {
            return 0;
        }
        if(graph[nodes[i]].size()==(maxi_node-1))
        {
            now_selected_source=nodes[i];
        }
    }
    set<ll>sources;
    parent[now_selected_source]=now_selected_source;
    sources.insert(now_selected_source);
    q.push_back(now_selected_source);
    while(!q.empty())
    {
        ll s=q.front();
        q.pop_front();
        for(ll i=0; i<graph[s].size(); i++)
        {
            ll adj=graph[s][i];
            if(parent[adj]==-1)
            {
                if(parent[s]==s)
                {
                    parent[adj]=s;
                    sources.insert(s);
                    q.push_back(adj);
                }
                else
                {
                    parent[adj]=adj;
                    sources.insert(adj);
                    q.push_back(adj);
                }
            }
        }
    }
    if(sources.size()==2)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int main()
{
    ll tes;
    sc(tes);
    for(ll cas=1; cas<=tes; cas++)
    {
        sc(n);
        sc(m);
        cle();
        in_edge();
        for(ll i=1; i<=n; i++)
        {
            if(visited[i]==0)
            {
                ans+=bfs(i);
            }
        }
        printf("Case #%lld: %lld\n",cas,ans);
    }
    return 0;
}
