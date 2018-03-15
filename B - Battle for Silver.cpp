#include <bits/stdc++.h>
using namespace std;
/***template**/
#define ll long long
#define dd double
#define scl(n)               scanf("%lld",&n)
#define sci(n)               scanf("%d",&n)
#define scd(n)               scanf("%lf",&n)
#define pi                   pair<ll,ll>
#define pb                   push_back
#define mp                   make_pair
#define uu                   first
#define vv                   second
#define FOR(i,n)             for(ll i=1;i<=n;i++)
#define LOOP(i,n)            for(ll i=0;i<n;i++)
#define FOOR(i,a,b)          for(ll i=a;i<=b;i++)
#define sorted(s)            sort(s.begin(),s.end())
#define reversed(s)          reverse(s.begin(),s.end())
#define contains(a,b)       (find((a).begin(), (a).end(), (b)) != (a).end())
#define maxn 500
#define pii 3.1415926536
/**template**/
ll n,m,best;
vector<ll>graph[maxn];
vector<pi>degree;
ll silver[maxn];
bool dis[maxn];
void cle()
{
    FOOR(i,0,n)
    {
        graph[i].clear();
        dis[i]=false;
    }
    best=0;
    degree.clear();
}
void in_silver()
{
    LOOP(i,n)
    {
        scl(silver[i]);
        best=max(best,silver[i]);
    }
}
void in_edges()
{
    ll u,v;
    FOR(i,m)
    {
        scl(u);
        scl(v);
        u--;v--;
        graph[u].pb(v);
        graph[v].pb(u);
    }
}
void making_degeneracy_ordering()
{
    LOOP(i,n)
    {
        degree.pb(mp(graph[i].size(),i));
    }
    sorted(degree);
}
ll chain(vector<ll>cur_nodes,vector<ll>sel,ll pos,ll sum)
{
    if (pos >= cur_nodes.size())
    {
       return sum;
    }
    ll ret=max(sum,chain(cur_nodes, sel, pos+1,sum));
    bool possible = true;
    LOOP(i,sel.size())
    {
        if (!contains(graph[cur_nodes[pos]], sel[i]))
        {
            possible = false;
        }
    }
    sel.push_back(cur_nodes[pos]);
    if (possible)
    {
        ret=max(ret,chain(cur_nodes, sel, pos + 1,sum+silver[cur_nodes[pos]]));
    }
    return ret;
}
int main()
{
    while(scanf("%lld%lld",&n,&m)==2)
    {
        cle();
        in_silver();
        in_edges();
        making_degeneracy_ordering();
        LOOP(i,n)
        {
            ll cur_node = degree[i].vv;
            vector<ll> cur_nodes;
            LOOP(j,graph[cur_node].size())
            {
                int adj = graph[cur_node][j];
                if (!dis[adj])
                {
                    cur_nodes.pb(adj);
                }
            }
            vector<ll> sel;
            vector<ll>clique;
            best=max(best,chain(cur_nodes, sel, 0, silver[cur_node]));
            dis[cur_node] = true;
        }
        cout<<best<<endl;
    }
    return 0;
}

