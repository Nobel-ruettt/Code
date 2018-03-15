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
char s[10][1000];
string left_al;
        string right_al;
ll calc(ll num)
{
    ll sum=0;
    while(num>1)
    {
        if(num%2==0)
        {
            sum+=250;
        }
        else if(num%2==1)
        {
            sum+=500;
        }
        num/=2;
    }
    sum+=500;
    return sum;
}
int main()
{
    char soman[7][18]=
    {
        {46,46,46,46,46,46,46,46,124,124,46,46,46,46,46,46,46,46,},
        {46,46,46,47,92,46,46,46,124,124,46,46,46,47,92,46,46,46,},
        {46,46,47,46,46,92,46,46,124,124,46,46,47,46,46,92,46,46,},
        {46,47,46,46,46,46,92,46,124,124,46,47,46,46,46,46,92,46,},
        {47,46,46,46,46,46,46,92,124,124,47,46,46,46,46,46,46,92,},
        {92,95,95,95,95,95,95,47,124,124,92,95,95,95,95,95,95,47,},
        {46,46,46,46,46,46,46,46,124,124,46,46,46,46,46,46,46,46,},
    };
    char left_boro[7][18]=
    {
        {46,46,46,46,46,46,46,46,124,124,46,46,46,47,92,46,46,46,},
        {46,46,46,46,46,46,46,46,124,124,46,46,47,46,46,92,46,46,},
        {46,46,46,47,92,46,46,46,124,124,46,47,46,46,46,46,92,46,},
        {46,46,47,46,46,92,46,46,124,124,47,46,46,46,46,46,46,92,},
        {46,47,46,46,46,46,92,46,124,124,92,95,95,95,95,95,95,47,},
        {47,46,46,46,46,46,46,92,124,124,46,46,46,46,46,46,46,46,},
        {92,95,95,95,95,95,95,47,124,124,46,46,46,46,46,46,46,46,},
    };
    char right_boro[7][18]=
    {
        {46,46,46,47,92,46,46,46,124,124,46,46,46,46,46,46,46,46,},
        {46,46,47,46,46,92,46,46,124,124,46,46,46,46,46,46,46,46,},
        {46,47,46,46,46,46,92,46,124,124,46,46,46,47,92,46,46,46,},
        {47,46,46,46,46,46,46,92,124,124,46,46,47,46,46,92,46,46,},
        {92,95,95,95,95,95,95,47,124,124,46,47,46,46,46,46,92,46,},
        {46,46,46,46,46,46,46,46,124,124,47,46,46,46,46,46,46,92,},
        {46,46,46,46,46,46,46,46,124,124,92,95,95,95,95,95,95,47,},
    };
    ll tes;
    ll num;
    scl(tes);
    FOR(cas,tes)
    {
        LOOP(i,8)
        {
            scanf(" %s",s[i]);
        }
        ll left_pan=0;
        ll right_pan=0;
        ll le=-1;
        ll ri=-1;
        left_al.clear();
        right_al.clear();
        LOOP(i,8)
        {
            for(ll j=0; j<=7; j++)
            {
                if(s[i][j]>='A' && s[i][j]<='Z')
                {
                    left_al.pb(s[i][j]);
                    left_pan+=calc(s[i][j]);
                }
                if(s[i][j]=='_' && i<7)
                {
                    le=max(le,i);
                }
            }
            for(ll j=10; j<=17; j++)
            {
                if(s[i][j]>='A' && s[i][j]<='Z')
                {
                    right_al.pb(s[i][j]);
                    right_pan+=calc(s[i][j]);
                }
                if(s[i][j]=='_' && i<7)
                {
                    ri=max(ri,i);
                }
            }
        }
        bool f=0;
        if(left_pan==right_pan)
        {
            if(le==ri)
            {
                f=1;
                printf("Case %lld:\n",cas);
                printf("The figure is correct.\n");
            }
        }
        else if(left_pan>right_pan)
        {
            if(le>ri)
            {
                f=1;
                printf("Case %lld:\n",cas);
                printf("The figure is correct.\n");
            }
        }
        else if(left_pan<right_pan)
        {
            if(le<ri)
            {
                f=1;
                printf("Case %lld:\n",cas);
                printf("The figure is correct.\n");
            }
        }
        if(f)
        {
            continue;
        }
        else
        {
            char ans[7][18];
            if(left_pan==right_pan)
            {

                for(ll i=0;i<7;i++)
                {
                    for(ll j=0;j<18;j++)
                    {
                        ans[i][j]=soman[i][j];
                    }
                }
                ll cnt=0;
                for(ll i=1;cnt<left_al.size();i++)
                {
                    ans[4][i]=left_al[cnt];
                    cnt++;
                }
                cnt=0;
                for(ll i=11;cnt<right_al.size();i++)
                {
                    ans[4][i]=right_al[cnt];
                    cnt++;
                }
            }
            else if(left_pan>right_pan)
            {

                for(ll i=0;i<7;i++)
                {
                    for(ll j=0;j<18;j++)
                    {
                        ans[i][j]=left_boro[i][j];
                    }
                }
                ll cnt=0;
                for(ll i=1;cnt<left_al.size();i++)
                {
                    ans[5][i]=left_al[cnt];
                    cnt++;
                }
                cnt=0;
                for(ll i=11;cnt<right_al.size();i++)
                {
                    ans[3][i]=right_al[cnt];
                    cnt++;
                }
            }
            else if(left_pan<right_pan)
            {

                for(ll i=0;i<7;i++)
                {
                    for(ll j=0;j<18;j++)
                    {
                        ans[i][j]=right_boro[i][j];
                    }
                }
                ll cnt=0;
                for(ll i=1;cnt<left_al.size();i++)
                {
                    ans[3][i]=left_al[cnt];
                    cnt++;
                }
                cnt=0;
                for(ll i=11;cnt<right_al.size();i++)
                {
                    ans[5][i]=right_al[cnt];
                    cnt++;
                }
            }
            printf("Case %lld:\n",cas);
            for(ll i=0;i<7;i++)
            {
                for(ll j=0;j<18;j++)
                {
                    printf("%c",ans[i][j]);
                }
                printf("\n");
            }
        }
    }
    return 0;
}

