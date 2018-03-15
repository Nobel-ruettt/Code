#include <bits/stdc++.h>
using namespace std;
int marked[30];
int nodes,edges,node1,node2,max1;
vector<int>node[30];
void clear_node()
{
    for(int i=0;i<nodes;i++)
    {
        node[i].clear();
    }
}
void input_edges()
{
    for(int i=0;i<edges;i++)
    {
        scanf("%d%d",&node1,&node2);
        node[node1].push_back(node2);
        node[node2].push_back(node1);
    }
}
void clear_marking()
{
    for(int i=0;i<nodes;i++)
    {
        marked[i]=0;
    }
}
void dfs(int source,int time)
{
    marked[source]=1;
    if(max1<time)
    {
        max1=time;
    }
    int adj;
    for(int i=0;i<node[source].size();i++)
    {
        adj=node[source][i];
        if(marked[adj]==0)
        {
            dfs(adj,time+1);
        }
    }
    marked[source]=0;
}
void main_calculation()
{
    max1=0;
    for(int i=0;i<nodes;i++)
    {
        clear_marking();
        dfs(i,0);
    }
}
int main()
{
    while(scanf("%d%d",&nodes,&edges)==2)
    {
        clear_node();
        input_edges();
        main_calculation();
        printf("%d\n",max1);
    }
    return 0;
}
