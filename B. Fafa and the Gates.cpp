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
struct node
{
    ll nod,d;
    node(ll a,ll b)
    {
        nod=a;
        d=b;
    }
    bool operator<(const node &p)const
    {
        return p.d<d;
    }
};
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
ll n;
string s;
int main()
{
    scl(n);
    cin>>s;
    pi now_p;
    now_p.uu=0;
    now_p.vv=0;
    ll prev_wall=0;
    ll cnt=0;
    LOOP(i,s.size())
    {
        if(s[i]=='U')
        {
            pi now_p2;
            now_p2.uu=now_p.uu;
            now_p2.vv=now_p.vv+1;
            if(now_p2.vv<now_p2.uu)
            {
                if(prev_wall==0)
                {
                    prev_wall=1;
                    now_p=now_p2;
                }
                else if(prev_wall==2)
                {
                    cnt++;
                    prev_wall=1;
                    now_p=now_p2;
                }
                else if(prev_wall==1)
                {
                    now_p=now_p2;
                }
            }
            else if(now_p2.vv>now_p2.uu)
            {
                if(prev_wall==0)
                {
                    prev_wall=2;
                    now_p=now_p2;
                }
                else if(prev_wall==1)
                {
                    cnt++;
                    prev_wall=2;
                    now_p=now_p2;
                }
                else if(prev_wall==2)
                {
                    now_p=now_p2;
                }
            }
            else if(now_p2.uu==now_p2.vv)
            {
                now_p=now_p2;
            }
        }
        if(s[i]=='R')
        {
            pi now_p2;
            now_p2.uu=now_p.uu+1;
            now_p2.vv=now_p.vv;
            if(now_p2.vv<now_p2.uu)
            {
                if(prev_wall==0)
                {
                    prev_wall=1;
                    now_p=now_p2;
                }
                else if(prev_wall==2)
                {
                    cnt++;
                    prev_wall=1;
                    now_p=now_p2;
                }
                else if(prev_wall==1)
                {
                    now_p=now_p2;
                }
            }
            else if(now_p2.vv>now_p2.uu)
            {
                if(prev_wall==0)
                {
                    prev_wall=2;
                    now_p=now_p2;
                }
                else if(prev_wall==1)
                {
                    cnt++;
                    prev_wall=2;
                    now_p=now_p2;
                }
                else if(prev_wall==2)
                {
                    now_p=now_p2;
                }
            }
            else if(now_p2.uu==now_p2.vv)
            {
                now_p=now_p2;
            }
        }
    }
    cout<<cnt<<endl;
    return 0;
}
