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
ll tes;
multiset<ll>gents;
multiset<ll>woman;
multiset<ll>::iterator it;
multiset<ll>::iterator it2;
multiset<ll>::iterator it3;
int main()
{
    ll n,m;
    tes=1;
    while(scanf("%lld%lld",&n,&m)==2)
    {
        if(n==0 && m==0)
        {
            break;
        }
        gents.clear();
        woman.clear();
        FOR(i,n)
        {
            ll val;
            scl(val);
            gents.insert(val);
        }
        FOR(i,m)
        {
            ll val;
            scl(val);
            woman.insert(val);
        }
        ll cnt=0;
        while(1)
        {
            if(gents.size()==0)
            {
                break;
            }
            if(woman.size()==0)
            {
                break;
            }
            cnt++;
            it=gents.end();
            it--;
            ll now_val=*it;
            it2=woman.begin();
            if(*it2>=now_val)
            {
                gents.erase(it);
                woman.erase(it2);
                continue;
            }
            it2=woman.end();
            it2--;
            if(*it2<=now_val)
            {
                gents.erase(it);
                woman.erase(it2);
                continue;
            }
            it2=woman.lower_bound(now_val);
            if(*it2==now_val)
            {
                gents.erase(it);
                woman.erase(it2);
                continue;
            }
            ll up=*it2;
            it3=woman.lower_bound(now_val);
            it3--;
            ll low=*it3;
            if((up-now_val)<=(now_val-low))
            {
                gents.erase(it);
                woman.erase(it2);
                continue;
            }
            else
            {
                gents.erase(it);
                woman.erase(it3);
                continue;
            }
        }
        ll ans=n-cnt;
        printf("Case %lld: %lld",tes,ans);
        if(ans>0)
        {
            it=gents.begin();
            printf(" %lld",*it);
        }
        printf("\n");
        tes++;
    }
    return 0;
}
