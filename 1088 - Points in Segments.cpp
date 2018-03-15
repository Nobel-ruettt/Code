#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sc(n) scanf("%lld",&(n))
#define scc(r) scanf("%lf",&(r))
#define foor(i,n) for(long long (i)=1;(i)<=(n);(i)++)
#define inf LLONG_MAX
#define ii if
#define eii else if
#define dd double
ll arr[1000005];
ll search_bi1(ll key,ll n)
{
   ll low=1;
   ll high=n;
   ll mid;
   ll ans=-1;
   while(low<=high)
    {
        mid=(low+high)/2;
        if(arr[mid]==key)
        {
            ans=mid;
            break;
        }
        if(arr[mid]>key)
        {
            high=mid-1;
        }
        else
        {
            low=mid+1;
        }
    }
    if(ans==-1)
    {
        ans=high;
    }
    return ans;
}
ll search_bi2(ll key,ll n)
{
   ll low=1;
   ll high=n;
   ll mid;
   ll ans=-1;
   while(low<=high)
    {
        mid=(low+high)/2;
        if(arr[mid]==key)
        {
            ans=mid;
            break;
        }
        if(arr[mid]>key)
        {
            high=mid-1;
        }
        else
        {
            low=mid+1;
        }
    }
    if(ans==-1)
    {
        ans=low;
    }
    return ans;
}
int main()
{
    ll tes,n,q,l,r;
    sc(tes);
    foor(i,tes)
    {
        sc(n);
        sc(q);
        foor(j,n)
        {
            sc(arr[j]);
        }
        printf("Case %lld: \n",i);
        foor(k,q)
        {
            sc(l);
            ll index1=search_bi2(l,n);
            sc(r);
            ll index2=search_bi1(r,n);
            printf("%lld\n",index2-index1+1);
        }
    }
    return 0;
}
