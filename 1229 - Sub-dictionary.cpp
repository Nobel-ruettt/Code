#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll nodes;
map<string,ll>str_to_number;
map<ll,string>number_to_str;
vector<ll>graph[110];
vector<ll>reverse_graph[110];
vector<ll>components[110];
vector<string>ans;
ll colour[110];
ll visited[110];
ll mark;
stack<ll>finished_nodes;
void cle()
{
    str_to_number.clear();
    number_to_str.clear();
    for(ll i=1;i<=nodes;i++)
    {
        graph[i].clear();
        reverse_graph[i].clear();
        components[i].clear();
    }
    ans.clear();
}
void clear_stack_visited_colour()
{
    for(ll i=1;i<=nodes;i++)
    {
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
    string line;
    string number;
    vector<string>nodess;
    ll count1=1;
    ll source_node,adj;
    for(ll i=1; i<=nodes; i++)
    {
        nodess.clear();
        getline(cin, line);
        stringstream ss(line);
        while (ss >> number)
        {
            nodess.push_back(number);
        }
        if(str_to_number[nodess[0]]==0)
        {
            str_to_number[nodess[0]]=count1;
            number_to_str[count1]=nodess[0];
            source_node=count1;
            count1++;
        }
        else
        {
            source_node=str_to_number[nodess[0]];
        }
        for(ll i=1; i<nodess.size(); i++)
        {
            if(str_to_number[nodess[i]]==0)
            {
                str_to_number[nodess[i]]=count1;
                number_to_str[count1]=nodess[i];
                adj=count1;
                count1++;
            }
            else
            {
                adj=str_to_number[nodess[i]];
            }
            graph[adj].push_back(source_node);
            reverse_graph[source_node].push_back(adj);
        }
    }
}
void dfs(ll source)
{
    ll adj;
    colour[source]=1;
    for(ll i=0;i<graph[source].size();i++)
    {
        adj=graph[source][i];
        if(colour[adj]==-1)
        {
            dfs(adj);
        }
    }
    finished_nodes.push(source);
}
void dfs2(ll source,ll mark)
{
    ll adj;
    visited[source]=1;
    for(ll i=0;i<reverse_graph[source].size();i++)
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
    for(ll i=1;i<=nodes;i++)
    {
        if(colour[i]==-1)
        {
            dfs(i);
        }
    }
    mark=0;
    ll source;
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
int main()
{
    char c;
    while(scanf("%lld",&nodes)==1)
    {
        if(nodes==0)
        {
            break;
        }
        scanf("%*c",&c);
        cle();
        in_edges();
        clear_stack_visited_colour();
        find_scc();
        for(ll i=0;i<mark;i++)
        {
            if(components[i].size()>1)
            {
                for(ll j=0;j<components[i].size();j++)
                {
                    ans.push_back(number_to_str[components[i][j]]);
                }
            }
        }
        cout<<ans.size()<<endl;
        sort(ans.begin(),ans.end());
        cout<<ans[0];
        for(ll i=1;i<ans.size();i++)
        {
            cout<<" "<<ans[i];
        }
        cout<<endl;
    }
    return 0;
}
