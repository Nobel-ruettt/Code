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
ll two[19];
map<ll,ll>ase;
vector<ll>divv;
ll num;
void printdivvisors(ll n)
{
    // Note that this loop runs till square root
    for (ll i=1; i<=sqrt(n)+1; i++)
    {
        if (n%i==0)
        {
            // If divvisors are equal, print only one
            if (n/i == i)
                divv.pb(i);

            else // Otherwise print both
            {
                divv.pb(i);
                divv.pb(n/i);
            }
        }
    }
}
int main()
{
    two[0]=1;
    for(ll i=1; i<=18; i++)
    {
        two[i]=two[i-1]*2;
    }
    for(ll i=0; i<=17; i++)
    {
        ase[two[i]*(two[i+1]-1)]=1;
    }
    scl(num);
    printdivvisors(num);
    ll maxi=0;
    for(ll i=0;i<divv.size();i++)
    {
        if(ase[divv[i]]==1)
        {
            maxi=max(maxi,divv[i]);
        }
    }
    cout<<maxi<<endl;
    return 0;
}

