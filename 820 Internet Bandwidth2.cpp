#include <bits/stdc++.h>

using namespace std;

const int MAXN = 110;
const int INF = (int) 1e9;

struct edge
{
    int from, to, f, cap;
};

int n, m;
vector <edge> e;
vector <int> g[MAXN];
bool used[MAXN];
int s, t;
int ans;

void addEdge(int from, int to, int cap)
{
    edge ed;

    ed.from = from;
    ed.to = to;
    ed.f = 0;
    ed.cap = cap;
    e.push_back(ed);
    g[from].push_back((int) e.size() - 1);

    ed.from = to;
    ed.to = from;
    ed.f = cap;
    ed.cap = cap;
    e.push_back(ed);
    g[to].push_back((int) e.size() - 1);
}

int pushFlow(int v, int flow = INF)
{
    used[v] = true;
    if (v == t)
        return flow;

    for (int i = 0; i < (int) g[v].size(); i++)
    {
        int ind = g[v][i];
        int to = e[ind].to;
        int f = e[ind].f;
        int cap = e[ind].cap;

        if (used[to] || cap - f == 0)
            continue;

        int pushed = pushFlow(to, min(flow, cap - f));
        if (pushed > 0)
        {
            e[ind].f += pushed;
            e[ind ^ 1].f -= pushed;
            return pushed;
        }
    }

    return 0;
}

int main()
{
    int cas,net=1;
    scanf("%d",&cas);
    while(net<=cas)
    {
        scanf("%d", &n);
        if(n==0)
        {
            break;
        }
        scanf("%d%d%d",&s,&t,&m);
        e.clear();
        for(int i=0;i<MAXN;i++)
        {
            g[i].clear();
        }
        for (int i = 1; i <= m; i++)
        {
            int from, to, cap;
            scanf("%d %d %d", &from, &to, &cap);
            addEdge(from, to, cap);
        }
        ans=0;
        while (true)
        {
            memset(used, 0, sizeof(used));
            int add = pushFlow(s);
            if (add == 0)
                break;
            ans += add;
        }
        printf("Case %d: %d\n",net,ans);
        net++;
    }
    return 0;
}
