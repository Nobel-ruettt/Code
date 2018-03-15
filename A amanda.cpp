#include <bits/stdc++.h>
using namespace std;
/***template***/
#define ll                   long long
#define LL                   long long
#define dd                   double
#define scl(n)               scanf("%lld",&n)
#define sl(n)                scanf("%lld",&n)
#define scd(n)               scanf("%lf",&n)
#define pi                   pair<ll,ll>
#define pll                  pair<ll,ll>
#define pb                   push_back
#define mp                   make_pair
#define uu                   first
#define vv                   second
#define fr                   first
#define sc                   second
#define FOR(i,n)             for(ll i=1;i<=n;i++)
#define LOOP(i,n)            for(ll i=0;i<n;i++)
#define FOOR(i,a,b)          for(ll i=a;i<=b;i++)
#define LOP(i,a,b)           for(ll i=a;i<b;i++)
#define sorted(s)            sort(s.begin(),s.end())
#define sortedd(s)           sort(s.begin(),s.end(),cmp)
#define reversed(s)          reverse(s.begin(),s.end())
#define contains(a,b)        (find((a).begin(), (a).end(), (b)) != (a).end())
#define MAXN                 200005
#define pii                  3.1415926536
#define mod                  1000000007
#define eps                  0.0000000001
#define inf                  9000000000000000
#define INF                  (1LL<<62)
#define mstt(a,b)            memset((a),(b),sizeof (a))
#define sz(x)                (ll)x.size()
ll Set(ll n,ll pos)
{
    return n=n|(1LL<<pos);
}
ll reset(ll n,ll pos)
{
    return n=n&~(1LL<<pos);
}
bool check(ll n,ll pos)
{
    return (bool)(n&(1LL<<pos));
}
ll mul(ll a,ll b)
{
    ll c;
    c = (a%mod * b%mod)%mod;
    return c;
}
ll add(ll a,ll b)
{
    ll c;
    c = (a%mod + b%mod)%mod;
    return c;
}
ll sub(ll a,ll b)
{
    ll c;
    c = ((a%mod - b%mod)%mod + mod)%mod;
    return c;
}
ll power(ll x,ll y,ll p)
{
    ll res = 1;
    x = x % p;
    while (y > 0)
    {
        if (y & 1)
            res = (res*x) % p;
        y = y>>1;
        x = (x*x) % p;
    }
    return res;
}
ll s2, s1, t2, t1;
ll egcd(ll a, ll b)
{
    ll temp;
    if (a%b == 0)
    {
        return s1;
    }
    temp = s2 - (a/b)*s1;
    s2 = s1;
    s1 = temp;
    temp = t2 - (a/b)*t1;
    t2 = t1;
    t1 = temp;
    return egcd(b, a%b);
}
/***template***/
ll n,m,ans;
vector<pi>graph[MAXN];
ll level[MAXN];
bool visited[MAXN],f;
struct edge
{
    ll u,v,c;
    edge(){}
    edge(ll _u,ll _v,ll _c)
    {
        u=_u;
        v=_v;
        c=_c;
    }
};
vector<edge>edges;
void bfs(ll src)
{
    vector<ll>nodes;
    deque<ll>q;
    visited[src]=1;
    nodes.pb(src);
    q.pb(src);
    while(!q.empty())
    {
        src=q.front();
        q.pop_front();
        LOOP(i,graph[src].size())
        {
            ll adj=graph[src][i].uu;
            if(visited[adj]==0)
            {
                nodes.pb(adj);
                visited[adj]=1;
                q.pb(adj);
            }
        }
    }
    ll src_col=-1;
    LOOP(i,nodes.size())
    {
        if(level[nodes[i]]==1 || level[nodes[i]]==0)
        {
            q.pb(nodes[i]);
        }
    }
    if(!q.empty())
    {
        while(!q.empty())
        {
            src=q.front();
            q.pop_front();
//            cout<<"SRC "<<src<<endl;
            LOOP(i,graph[src].size())
            {
                ll adj=graph[src][i].uu;
                ll ad_t=graph[src][i].vv;
                if(level[adj]==-1)
                {
                    level[adj]=level[src]^1;
//                    cout<<"-1 adj "<<adj<<" col "<<level[adj]<<endl;
                    q.pb(adj);
                }
                else if(level[adj]!=-1)
                {
//                    cout<<"-1 chara adj "<<adj<<" col "<<level[adj]<<endl;
                    if(ad_t==0)
                    {
                        if(level[src]==1 || level[adj]==1)
                        {
                            f=1;
                            return ;
                        }
                    }
                    else if(ad_t==2)
                    {
                         if(level[src]==0 || level[adj]==0)
                         {
                             f=1;
                             return ;
                         }
                    }
                    else if(ad_t==1)
                    {
                        if(level[src]==0 && level[adj]==0 || level[src]==1 && level[adj]==1)
                        {
                            f=1;
                            return ;
                        }
                    }
                }
            }
        }
        LOOP(i,nodes.size())
        {
            if(level[nodes[i]]==1)
            {
                ans++;
            }
        }
    }
    else
    {
        q.pb(nodes[0]);
        level[nodes[0]]=1;
        ll count1[2];
        count1[0]=0;
        count1[1]=1;
        while(!q.empty())
        {
            src=q.front();
            q.pop_front();
            LOOP(i,graph[src].size())
            {
                ll adj=graph[src][i].uu;
                if(level[adj]==-1)
                {
                    level[adj]=level[src]^1;
                    count1[level[adj]]++;
                    q.pb(adj);
                }
                else if(level[adj]!=-1)
                {
                    if(level[src]==level[adj])
                    {
                        f=1;
                        return ;
                    }
                }
            }
        }
        ans+=min(count1[0],count1[1]);
    }
}
void initial_check()
{
    LOOP(i,edges.size())
    {
        if(edges[i].c==2)
        {
            ll u=edges[i].u;
            ll v=edges[i].v;
            if(level[u]==-1)
            {
                level[u]=1;
            }
            else if(level[u]==0)
            {
                f=1;
                break;
            }
            if(level[v]==-1)
            {
                level[v]=1;
            }
            else if(level[v]==0)
            {
                f=1;
                break;
            }
        }
        else if(edges[i].c==0)
        {
            ll u=edges[i].u;
            ll v=edges[i].v;
            if(level[u]==-1)
            {
                level[u]=0;
            }
            else if(level[u]==1)
            {
                f=1;
                break;
            }
            if(level[v]==-1)
            {
                level[v]=0;
            }
            else if(level[v]==1)
            {
                f=1;
                break;
            }
        }
    }
}
int main()
{
    scl(n);
    scl(m);
    FOR(i,m)
    {
        ll u,v,c;
        scl(u);
        scl(v);
        scl(c);
        graph[u].pb(mp(v,c));
        graph[v].pb(mp(u,c));
        edges.pb(edge(u,v,c));
    }
//    FOR(i,n)
//    {
//        cout<<i<<" : ";
//        LOOP(j,graph[i].size())
//        {
//            cout<<graph[i][j].uu<<","<<graph[i][j].vv<<" ";
//        }
//        cout<<endl;
//    }
    ans=0;
    f=0;
    mstt(level,-1);
    initial_check();
    if(f)
    {
        cout<<"impossible"<<endl;
        return 0;
    }
//    FOR(i,n)
//    {
//        cout<<visited[i]<<" ";
//    }
//    cout<<endl;
    FOR(i,n)
    {
        if(visited[i]==0)
        {
            bfs(i);
        }
    }
    if(f==1)
    {
        cout<<"impossible"<<endl;
        return 0;
    }
    cout<<ans<<endl;
    return 0;
}
