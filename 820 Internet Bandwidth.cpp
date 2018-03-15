#include <bits/stdc++.h>
#define ll long long
using namespace std;
struct edge
{
    ll a, b, f, c;
};

const ll inf = 1000 * 1000 * 1000;
const ll MAXN = 110;

ll n, m;
vector <edge> e;
ll pt[MAXN]; // very important performance trick
vector <ll> g[MAXN];
ll flow;
queue <ll> q;
ll d[MAXN];
ll lim;
ll s, t;

void add_edge(ll a, ll b, ll c)
{
    edge ed;


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
    ll net=1;
    while(1)
    {
        scanf("%lld",&n);
        if(n==0)
        {
            break;
        }
        e.clear();
        for(ll i=0;i<MAXN;i++)
        {
            g[i].clear();
        }
        flow=0;
        scanf("%lld%lld%lld",&s,&t,&m);
        for (ll i = 1; i <= m; i++)
        {
            ll a, b, c;
            scanf("%lld %lld %lld", &a, &b, &c);
            add_edge(a,b,c);
            add_edge(b,a,c);
        }
        dinic();
        printf("Network %lld\n",net);
        net++;
        printf("The bandwidth is %lld.\n",flow);
    }
    return 0;
}
