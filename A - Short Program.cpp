#include <bits/stdc++.h>
using namespace std;
/***template***/
#define ll                   long long
#define dd                   double
#define scl(n)               scanf("%lld",&n)
#define sci(n)               scanf("%d",&n)
#define scd(n)               scanf("%lf",&n)
#define pi                   pair<ll,ll>
#define pb                   push_back
#define mp                   make_pair
#define uu                   first
#define vv                   second
#define FOR(i,n)             for(ll i=1;i<=n;i++)
#define LOOP(i,n)            for(ll i=0;i<n;i++)
#define FOOR(i,a,b)          for(ll i=a;i<=b;i++)
#define sorted(s)            sort(s.begin(),s.end())
#define reversed(s)          reverse(s.begin(),s.end())
#define contains(a,b)        (find((a).begin(), (a).end(), (b)) != (a).end())
#define MAXN                 200005
#define pii                  3.1415926536
#define mod                  1000000007
#define eps                  0.0000000001
#define inf                  900000000000000000
/***template***/
ll Set(ll n,ll pos){return n=n|(1<<pos);}
ll reset(ll n,ll pos){return n=n&~(1<<pos);}
bool check(ll n,ll pos){return (bool)(n&(1<<pos));}
int main()
{
    ll n;
    scl(n);
    ll a=1023;
    ll b=0;
    char c;
    ll val;
    ll andd=1023;
    ll orr=0;
    ll xorr=0;
    FOR(i,n)
    {
        scanf(" %c %lld",&c,&val);
        if(c=='|')
        {
            a|=val;
            b|=val;
        }
        if(c=='^')
        {
            a^=val;
            b^=val;
        }
        if(c=='&')
        {
            a&=val;
            b&=val;
        }
    }
    LOOP(i,10)
    {
        if(check(a,i)==0 && check(b,i)==1)
        {
            xorr=Set(xorr,i);
        }
        else if(check(a,i)==0 && check(b,i)==0)
        {
            andd=reset(andd,i);
        }
        else if(check(a,i)==1 && check(b,i)==1)
        {
            orr=Set(orr,i);
        }
    }
    printf("3\n");
    printf("| %lld\n",orr);
    printf("& %lld\n",andd);
    printf("^ %lld\n",xorr);
    return 0;
}
