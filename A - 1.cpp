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
ll tes;
ll a,b;
ll cas;
map<ll,map<ll,ll> >vis;
pi rep;
dd ans_win,ans_len;
ll depth;
dd ans_f,ans_ff;
void solve(ll al,ll bob,ll d)
{
    if(d>30)
    {
        return ;
    }
    if(al==0 || bob==0)
    {
        return ;
    }
    if(vis[al][bob]==cas)
    {
        rep.uu=al;
        rep.vv=bob;
        return ;
    }
    vis[al][bob]=cas;
    if(al<=bob)
    {
        solve(0,bob+al,d+1);
        solve(al*2,bob-al,d+1);
    }
    else
    {
        solve(al+bob,0,d+1);
        solve(al-bob,bob*2,d+1);
    }
}
dd solve2(ll al,ll bob,ll d)
{
    if(al==0)
    {
        return 0;
    }
    else if(bob==0)
    {
        return 1;
    }
    if(d>30)
    {
        return 0;
    }
    dd ans=0.00;
    dd ans2=0.00;
    if(al<=bob)
    {
        ans2+=solve2(0,bob+al,d+1);
        ans2+=solve2(al*2,bob-al,d+1);
    }
    else
    {
        ans2+=solve2(al+bob,0,d+1);
        ans2+=solve2(al-bob,bob*2,d+1);
    }
    ans=0.5*(ans2);
    return ans;
}
dd solve3(ll al,ll bob,ll d)
{
    if(al==0)
    {
        return 0;
    }
    else if(bob==0)
    {
        return 0;
    }
    if(d>30)
    {
        return 0;
    }
    dd ans=0.00;
    dd ans2=0.00;

    if(al<=bob)
    {
        ans2+=solve3(0,bob+al,d+1);
        ans2+=solve3(al*2,bob-al,d+1);
    }
    else
    {
        ans2+=solve3(al+bob,0,d+1);
        ans2+=solve3(al-bob,bob*2,d+1);
    }
    ans=1+0.5*ans2;
    return ans;
}
dd solve4(ll al,ll bob,ll d)
{
    if(al==rep.uu && bob==rep.vv && d>0)
    {
        depth=d;
        return 0;
    }
    if(al==0)
    {
        return 0;
    }
    else if(bob==0)
    {
        return 1;
    }
    dd ans=0.00;
    dd ans2=0;
    if(al<=bob)
    {
        ans2+=solve4(0,bob+al,d+1);
        ans2+=solve4(al*2,bob-al,d+1);
    }
    else
    {
        ans2+=solve4(al+bob,0,d+1);
        ans2+=solve4(al-bob,bob*2,d+1);
    }
    ans=0.5*ans2;
    return ans;
}
dd solve5(ll al,ll bob)
{
    if(al==rep.uu && bob==rep.vv)
    {
        return ans_f;
    }
    if(al==0)
    {
        return 0;
    }
    else if(bob==0)
    {
        return 1;
    }
    dd ans=0.00;
    dd ans2=0;
    if(al<=bob)
    {
        ans2+=solve5(0,bob+al);
        ans2+=solve5(al*2,bob-al);
    }
    else
    {
        ans2+=solve5(al+bob,0);
        ans2+=solve5(al-bob,bob*2);
    }
    ans=0.5*ans2;
    return ans;
}
dd solve6(ll al,ll bob,ll d)
{
    if(al==rep.uu && bob==rep.vv && d>0)
    {
        return 0;
    }
    if(al==0)
    {
        return 0;
    }
    else if(bob==0)
    {
        return 0;
    }
    dd ans=0.00;
    dd ans2=0;
    if(al<=bob)
    {
        ans2+=solve6(0,bob+al,d+1);
        ans2+=solve6(al*2,bob-al,d+1);
    }
    else
    {
        ans2+=solve6(al+bob,0,d+1);
        ans2+=solve6(al-bob,bob*2,d+1);
    }
    ans=1.00+0.5*(ans2);
    return ans;
}
dd solve7(ll al,ll bob)
{
    if(al==rep.uu && bob==rep.vv)
    {
        return ans_ff;
    }
    if(al==0)
    {
        return 0;
    }
    else if(bob==0)
    {
        return 0;
    }
    dd ans=0.00;
    dd ans2=0;
    if(al<=bob)
    {
        ans2+=solve7(0,bob+al);
        ans2+=solve7(al*2,bob-al);
    }
    else
    {
        ans2+=solve7(al+bob,0);
        ans2+=solve7(al-bob,bob*2);
    }
    ans=1.000+0.5*(ans2);
    return ans;
}
int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("out2.txt","w",stdout);
    ll pwr[62];
    pwr[0]=1;
    for(ll i=1;i<=60;i++)
    {
        pwr[i]=pwr[i-1]*2;
    }
    scl(tes);
    for(cas=1;cas<=tes;cas++)
    {
        rep.uu=-1;
        rep.vv=-1;
        scl(a);
        scl(b);
        solve(a,b,0);
//        printf("%lld %lld\n",a,b);
        if(rep.uu==-1)
        {
            ans_win=solve2(a,b,0);
            ans_len=solve3(a,b,0);
            printf("Case %lld: %0.6f %0.6f\n",cas,ans_len,ans_win);
        }
        else
        {
            ans_f=solve4(rep.uu,rep.vv,0);
            ans_f=((ans_f*((dd)pwr[depth]))/(dd)(pwr[depth]-1));
            ans_win=solve5(a,b);
            ans_ff=solve6(rep.uu,rep.vv,0);
            ans_ff=((ans_ff*((dd)pwr[depth]))/(dd)(pwr[depth]-1));
//            cout<<ans_ff<<endl;
            ans_len=solve7(a,b);
            printf("Case %lld: %0.6f %0.6f\n",cas,ans_len,ans_win);
        }
    }
    return 0;
}
/*
6 3
Case 1: 2.000000 0.666667
6 7
Case 2: 2.000000 0.461538
7 8
Case 3: 2.000000 0.466667
*/
