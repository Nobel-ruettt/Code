#include <bits/stdc++.h>
using namespace std;
const int MAXN = 210;
const int INF = (int) 1e9;
struct edge
{
    int from, to, f, cap;
};
int n,m,a,b,c,d;
vector <edge> e;
vector <int> g[MAXN];
bool used[MAXN];
int s, t;
int ans;
int start_to_u[MAXN],u_to_sink[MAXN],lower[1000000],upper[1000000];
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
void cle()
{
    e.clear();
    for(int i=0;i<MAXN;i++)
    {
        g[i].clear();
        used[i]=0;
        start_to_u[i]=0;
        u_to_sink[i]=0;
    }
    ans=0;
}
int main()
{
    int tes,sum;
    scanf("%d",&tes);
    for(int cas=1; cas<=tes; cas++)
    {
        cle();
        scanf("%d%d",&n,&m);
        sum=0;
        for(int i=1;i<=m;i++)
        {
            scanf("%d%d%d%d",&a,&b,&c,&d);
            sum+=c;
            start_to_u[b]+=c;
            u_to_sink[a]+=c;
            lower[i]=c;
            upper[i]=d;
            addEdge(a,b,d-c);
        }
//        cout<<sum<<endl;
//        for(int i=1;i<=n;i++)
//        {
//            cout<<start_to_u[i]<<" "<<u_to_sink[i]<<endl;
//        }
        for(int i=1;i<=n;i++)
        {
            addEdge(0,i,start_to_u[i]);
            addEdge(i,n+1,u_to_sink[i]);
        }
        addEdge(n,1,INF);
        s=0;
        t=n+1;
        while (true)
        {
            memset(used, 0, sizeof(used));
            int add = pushFlow(s);
            if (add == 0)
                break;
            ans += add;
        }
        printf("Case %d: ",cas);
        if(ans==sum)
        {
            printf("yes\n");
            for(int i=0,j=1;i<=m*2-2&&j<=m;i+=2,j++)
            {
                printf("%d\n",e[i].f+lower[j]);
            }
        }
        else
        {
            printf("no\n");
        }
    }
    return 0;
}
