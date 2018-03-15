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
#define inf                  1e17
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
ll cas;
ll n,s,w;
vector<ll>key[200];
vector<ll>lines[510];
ll dp[600];
ll vis[600];
set<ll>pos;
void cle()
{
    LOOP(i,w+1)
    {
        key[i].clear();
    }
    LOOP(i,n+1)
    {
        lines[i].clear();
    }
}
ll binar(ll now_foot_not,ll maxi)
{
    ll low=0;
    ll high=key[now_foot_not].size()-1;
    ll mid;
    ll ans=-1;
    while(low<=high)
    {
        mid=(low+high)/2;
        if(key[now_foot_not][mid]<=maxi)
        {
            ans=key[now_foot_not][mid];
            low=mid+1;
        }
        else
        {
            high=mid-1;
        }
    }
    return ans;
}
ll solve(ll pos)
{
    if(pos==n+1)
    {
        return 0;
    }
    if(vis[pos]==cas)
    {
        return dp[pos];
    }
    vis[pos]=cas;
    ll cnt=0;
    ll ans=inf;
    for(ll i=pos;i<=n;i++)
    {
        for(ll j=0;j<lines[i].size();j++)
        {
            ll now_foot_not=lines[i][j];
            ll ager_pos=binar(now_foot_not,i-1);
            if(ager_pos<pos)
            {
                cnt++;
            }
        }
        if((cnt+i-pos+1)<=s)
        {
            ans=min(ans,(cnt+solve(i+1)));
        }
    }
    return dp[pos]=ans;
}
int main()
{
    scl(tes);
    for(cas=1;cas<=tes;cas++)
    {
        scl(n);
        scl(s);
        scl(w);
        cle();
        FOR(i,w)
        {
            ll freq;
            scl(freq);
            FOR(j,freq)
            {
                ll line;
                scl(line);
                key[i].pb(line);
                lines[line].pb(i);
            }
            sort(key[i].begin(),key[i].end());
        }
        FOR(i,n)
        {
            if(lines[i].size()==0)
            {
                continue;
            }
            pos.clear();
            LOOP(j,lines[i].size())
            {
                pos.insert(lines[i][j]);
            }
            lines[i].clear();
            set<ll>::iterator it;
            for(it=pos.begin();it!=pos.end();it++)
            {
                lines[i].pb(*it);
            }
        }
        ll ans=solve(1);
        if(ans>=inf)
        {
            printf("Case %lld: %lld\n",cas,-1LL);
        }
        else
        {
            printf("Case %lld: %lld\n",cas,ans);
        }
    }
    return 0;
}

