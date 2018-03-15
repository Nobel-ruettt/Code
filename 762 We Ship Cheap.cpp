#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll edges;
char c;
string s1,s2;
string main_source,destination;
map<string,vector<string> >node;
map<string,string>parent;
map<string,ll>visited;
deque<string>que;
stack<string>path;
void cle()
{
    node.clear();
    parent.clear();
    visited.clear();
}
void in_edges()
{
    for(ll i=0; i<edges; i++)
    {
        cin>>s1>>s2;
        node[s1].push_back(s2);
        node[s2].push_back(s1);
        visited[s1]=-1;
        visited[s2]=-1;
        parent[s1]=-1;
        parent[s2]=-1;
    }
    cin>>main_source>>destination;
}
void bfs_clear()
{
    que.clear();
    while(!path.empty())
    {
        path.pop();
    }
}
void bfs()
{
    string source,adj;
    bfs_clear();
    visited[main_source]=1;
    parent[main_source]=main_source;
    que.push_back(main_source);
    while(!que.empty())
    {
        source=que.front();
        que.pop_front();
        for(ll i=0; i<node[source].size(); i++)
        {
            adj=node[source][i];
            if(visited[adj]==-1)
            {
                visited[adj]=1;
                parent[adj]=source;
                que.push_back(adj);
            }
        }
    }
    if(visited[destination]==-1)
    {
        printf("No route\n");
    }
    else
    {
          string s=destination;
          while(parent[s]!=s)
          {
               cout<<s<<" "<<parent[s];
          }
          cout<<endl;
    }
}
int main()
{
    while(scanf("%lld",&edges)==1)
    {
        scanf("%*c",&c);
        cle();
        in_edges();
        bfs();
    }
    return 0;
}
