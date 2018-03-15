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
ll n;
ll data[400125];
map<ll,ll>pos;
int main()
{
    scl(tes);
    FOR(cas,tes)
    {
        scl(n);
        printf("Case %lld:\n",cas);
        ll low = 200025, high = 200025;
        pos.clear();
        LOOP(i,n)
        {
            ll type;
            char x;
            ll y;
            scl(type);
            if(type == 1)
            {
                scanf(" %c %lld",&x,&y);
                if(x == 'B')
                {
                    data[high] = y;
                    pos[y] = high;
                    high++;
                }
                else
                {
                    low--;
                    data[low] = y;
                    pos[y] = low;
                }
            }
            else if(type == 2)
            {
                scanf(" %c",&x);
                if(x == 'B')
                {
                    high --;
                }
                else
                {
                    low ++;
                }
            }
            else
            {
                scanf(" %c %lld\n",&x,&y);
                if(x == 'D')
                {
                    cout << data[low + y - 1] << endl;
                }
                else
                {
                    cout << pos[y] - low + 1 << endl;
                }
            }
        }
    }

    return 0;
}
/*
1000
1 B 2
1 B 3
1 F 1
1 F 5
1 F 7
1 B 4
1 F 9
1 B 10
1 F 11
2 B
3 D 1
3 D 2
3 D 3
3 D 4
3 D 5
3 D 6
3 D 7
3 D 8
*/
