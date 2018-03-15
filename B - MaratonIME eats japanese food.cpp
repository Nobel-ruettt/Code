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
struct node
{
    ll x,y,r;
};
ll vis[100000];
vector<node>as;
ll sqr(ll a)
{
    return a*a;
}
ll distance(node a,node b)
{
    return sqr(a.x-b.x)+sqr(a.y-b.y);
}
int main()
{
    ll q;
//    node a;
//    a.x=20;
//    a.y=25;
//    a.r=15;
//    node b;
//    b.x=25;
//    b.y=25;
//    b.r=5;
//    cout<<distance()
    scl(q);
    FOR(i,q)
    {
        char c;
        scanf(" %c",&c);
        if(c=='A')
        {
            node ff;
            scl(ff.x);
            scl(ff.y);
            scl(ff.r);
            bool f=0;
            LOOP(i,as.size())
            {
                if(vis[i]==0)
                {
                    if(distance(ff,as[i])<sqr(as[i].r+ff.r))
                    {
                        f=1;
                        break;
                    }
                }
            }
            if(f==0)
            {
                printf("Ok\n");
                as.pb(ff);
            }
            else
            {
                printf("No\n");
            }
        }
        else if(c=='R')
        {
            node ff;
            scl(ff.x);
            scl(ff.y);
            scl(ff.r);
            bool f=0;
            LOOP(i,as.size())
            {
                if(vis[i]==0)
                {
                    if(as[i].x==ff.x && as[i].y==ff.y && as[i].r==ff.r)
                    {
                        vis[i]=1;
                        f=1;
                        break;
                    }
                }
            }
            if(f==0)
            {
                printf("No\n");
            }
            else
            {
                printf("Ok\n");
            }
        }
    }
    return 0;
}
