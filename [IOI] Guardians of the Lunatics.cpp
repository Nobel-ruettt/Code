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
ll n,g;
ll c[9000];
ll cumsum[9000];
ll dp[9000][810];
ll p[9000][810];
ll cost(ll l,ll r)
{
    if(l>r)
    {
        return inf;
    }
    ll costt=(cumsum[r]-cumsum[l-1])*(r-l+1);
    return costt;
}
void fill_dp(ll rem,ll l,ll r,ll p1,ll p2)
{
    if(l>r)
    {
        return ;
    }
    ll mid=(l+r)/2;
    dp[mid][rem]=dp[mid][rem-1];
    p[mid][rem]=-1;
    for(ll i=p1;i<=p2;i++)
    {
        ll now_cost=dp[i][rem-1]+cost(i+1,mid);
        if(now_cost<dp[mid][rem])
        {
            dp[mid][rem]=now_cost;
            p[mid][rem]=i;
        }
    }
     fill_dp(rem, l, mid-1, p1, p[mid][rem]);
     fill_dp(rem, mid+1, r, p[mid][rem], p2);
}
int main()
{
    scl(n);
    scl(g);
    FOR(i,n)
    {
        scl(c[i]);
        cumsum[i]+=cumsum[i-1]+c[i];
    }
    for(ll i=1;i<=n;i++)
    {
        dp[i][1]=cost(1,i);
    }
    for(ll i=2;i<=g;i++)
    {
        fill_dp(i,1,n,1,n);
    }
    cout<<dp[n][g]<<endl;
    return 0;
}

