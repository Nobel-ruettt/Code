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
#define dd                   double
#define scl(n)               scanf("%lld",&n)
#define scd(n)               scanf("%lf",&n)
#define pi                   pair<ll,ll>
#define pb                   push_back
#define mp                   make_pair
#define uu                   first
#define vv                   second
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
    ll l,r,ase;
    node(){}
    node(ll a,ll b,ll c)
    {
        l=a;
        r=b;
        ase=c;
    }
};
bool cmp(node a,node b)
{
    if(a.l<b.l)
    {
        return 1;
    }
    return 0;
}
vector<pi>ranges;
vector<node>range_final;
ll asee[40];
ll component_baki_ase[40];
ll n,m;
ll cumsum[10000];

int main()
{
    ll tes;
    scl(tes);
    FOR(cas,tes)
    {
       ranges.clear();
       range_final.clear();
       scl(n);
       scl(m);
       FOR(i,n)
       {
           component[i].clear();
       }
       FOR(i,n)
       {
           ll u,v;
           scl(u);
           scl(v);
           if(u>v)
           {
               swap(u,v);
           }
           ranges.pb(mp(u,v));
       }
       FOR(i,m)
       {
           ll d;
           scl(d);
           FOR(j,d)
           {
               ll id,participent;
               scl(id);
               scl(participent);
               asee[id-1]+=participent;
           }
       }
       LOOP(i,ranges.size())
       {
           range_final.pb(node(ranges[i].uu,ranges[i].vv,asee[i]));
       }
       sortedd(range_final);

    }
    return 0;
}

