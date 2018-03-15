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
#define MAXN                 105
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
/***template***/
ll arr[200];
int main()
{
    ll n;
    scl(n);
    FOR(i,n)
    {
        scl(arr[i]);
    }
    ll a=1;
    ll b=1;
    ll c=0;
    ll f=0;
    FOR(i,n)
    {
        if(a==1 && b==1 && c==0)
        {
            if(arr[i]==1)
            {
                b=0;
                c=1;
            }
            else if(arr[i]==2)
            {
                a=0;
                c=1;
            }
            else if(arr[i]==3)
            {
               f=1;
               break;
            }
        }
        else if(a==1 && b==0 && c==1)
        {
            if(arr[i]==1)
            {
                b=1;
                c=0;
            }
            else if(arr[i]==2)
            {
                f=1;
                break;
            }
            else if(arr[i]==3)
            {
               a=0;
               b=1;
            }
        }
        else if(a==0 && b==1 && c==1)
        {
            if(arr[i]==1)
            {
                f=1;
                break;
            }
            else if(arr[i]==2)
            {
                c=0;
                a=1;
            }
            else if(arr[i]==3)
            {
               b=0;
               a=1;
            }
        }
    }
    if(f)
    {
        cout<<"NO"<<endl;
    }
    else
    {
        cout<<"YES"<<endl;
    }
    return 0;
}

