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
#define MAXN                 100005
#define pii                  3.1415926536
#define mod                  1000000007
#define eps                  0.0000000001
#define inf                  9000000000000000
#define mstt(a,b)            memset((a),(b),sizeof (a))
ll Set(ll n,ll pos)
{
    return n=n|(1<<pos);
}
ll reset(ll n,ll pos)
{
    return n=n&~(1<<pos);
}
bool check(ll n,ll pos)
{
    return (bool)(n&(1<<pos));
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
/***template***/
ll two[MAXN];
bool status[MAXN];
ll mobius[MAXN];
ll prime[MAXN];
ll a[MAXN];
ll cnt[MAXN];
int main()
{
    two[0]=1;
    mobius[1]=1;
    FOR(i,MAXN-1)
    {
        two[i]=mul(two[i-1],2);
    }
    ll tot=0;
    for(ll i=2; i<MAXN; i++)
    {
        if(!status[i])
        {
            prime[tot++] = i;
            mobius[i] = -1;
        }
        for(ll j=0; j<tot; j++)
        {
            if(i*prime[j]>=MAXN)
            {
                break;
            }
            status[i*prime[j]] = 1;
            if(i%prime[j] == 0)
            {
                mobius[i*prime[j]] = 0;
                break;
            }
            else
            {
                mobius[i*prime[j]] = -mobius[i];
            }
        }
    }
    ll n;
    scl(n);
    FOR(i,n)
    {
        scl(a[i]);
    }
    for(ll i=1;i<=n;i++)
    {
        for(ll j=1;j*j<=a[i];j++)
        {
            if(a[i]%j)
            {
                continue;
            }
            if(j*j != a[i])
            {
                cnt[a[i]/j]++;
            }
            cnt[j]++;
        }
    }
    ll ans=0;
    FOR(i,MAXN-1)
    {
        ll now_ans=mul((mobius[i]),sub(two[cnt[i]],1));
        ans=add(ans,now_ans);
    }
    printf("%lld\n",(ans+mod)%mod);
    return 0;
}

