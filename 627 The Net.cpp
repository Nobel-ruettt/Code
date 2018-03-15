#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll nodes,query,start,ending;
vector<ll>node[310];
ll visited[310];
ll parent[310];
char c;
deque<ll>que;
stack<ll>path;
void clear_parent_visited()
{
    for(ll i=1; i<=nodes; i++)
    {
        visited[i]=-1;
        parent[i]=-1;
    }
    que.clear();
    while(!path.empty())path.pop();
}
void take_edges()
{
    string line;
    char garbage;
    ll router;
    for(ll i=1; i<=nodes; i++)
    {
        node[i].clear();
    }
    for (ll i=0; i<nodes; i++)
    {
        cin >> router;
        getline(cin, line);
        stringstream ss(line);
        ll connectedTo;
        while (ss >> garbage >> connectedTo)
        {
            node[router].push_back(connectedTo);
        }
    }
}
void bfs()
{
    ll source,adj;
    visited[start]=1;
    parent[start]=0;
    que.push_back(start);
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
    if(visited[ending]==-1)
    {
        cout << "connection impossible\n";
    }
    else
    {
        ll n =ending;
        ll top;
        while (n != start)
        {
            path.push(n);
            n = parent[n];
        }
        cout << start;
        while (!path.empty())
        {
            top = path.top();
            path.pop();
            cout <<" "<< top;
        }
        cout <<endl;
    }
}
int main()
{
    while(scanf("%lld",&nodes)==1)
    {
        scanf("%*c",&c);
        take_edges();
        printf("-----\n");
        scanf("%lld",&query);
        for(ll j=0; j<query; j++)
        {
            scanf("%lld%lld",&start,&ending);
            clear_parent_visited();
            bfs();
        }
    }
    return 0;
}
