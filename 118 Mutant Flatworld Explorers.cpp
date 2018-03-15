#include <bits/stdc++.h>
using namespace std;
vector<int>node[110];
vector<int>unmarked;
int marked[110];
int nodes,start_node,ad_node,tot_source,main_source;
void clear_nodes()
{
    for(int i=1; i<=nodes; i++)
    {
        node[i].clear();
    }
}
void adjecency_list()
{
    while(1)
    {
        scanf("%d",&start_node);
        if(start_node==0)
        {
            break;
        }
        while(1)
        {
            scanf("%d",&ad_node);
            if(ad_node==0)
            {
                node[start_node].push_back(ad_node);
                break;
            }
            node[start_node].push_back(ad_node);
        }
    }
}
void clear_mark()
{
    for(int i=1;i<=nodes;i++)
    {
        marked[i]=0;
    }
}
void dfs(int source)
{
    int adj;
    for(int i=0;i<node[source].size();i++)
    {
        adj=node[source][i];
        if(marked[adj]==0)
        {
            marked[adj]=1;
            dfs(adj);
        }
    }
}
void take_source()
{
    scanf("%d",&tot_source);
    for(int i=0;i<tot_source;i++)
    {
        scanf("%d",&main_source);
        clear_mark();
        dfs(main_source);
        unmarked.clear();
        for(int j=1;j<=nodes;j++)
        {
            if(marked[j]==0)
            {
                unmarked.push_back(j);
            }
        }
        printf("%d",unmarked.size());
        for(int j=0;j<unmarked.size();j++)
        {
            printf(" %d",unmarked[j]);
        }
        printf("\n");
    }
}
int main()
{
    while(scanf("%d",&nodes)==1)
    {
        if(nodes==0)
        {
            break;
        }
        clear_nodes();
        adjecency_list();
        take_source();
    }
    return 0;
}
