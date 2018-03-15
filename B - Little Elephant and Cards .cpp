

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
ll n,val1,val2;
map<ll,ll>open;
map<ll,ll>close;
map<ll,ll>vis;
vector<ll>col;
int main()
{
    scl(n);
    FOR(i,n)
    {
        scl(val1);
        scl(val2);
        if(vis[val1]==0)
        {
            vis[val1]=1;
            col.pb(val1);
        }
        if(vis[val2]==0)
        {
            vis[val2]=1;
            col.pb(val2);
        }
        if(val1==val2)
        {
            open[val1]++;
        }
        else
        {
            open[val1]++;
            close[val2]++;
        }
    }
    ll ordhek=n;
    ordhek/=2;
    if(n%2==1)
    {
        ordhek++;
    }
    ll minimum=inf;
//    cout<<endl;;
    LOOP(i,col.size())
    {
        ll now_col=col[i];
//        cout<<now_col<<" "<<open[now_col]<<" "<<close[now_col]<<endl;
        ll lagbe=ordhek-open[now_col];
        if(lagbe<=0)
        {
            minimum=0;
        }
        else
        {
            if(close[now_col]>=lagbe)
            {
                minimum=min(minimum,lagbe);
            }
        }
    }
    if(minimum==inf)
    {
        cout<<"-1"<<endl;
    }
    else
    {
        cout<<minimum<<endl;
    }
    return 0;
}
