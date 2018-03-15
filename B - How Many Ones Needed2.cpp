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
ll a,b;
#define max_l 33
vector<ll>dig;
ll arr[max_l];
pi dp[40][2];
ll vis[40][2];
pi solve(ll pos,ll is_big)
{
    if(pos>=33)
    {
        return pi(0,1);
    }
    if(vis[pos][is_big]==1)
    {
        return dp[pos][is_big];
    }
    vis[pos][is_big]=1;
    ll ret=0;
    ll lez=0;
    if(is_big==1)
    {
        if(arr[pos]==1)
        {
            pi ans=solve(pos+1,0);
            ret+=ans.first;
            lez+=ans.second;
            ans=solve(pos+1,1);
            ret+=(ans.vv+ans.uu);
            lez+=ans.vv;
        }
        else if(arr[pos]==0)
        {
            pi ans=solve(pos+1,1);
            ret+=ans.uu;
            lez+=ans.vv;
        }
    }
    else if(is_big==0)
    {
        pi ans=solve(pos+1,0);
        ret+=(ans.vv+2*ans.uu);
        lez+=(2*ans.vv);
    }
    dp[pos][is_big].uu=ret;
    dp[pos][is_big].vv=lez;
    return dp[pos][is_big];
}
int main()
{
    ll cas=1;
    while(scanf("%lld %lld",&a,&b)==2)
    {
        if(a==0 && b==0)
        {
            break;
        }
        mstt(vis,0);
        mstt(arr,0);
        dig.clear();
        ll num=b;
        while(num>1)
        {
            dig.pb(num%2);
            num/=2;
        }
        dig.pb(1);
        ll cnt=32;
        for(ll i=0;i<dig.size();i++)
        {
            arr[cnt]=dig[i];
            cnt--;
        }
        ll ans1=solve(0,1).uu;
        mstt(vis,0);
        mstt(arr,0);
        dig.clear();
        if(a<=1)
        {
            printf("Case %lld: %lld\n",cas,ans1);
            cas++;
            continue;
        }
        num=a-1;
        while(num>1)
        {
            dig.pb(num%2);
            num/=2;
        }
        dig.pb(1);
        cnt=32;
        for(ll i=0;i<dig.size();i++)
        {
            arr[cnt]=dig[i];
            cnt--;
        }
        ll ans2=solve(0,1).uu;
        printf("Case %lld: %lld\n",cas,ans1-ans2);
        cas++;
    }
    return 0;
}

