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
struct floe
{
    int x,y,now,capacity;
};
floe f[220];
bool thakbe(int index1,int index2,double maxi_dis)
{
    int dis1=fabs(f[index2].x-f[index1].x);
    dis1*=dis1;
    int dis2=fabs(f[index2].y-f[index1].y);
    dis2*=dis2;
    int main_dis=dis1+dis2;
    double dis=(double)main_dis;
    dis=sqrt(dis);
    if((maxi_dis-dis)>=0.000000000001)
    {
        return 1;
    }
    return 0;
}
void solve(int cas)
{
    int n, penguins = 0;
    double d;
    scanf("%d%lf",&n,&d);
    double x, y;
    int  cap, cur;
    int total_nodes=n*2;
    Dinic g(total_nodes+2);
    for (int i=1; i<=n;i++)
    {
        int x,y,cur,cap;
        scanf("%d%d%d%d",&x,&y,&cur,&cap);
        f[i].x=x;
        f[i].y=y;
        f[i].now=cur;
        f[i].capacity=cap;
        penguins += cur;
    }
    for(int i=1;i<=n;i++)
    {
        g.AddEdge(0,i*2-1,f[i].now);
        g.AddEdge(i*2-1,i*2,f[i].capacity);
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            if(thakbe(i,j,d))
            {
                g.AddEdge(i*2,j*2-1,INF);
                g.AddEdge(j*2,i*2-1,INF);
            }
        }
    }
    printf("Case %d:",cas);
    bool ase=0;
    for (int i = 1; i <= n; ++i)
    {
        g.ClearFlow();
        if(g.GetMaxFlow(0,i*2-1)==penguins)
        {
            ase=1;
            printf(" %d",i-1);
        }
    }
    if(ase==0)
    {
        printf(" -1\n");
    }
    else
    {
        printf("\n");
    }
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
