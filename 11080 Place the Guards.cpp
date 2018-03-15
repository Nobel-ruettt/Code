#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll tes,nodes,edges;
vector<ll>node[210];
deque<ll>q;
ll colour[210];
void cle()
{
    for(ll i=0; i<nodes; i++)
    {
        node[i].clear();
        colour[i]=-1;
    }
}
void in_edge()
{
    ll node1,node2;
    for(ll i=0; i<edges; i++)
    {
        scanf("%lld%lld",&node1,&node2);
        node[node1].push_back(node2);
        node[node2].push_back(node1);
    }
}
ll main_bfs(ll main_source)
{
    ll source,adj;
    ll zeros=0;
    ll ones=0;
    q.clear();
    colour[main_source]=1;
    ones++;
    q.push_back(main_source);
    while(!q.empty())
    {
        source=q.front();
        q.pop_front();
        for(ll i=0; i<node[source].size(); i++)
        {
            adj=node[source][i];
            if(colour[adj]==-1)
            {
                if(colour[source]==1)
                {
                    colour[adj]=0;
                    zeros++;
                }
                else if(colour[source]==0)
                {
                    colour[adj]=1;
                    ones++;
                }
                q.push_back(adj);
            }
            else if(colour[adj]!=-1)
            {
                if(colour[adj]==colour[source])
                {
                    return LLONG_MAX;
                }
            }
        }
    }
    if(zeros==0 || ones==0)
    {
         return 1;
    }
    else
    {
        return min(zeros,ones);
    }
}
ll bfs()
{
    ll sum=0;
    ll check;
    for(ll i=0; i<nodes; i++)
    {
        if(colour[i]==-1)
        {
            check=main_bfs(i);
            if(check==LLONG_MAX)
            {
                return LLONG_MAX;
            }
            else
            {
                sum+=check;
            }
        }
    }
    return sum;
}
int main()
{
    scanf("%lld",&tes);
    for(ll i=1; i<=tes; i++)
    {
        scanf("%lld%lld",&nodes,&edges);
        cle();
        in_edge();
        ll tot=bfs();
        if(tot==LLONG_MAX)
        {
            printf("-1\n");
        }
        else
        {
            printf("%lld\n",tot);
        }
    }
    return 0;
}
