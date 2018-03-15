#include<bits/stdc++.h>
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
#define mod                  100000007
#define eps                  0.0000000001
#define inf                  9000000000000000
#define INF                  (1LL<<62)
#define mstt(a,b)            memset((a),(b),sizeof (a))
#define sz(x)                (ll)x.size()
#define mx                    10005
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
ll n,m,t;
ll status[mx];
vector<ll>prime;
vector<pi>n_fac;
void sieve()
{
    for(ll i=2;i<mx;i++)
    {
        if(status[i]==0)
        {
            for(ll j=i*2;j<mx;j+=i)
            {
                status[j]=1;
            }
        }
    }
    for(ll i=2;i<mx;i++)
    {
        if(status[i]==0)
        {
            prime.pb(i);
        }
    }
}
void cle()
{
    n_fac.clear();
}
void fac_n()
{
    ll num=n;
    for(ll i=0;prime[i]*prime[i]<=n && i<prime.size();i++)
    {
        ll n_p=prime[i];
        if((num%n_p)==0)
        {
            ll cnt=0;
            while((num%n_p)==0)
            {
                num/=n_p;
                cnt++;
            }
            n_fac.pb(pi(n_p,cnt));
        }
    }
    if(num>1)
    {
        n_fac.pb(pi(num,1));
    }
}
int main()
{
    ll cas=1;
    sieve();
    while(scanf("%lld %lld %lld",&n,&m,&t)==3)
    {
        if(n==0 & m==0 && t==0)
        {
            break;
        }
        cle();
        fac_n();
        LOOP(i,n_fac.size())
        {
            n_fac[i].vv*=m;
        }
        ll ans1=1;
        ll ans2=1;
        LOOP(i,n_fac.size())
        {
            ll up=(ll)(n_fac[i].vv/t);
            ll low=(ll)(n_fac[i].vv/(t+1));
            ans1=(ans1*(up+1))%mod;
            ans2=(ans2*(low+1))%mod;
        }
        ll ans=((ans1-ans2)+mod)%mod;
        printf("Case %lld: %lld\n",cas,ans);
        cas++;
    }
    return 0;
}
