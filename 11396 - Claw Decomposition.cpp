#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<ll>node[310];
deque<ll>q;
ll colour[310];
ll nodes,node1,node2;
void cle()
{
    for(ll i=1;i<=nodes;i++)
    {
        node[i].clear();
        colour[i]=-1;
    }
}
void in_edge()
{
    while(scanf("%lld%lld",&node1,&node2)==2)
    {
        if(node1==0&&node2==0)
        {
            return ;
        }
        node[node1].push_back(node2);
        node[node2].push_back(node1);
    }
}
ll main_bfs(ll main_source)
{
    ll source,adj;
    colour[main_source]=1;
    q.clear();
    q.push_back(main_source);
    while(!q.empty())
    {
        source=q.front();
        q.pop_front();
        for(ll i=0;i<node[source].size();i++)
        {
            adj=node[source][i];
            if(colour[adj]==-1)
            {
                if(colour[source]==1)
                {
                    colour[adj]=0;
                }
                else if(colour[source]==0)
                {
                    colour[adj]=1;
                }
                q.push_back(adj);
            }
            if(colour[adj]!=-1)
            {
                if(colour[adj]==colour[source])
                {
                    return LLONG_MAX;
                }
            }
        }
    }
    return 1;
}
ll bfs()
{
    ll check;
    for(ll i=1;i<=nodes;i++)
    {
        if(colour[i]==-1)
        {
            check=main_bfs(i);
            if(check==LLONG_MAX)
            {
                return LLONG_MAX;
            }
        }
    }
    return 1;
}
int main()
{
    while(scanf("%lld",&nodes)==1)
    {
        if(nodes==0)
        {
            break;
        }
        cle();
        in_edge();
        ll tot=bfs();
        if(tot==LLONG_MAX)
        {
            printf("NO\n");
        }
        else
        {
            printf("YES\n");
        }
    }
    return 0;
}
