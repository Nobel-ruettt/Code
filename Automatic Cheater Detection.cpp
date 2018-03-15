#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <string>
#include <map>
#include <stack>
#include <vector>
#include <set>
#include <queue>
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
struct point
{
    ll x,y;
};
ll sqr(ll a)
{
    return a*a;
}
dd distancee(point p,point q)
{
    ll dis=sqr(q.x-p.x)+sqr(q.y-p.y);
    dd dis2=sqrt(dis);
    return dis2;
}
dd projection(point p,point q,point r)
{
    ll upor=abs((q.y-p.y)*r.x-(q.x-p.x)*r.y+q.x*p.y-q.y*p.x);
    dd upor2=(dd)upor;
    dd nich=distancee(p,q);
    return upor2/nich;
}
/***template***/
ll q;
ll leaked[15];
ll unleacked[15];
int main()
{
    ll tes;
    scl(tes);
    FOR(cas,tes)
    {
        scl(q);
        mstt(leaked,0);
        mstt(unleacked,0);
        FOR(i,q)
        {
            ll d,r;
            char c;
            scl(d);
            scl(r);
            scanf(" %c",&c);
            if(r==0 && c=='i')
            {
                unleacked[d]++;
            }
            else if(r==1 && c=='c')
            {
                leaked[d]++;
            }
        }
        for(ll i=1;i<=10;i++)
        {
            unleacked[i]+=unleacked[i-1];
        }
        ll ans=0;
        for(ll i=1;i<=10;i++)
        {
            ans+=(leaked[i]*unleacked[i-1]);
        }
        printf("%lld\n",ans);
    }

    return 0;
}
