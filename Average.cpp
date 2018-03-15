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
#define mod                   1000000007
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
ll n,high,cas;
vector<pi>sum_av;
ll dp[12004][64];
ll vis[12004][64];
ll solve(ll rem_sum,ll rem_pos)
{
    if(rem_pos==0 && rem_sum>0)
    {
        return 0;
    }
    if(rem_pos==0 && rem_sum==0)
    {
        return 1;
    }
    if(vis[rem_sum][rem_pos]==cas)
    {
        return dp[rem_sum][rem_pos];
    }
    ll ans=0;
    for(ll i=0;i<=high;i++)
    {
        if(rem_sum-i>=0)
        {
            ans=(ans+solve(rem_sum-i,rem_pos-1))%mod;
        }
    }
    return dp[rem_sum][rem_pos]=ans;
}
int main()
{
    cas=1;
    while(1)
    {
        scl(n);
        scl(high);
        if(n==0 && high==0)
        {
            break;
        }
        sum_av.clear();
        for(ll i=0;i<=high;i++)
        {
            sum_av.pb(pi(i*n,i));
        }
        ll ans=0;
        LOOP(i,sum_av.size())
        {
            ll now_sum=sum_av[i].uu;
            ll now_av=sum_av[i].vv;
            ans=(ans+n*solve(now_sum-now_av,n-1))%mod;
        }
        printf("%lld\n",ans%mod);
        cas++;
    }
    return 0;
}
