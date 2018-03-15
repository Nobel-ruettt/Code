#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<ll>node[210];
deque<ll>q;
ll tes,nodes,h_edge,node1,node2,flag;
ll colour[210];
void cle()
{
    for(ll i=1; i<=nodes; i++)
    {
        node[i].clear();
        colour[i]=-1;
    }
}
void in_edge()
{
    for(ll i=1; i<=nodes; i++)
    {
        node1=i;
        scanf("%lld",&h_edge);
        for(ll j=1; j<=h_edge; j++)
        {
            scanf("%lld",&node2);
            node[node1].push_back(node2);
            node[node2].push_back(node1);
        }
    }
//    for(ll i=1;i<=nodes;i++)
//    {
//        printf("Node %lld : ",i);
//        for(ll j=0;j<node[i].size();j++)
//        {
//            printf("%lld ",node[i][j]);
//        }
//        printf("\n");
//    }
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
    return max(zeros,ones);
}
ll bfs()
{
    ll check;
    ll sum=0;
    for(ll i=1; i<=nodes; i++)
    {
        if(colour[i]==-1)
        {
            check=main_bfs(i);
            if(check!=LLONG_MAX)
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
        scanf("%lld",&nodes);
        cle();
        in_edge();
        flag=bfs();
        if(flag==LLONG_MAX)
        {
            printf("0\n");
            continue;
        }
        printf("%lld\n",flag);
    }
    return 0;
}
