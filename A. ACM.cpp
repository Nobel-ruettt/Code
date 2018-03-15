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
#define MAXN                 500005
#define pii                  3.1415926536
#define mod                  1000000007
#define eps                  0.0000000001
#define inf                  900000000000000000
/***template***/
ll a[7];
ll make;
ll solve()
{
    FOR(i,6)
    {
        for(ll j=i+1;j<=6;j++)
        {
            for(ll k=j+1;k<=6;k++)
            {
                if(a[i]+a[j]+a[k]==make)
                {
                    return 1;
                }
            }
        }
    }
    return 0;
}
int main()
{
    ll sum=0;
    FOR(i,6)
    {
        scl(a[i]);
        sum+=a[i];
    }
    if(sum%2!=0)
    {
        printf("NO\n");
        return 0;
    }
    make=(sum/2);
    if(solve()==1)
    {
        cout<<"YES"<<endl;
    }
    else
    {
        cout<<"NO"<<endl;
    }
    return 0;
}
