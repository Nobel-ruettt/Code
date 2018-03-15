#include <bits/stdc++.h>
using namespace std;
const int INF = 2000000000;
const double EPS = 1e-9;
struct Edge
{
    int from, to, cap, flow, index;
    Edge(int from, int to, int cap, int flow, int index) :
        from(from), to(to), cap(cap), flow(flow), index(index) {}
};

struct Dinic
{
    int N;
    vector<vector<Edge> > G;
    vector<Edge *> dad;
    vector<int> Q;

    Dinic(int N) : N(N), G(N), dad(N), Q(N) {}

    void AddEdge(int from, int to, int cap)
    {
        G[from].push_back(Edge(from, to, cap, 0, G[to].size()));
        if (from == to) G[from].back().index++;
        G[to].push_back(Edge(to, from, 0, 0, G[from].size() - 1));
    }

    long long BlockingFlow(int s, int t)
    {
        fill(dad.begin(), dad.end(), (Edge *) NULL);
        dad[s] = &G[0][0] - 1;

        int head = 0, tail = 0;
        Q[tail++] = s;
        while (head < tail)
        {
            int x = Q[head++];
            for (int i = 0; i < G[x].size(); i++)
            {
                Edge &e = G[x][i];
                if (!dad[e.to] && e.cap - e.flow > 0)
                {
                    dad[e.to] = &G[x][i];
                    Q[tail++] = e.to;
                }
            }
        }
        if (!dad[t]) return 0;

        long long totflow = 0;
        for (int i = 0; i < G[t].size(); i++)
        {
            Edge *start = &G[G[t][i].to][G[t][i].index];
            int amt = INF;
            for (Edge *e = start; amt && e != dad[s]; e = dad[e->from])
            {
                if (!e)
                {
                    amt = 0;
                    break;
                }
                amt = min(amt, e->cap - e->flow);
            }
            if (amt == 0) continue;
            for (Edge *e = start; amt && e != dad[s]; e = dad[e->from])
            {
                e->flow += amt;
                G[e->to][e->index].flow -= amt;
            }
            totflow += amt;
        }
        return totflow;
    }

    long long GetMaxFlow(int s, int t)
    {
        long long totflow = 0;
        while (long long flow = BlockingFlow(s, t))
            totflow += flow;
        return totflow;
    }

    void ClearFlow()
    {
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < G[i].size(); ++j)
                G[i][j].flow = 0;

    }
};
int m,w;
int cost_m[100];
void solve(int cas)
{
    scanf("%d%d",&m,&w);
    int total_nodes=m*2;
    Dinic g(total_nodes+2);
    g.AddEdge(1,2,INF);
    g.AddEdge(m*2-1,m*2,INF);
    for(int i=2;i<=m-1;i++)
    {
        scanf("%d",&cost_m[i]);
        g.AddEdge(i*2-1,i*2,cost_m[i]);
    }
    for(int i=1;i<=w;i++)
    {
        int u,v,cost;
        scanf("%d%d%d",&u,&v,&cost);
        g.AddEdge(u*2,v*2-1,cost);
        g.AddEdge(v*2,u*2-1,cost);
    }
    printf("Case %d: %d\n",cas,g.GetMaxFlow(1,m*2));
}
int main()
{
    int tes;
    scanf("%d",&tes);
    for(int cas=1; cas<=tes; cas++)
    {
        solve(cas);
    }
    return 0;
}

