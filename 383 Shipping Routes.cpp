#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll tes,nodes,edges,query,ship_size;
string node1,node2,source,des;
vector<string>ware;
map<string,vector<string> >node;
map<string,ll>level;
deque<string>q;
void cle()
{
    ware.clear();
    node.clear();
    level.clear();
}
void level_clear()
{
    for(ll i=0;i<ware.size();i++)
    {
        level[ware[i]]=-1;
    }
}
void in_nodes()
{
    string w;
    for(ll i=1;i<=nodes;i++)
    {
        cin>>w;
        ware.push_back(w);
    }
    level_clear();
}
void in_edges()
{
    for(ll i=1;i<=edges;i++)
    {
        cin>>node1>>node2;
        node[node1].push_back(node2);
        node[node2].push_back(node1);
    }
}
void bfs(string main_source)
{
    q.clear();
    string so,adj;
    level[main_source]=0;
    q.push_back(main_source);
    while(!q.empty())
    {
        so=q.front();
        q.pop_front();
        for(ll i=0;i<node[so].size();i++)
        {
            adj=node[so][i];
            if(level[adj]==-1)
            {
                level[adj]=level[so]+1;
                q.push_back(adj);
            }
        }
    }
}
int main()
{
    scanf("%lld",&tes);
    printf("SHIPPING ROUTES OUTPUT\n\n");
    for(ll i=1;i<=tes;i++)
    {
        printf("DATA SET %lld\n\n",i);
        cle();
        scanf("%lld%lld%lld",&nodes,&edges,&query);
        in_nodes();
        in_edges();
        for(ll j=1;j<=query;j++)
        {
            cin>>ship_size>>source>>des;
            level_clear();
            bfs(source);
            if(level[des]==-1)
            {
                printf("NO SHIPMENT POSSIBLE\n");
            }
            else
            {
                printf("$%lld\n",ship_size*level[des]*100);
            }
        }
        printf("\n");
    }
    printf("END OF OUTPUT\n\n");
    return 0;
}
