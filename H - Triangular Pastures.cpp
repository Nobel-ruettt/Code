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
#define MAXN                 42
#define pii                  3.1415926536
#define mod                  1000000007
#define eps                  0.0000000001
#define inf                  900000000000000000
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
/***template***/
ll length[MAXN];
bool dp[MAXN*MAXN][MAXN*MAXN][2];
ll n,s,sum,limit;
int main()
{
    scl(n);
    FOR(i,n)
    {
        scl(length[i]);
        sum+=length[i];
    }
    dp[0][0][s]=1;
    FOR(i,n)
    {
        s^=1;
        limit+=length[i];
        LOP(j,0,limit)
        {
            LOP(k,0,limit)
            {
                bool &r=dp[j][k][s];
                r=dp[j][k][s^1];
                if(j>=length[i])
                {
                    r|=dp[j-length[i]][k][s^1];
                }
                if(k>=length[i])
                {
                    r|=dp[j][k-length[i]][s^1];
                }
            }
        }
    }
    ll sol=0;
    LOP(i,1,limit)
    {
        LOP(j,1,limit)
        {
            if(dp[i][j][s])
            {
                ll k=sum-i-j;
                if ( i + j <= k || i + k <= j || j + k <= i )
                {
                   continue;
                }
                dd p = sum / 2.0;
                dd area = sqrtl( p * (p - i) * (p - j) * (p - k) );
                ll ans=(ll)(area*100.00);
                sol=max(sol,ans);
            }
        }
    }
    if(sol==0)
    {
        cout<<"-1"<<endl;
    }
    else
    {
        cout<<sol<<endl;
    }
    return 0;
}
