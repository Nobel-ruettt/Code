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
ll arr[1100];
ll can(ll highh,ll n)
{
    ll sum=0;
    ll count1=0;
    foor(i,n)
    {
        if(arr[i]>highh)
        {
            return inf;
        }
        else if(sum+arr[i]==highh)
        {
            sum=0;
            count1++;
        }
        else if(sum+arr[i]>highh)
        {
            sum=arr[i];
            count1++;
        }
        else if(sum+arr[i]<highh)
        {
            sum+=arr[i];
        }
    }
    if(sum)count1++;
    return count1;
}
int main()
{
    ll tes,n,m,maxi,sum,mid,low,high,ans;
    sc(tes);
    foor(i,tes)
    {
        sc(n);
        sc(m);
        maxi=0;
        sum=0;
        foor(j,n)
        {
            sc(arr[j]);
            if(arr[j]>maxi)
            {
                maxi=arr[j];
            }
            sum+=arr[j];
        }
        if(m>=n)
        {
            printf("Case %lld: %lld\n",i,maxi);
            continue;
        }
        low=0,high=sum,ans;
        while(low<=high)
        {
            mid=(low+high)/2;
            if(can(mid,n)<=m)
            {
                ans=mid;
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
        }
        printf("Case %lld: %lld\n",i,ans);
    }
    return 0;
}
