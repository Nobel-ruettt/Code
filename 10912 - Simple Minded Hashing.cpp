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
#define reversed(s)          reverse(s.begin(),s.end())
#define contains(a,b)        (find((a).begin(), (a).end(), (b)) != (a).end())
#define MAXN                 1000005
#define pii                  3.1415926536
#define mod                  1000000007
#define eps                  0.0000000001
#define inf                  9000000000000000
#define mstt(a,b)            memset((a),(b),sizeof (a))
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
ll dp[27][27][352];
ll tes,len,sum;
ll solve(ll pos,ll prev_taken,ll prev_sum)
{
    if(pos>len)
    {
        if(prev_sum==sum)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    if(dp[pos][prev_taken][prev_sum]!=-1)
    {
        return dp[pos][prev_taken][prev_sum];
    }
    ll ans=0;
    for(ll i=prev_taken+1;i<=26;i++)
    {
        if((prev_sum+i)<=sum)
        {
            ans+=solve(pos+1,i,prev_sum+i);
        }
    }
    return dp[pos][prev_taken][prev_sum]=ans;
}
int main()
{
    while(scanf("%lld%lld",&len,&sum)==2)
    {
        if(len==0 && sum==0)
        {
            break;
        }
        memset(dp,-1,sizeof  dp);
        if(len>26 || sum>351)
        {
             printf("Case %lld: %lld\n",++tes,0);
        }
        else
        {
            printf("Case %lld: %lld\n",++tes,solve(1,0,0));
        }
    }
    return 0;
}

