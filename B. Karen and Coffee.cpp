#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxi 200005
ll status[maxi];
ll count1[maxi];
int main()
{
    ll n,k,q;
    ll l,r;
    scanf("%lld%lld%lld",&n,&k,&q);
    for(ll i=1;i<=n;i++)
    {
        scanf("%lld%lld",&l,&r);
        status[l]++;
        status[r+1]--;
    }
    for(ll i=1;i<maxi;i++)
    {
        status[i]=status[i-1]+status[i];
    }
    for(ll i=1;i<maxi;i++)
    {
        if(status[i]>=k)
        {
            count1[i]=1;
        }
    }
    for(ll i=1;i<maxi;i++)
    {
        count1[i]=count1[i-1]+count1[i];
    }
    for(ll i=1;i<=q;i++)
    {
        scanf("%lld%lld",&l,&r);
        printf("%lld\n",count1[r]-count1[l-1]);
    }
    return 0;
}
