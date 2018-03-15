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
string s;
struct node
{
    ll open,balanced,closed;
}seg[4*1000005];
void build(ll node,ll b,ll e)
{
    if(b==e)
    {
        if(s[b-1]=='(')
        {
            seg[node].balanced=0;
            seg[node].open++;
            seg[node].closed=0;
        }
        if(s[b-1]==')')
        {
            seg[node].balanced=0;
            seg[node].open=0;
            seg[node].closed++;
        }
        return ;
    }
    ll mid=(b+e)/2;
    build(node*2,b,mid);
    build(node*2+1,mid+1,e);
    seg[node].balanced=seg[node*2].balanced+seg[node*2+1].balanced;
    seg[node].balanced+=min(seg[node*2].open,seg[node*2+1].closed);
    seg[node].open=seg[node*2+1].open+seg[node*2].open-min(seg[node*2].open,seg[node*2+1].closed);
    seg[node].closed=seg[node*2].closed+seg[node*2+1].closed-min(seg[node*2].open,seg[node*2+1].closed);
}
node query(ll n,ll b,ll e,ll i,ll j)
{
    if(b>=i && e<=j)
    {
        return seg[n];
    }
    else if(b>j || e<i)
    {
        node res;
        res.balanced=0;
        res.closed=0;
        res.open=0;
        return res;
    }
    ll mid=(b+e)/2;
    node lefti=query(n*2,b,mid,i,j);
    node righti=query(n*2+1,mid+1,e,i,j);
    node res;
    res.balanced=lefti.balanced+righti.balanced;
    res.balanced+=min(lefti.open,righti.closed);
    res.open=righti.open+lefti.open-min(lefti.open,righti.closed);
    res.closed=lefti.closed+righti.closed-min(lefti.open,righti.closed);
    return res;
}
int main()
{
    cin>>s;
    build(1,1,s.size());
    ll q;
    scl(q);
    FOR(i,q)
    {
        ll l,r;
        scl(l);
        scl(r);
        printf("%lld\n",query(1,1,s.size(),l,r).balanced*2);
    }
    return 0;
}
