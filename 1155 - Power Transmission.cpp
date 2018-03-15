#include <bits/stdc++.h>
#define ll long long
using namespace std;
const long long MAXN = 220;
const long long inf = (int) 1e9;

struct edge
{
    ll a, b, f, c;
};
vector <edge> e;
ll pt[MAXN];
vector <ll> g[MAXN];
ll flow;
queue <ll> q;
ll d[MAXN];
ll lim,n,m;
ll s,t;
void cle()
{
    e.clear();
    for(ll i=0; i<MAXN; i++)
    {
        g[i].clear();
    }
}
void add_edge(ll a, ll b, ll c)
{
    edge ed;

    //keep edges in vector: e[ind] - direct edge, e[ind ^ 1] - back edge

    ed.a = a;
    ed.b = b;
    ed.f = 0;
    ed.c = c;
    g[a].push_back(e.size());
    e.push_back(ed);

    ed.a = b;
    ed.b = a;
    ed.f = c;
    ed.c = c;
    g[b].push_back(e.size());
    e.push_back(ed);
}
bool bfs()
{
    for (ll i = s; i <= t; i++)
        d[i] = inf;
    d[s] = 0;
    q.push(s);
    while (!q.empty() && d[t] == inf)
    {
        ll cur = q.front();
        q.pop();
        for (size_t i = 0; i < g[cur].size(); i++)
        {
            ll id = g[cur][i];
            ll to = e[id].b;

            //prllf("cur = %d id = %d a = %d b = %d f = %d c = %d\n", cur, id, e[id].a, e[id].b, e[id].f, e[id].c);

            if (d[to] == inf && e[id].c - e[id].f >= lim)
            {
                d[to] = d[cur] + 1;
                q.push(to);
            }
        }
    }
    while (!q.empty())
        q.pop();
    return d[t] != inf;
}

bool dfs(ll v, ll flow)
{
    if (flow == 0)
        return false;
    if (v == t)
    {
        //cout << v << endl;
        return true;
    }
    for (; pt[v] < g[v].size(); pt[v]++)
    {
        ll id = g[v][pt[v]];
        ll to = e[id].b;

        //prllf("v = %d id = %d a = %d b = %d f = %d c = %d\n", v, id, e[id].a, e[id].b, e[id].f, e[id].c);

        if (d[to] == d[v] + 1 && e[id].c - e[id].f >= flow)
        {
            ll pushed = dfs(to, flow);
            if (pushed)
            {
                e[id].f += flow;
                e[id ^ 1].f -= flow;
                return true;
            }
        }
    }
    return false;
}

void dinic()
{
    for (lim = (1 << 30); lim >= 1;)
    {
        if (!bfs())
        {
            lim >>= 1;
            continue;
        }

        for (ll i = s; i <= t; i++)
            pt[i] = 0;

        ll pushed;

        while (pushed = dfs(s, lim))
        {
            flow = flow + lim;
        }

        //cout << flow << endl;
    }
}
int main()
{
    ll tes,node_capacity;
    scanf("%lld",&tes);
    for(ll cas=1; cas<=tes; cas++)
    {
        cle();
        scanf("%lld",&n);
        s=0;
        t=n*2+1;
        for(ll i=1; i<=n; i++)
        {
            scanf("%lld",&node_capacity);
            add_edge(i*2-1,i*2,node_capacity);
        }
        scanf("%lld",&m);
        for (ll i = 1; i <= m; i++)
        {
            ll a,b,c;
            scanf("%lld%lld%lld", &a, &b, &c);
            add_edge(2*a,2*b-1,c);
        }
        ll start,finish;
        scanf("%lld%lld",&start,&finish);
        for(ll i=1;i<=start;i++)
        {
            ll nodes;
            scanf("%lld",&nodes);
            add_edge(0,nodes*2-1,inf);
        }
        for(ll i=1;i<=finish;i++)
        {
            ll nodes;
            scanf("%lld",&nodes);
            add_edge(nodes*2,t,inf);
        }
        flow=0;
        dinic();
        printf("Case %lld: %lld\n",cas,flow);
    }
    return 0;
}

