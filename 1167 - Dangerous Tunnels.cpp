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
//bool can(int high_edge)
//{
//    Dinic g(resthouses*2+4);
//    for(int i=1;i<=resthouses;i++)
//    {
//        g.AddEdge(i*2-1,i*2,1);
//    }
//    for(int i=0;i<tunnels.size();i++)
//    {
//        if(tunnels[i].d<=high_edge)
//        {
//            if(tunnels[i].u!=0 || tunnels[i].v!=resthouses+1)
//            {
//                int from=tunnels[i].u*2;
//                int to=tunnels[i].v*2-1;
//                g.AddEdge(from,to,1);
//            }
//            else if(tunnels[i].u==0 && tunnels[i].v!=resthouses+1)
//            {
//                int from=0;
//                int to=tunnels[i].v*2-1;
//                g.AddEdge(from,to,1);
//            }
//            else if(tunnels[i].u!=0 && tunnels[i].v==resthouses+1)
//            {
//                int from=tunnels[i].u*2;
//                int to=resthouses*2+1;
//                g.AddEdge(from,to,1);
//            }
//            else if(tunnels[i].u==0 && tunnels[i].v==resthouses+1)
//            {
//                int from=0;
//                int to=resthouses*2+1;
//                g.AddEdge(from,to,1);
//            }
//        }
//    }
//    g.ClearFlow();
//    if(g.GetMaxFlow(0,resthouses+1)>=k)
//    {
//        return 1;
//    }
//    return 0;
//}
int n,m,aa,bb,cc,maximum,k;
struct ed
{
    int u,v,d;
    ed(int a,int b,int c)
    {
        u=a;
        v=b;
        d=c;
    }
};
vector<ed>tunnels;
vector<int>edge_value;
void cle()
{
    tunnels.clear();
    edge_value.clear();
    maximum=LLONG_MIN;
}
void solve(int cas)
{
    cle();
    scanf("%d",&n);
    scanf("%d",&m);
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d%d",&aa,&bb,&cc);
//        if(a>b)
//        {
//            swap(a,b);
//        }
//        ed edd;
//        edd.u=a;
//        edd.v=b;
//        edd.d=c;
//        tunnels.push_back(edd);
//        maximum=max(maximum,c);
//        edge_value.push_back(c);
    }
    scanf("%d",&k);
//    sort(edge_value.begin(),edge_value.end());
//    int low=0;
//    int high=maximum;
//    int ans=-1;
//    int mid;
//    while(low<=high)
//    {
//        mid=(low+high)/2;
//        if(can(mid))
//        {
//            ans=mid;
//            high=mid-1;
//        }
//        else
//        {
//            low=mid+1;
//        }
//    }
//    for(int i=0;i<edge_value.size();i++)
//    {
//        if(edge_value[i]==ans)
//        {
//            break;
//        }
//        else if(edge_value[i]>ans)
//        {
//            ans=edge_value[i];
//            break;
//        }
//    }
//    if(ans==-1)
//    {
//        printf("Case %d: no solution\n",cas);
//    }
//    else
//    {
//        printf("Case %d: %d\n",cas,ans);
//    }
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
