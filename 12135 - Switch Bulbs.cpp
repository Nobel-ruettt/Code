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
#define MAXN                 100005
#define pii                  3.1415926536
#define mod                  1000000007
#define eps                  0.0000000001
#define inf                  9000000000000000
#define INF                  (1LL<<62)
#define mstt(a,b)            memset((a),(b),sizeof (a))
#define sz(x)                (ll)x.size()
#define mx                    92681+10
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
ll power(ll x,ll y)
{
    ll res = 1;
    x = x;
    while (y > 0)
    {
        if (y & 1)
            res = (res*x);
        y = y>>1;
        x = (x*x);
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
long long exgcd(long long x, long long y, long long &a, long long &b)
{
    // ax + by = gcd(x,y)
    int flag = 0;
    long long t, la = 1, lb = 0, ra = 0, rb = 1;
    while(x%y)
    {
        if(flag == 0)
            la -= x/y*ra, lb -= x/y*rb;
        else
            ra -= x/y*la, rb -= x/y*lb;
        t = x, x = y, y = t%y;
        flag = 1 - flag;
    }
    if(flag == 0)
        a = ra, b = rb;
    else
        a = la, b = lb;
    return y;
}
/***template***/
ll n,m;
ll dis[1<<16];
ll toggle[50];
struct node
{
    ll nod, dist;
    node() {}
    node(ll a,ll b)
    {
        nod=a;
        dist=b;
    }
    bool operator<(const node &p)const
    {
        return p.dist<dist;
    }
};
priority_queue<node>q;
char str[20];
void cle()
{
    for(ll i=0; i<=((1<<n)-1); i++)
    {
        dis[i]=inf;
    }
    for(ll i=1;i<=m;i++)
    {
        toggle[i]=0;
    }
}
int main()
{
    ll tes;
    scl(tes);
    FOR(cas,tes)
    {
        scl(n);
        scl(m);
        cle();
        for(ll i=1; i<=m; i++)
        {
            ll k;
            scl(k);
            FOR(j,k)
            {
                ll pos;
                scl(pos);
                toggle[i]=Set(toggle[i],pos);
            }
        }
        dis[0]=0;
        q.push(node(0,0));
        while(!q.empty())
        {
            node topp=q.top();
            q.pop();
            ll now_nod=topp.nod;
            ll now_dis=topp.dist;
            FOR(i,m)
            {
                ll adj=now_nod^toggle[i];
                if(dis[adj]>(dis[now_nod]+1))
                {
                    dis[adj]=dis[now_nod]+1;
                    q.push(node(adj,dis[adj]));
                }
            }
        }
        ll q;
        scl(q);
        printf("Case %lld:\n",cas);
        FOR(i,q)
        {
            scanf(" %s",str);
            ll val=0;
            ll pwr=1;
            for(ll j=strlen(str)-1; j>=0; j--)
            {
                val=val+((str[j]-'0')*pwr);
                pwr*=2;
            }
            if(dis[val]==inf)
            {
                printf("-1\n");
            }
            else
            {
                printf("%lld\n",dis[val]);
            }
        }
        printf("\n");
    }
    return 0;
}

