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
ll n,m;
dd arrival[24][25];
dd dp[24][(1<<21)+2];
dd solve(ll pos,ll mask)
{
    if(pos>n)
    {
        return 0.00;
    }
    if(dp[pos][mask]!=-1.00)
    {
        return dp[pos][mask];
    }
    dd min_ans=(dd)inf;
    FOR(i,m)
    {
        if(check(mask,i)==0)
        {
            ll mask2=Set(mask,i);
            dd now_ans=arrival[pos][i]+solve(pos+1,mask2);
            if(min_ans-now_ans>=eps)
            {
                min_ans=now_ans;
            }
        }
    }
    return dp[pos][mask]=min_ans;
}
int main()
{

    while(scanf("%lld%lld",&n,&m)==2)
    {
        if(n==0 && m==0)
        {
            break;
        }
        FOR(i,n)
        {
            FOR(j,m)
            {
                scd(arrival[i][j]);
            }
        }
        FOR(i,n+1)
        {
            LOOP(j,(1<<(m+1))+2)
            {
                dp[i][j]=-1.00;
            }
        }
        dd ans=solve(1,0);
        printf("%0.2f\n",ans/(dd)n);
    }
    return 0;
}

