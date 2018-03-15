#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sc(n) scanf("%lld",&(n))
#define foor(i,n) for(long long (i)=1;(i)<=(n);(i)++)
#define inf LLONG_MAX
#define ii if
#define eii else if
ll tes,n,k,sum;
ll arr[1100];
ll how_many(ll high)
{
    ll sum=0;
    ll steps=0;
    foor(i,n+1)
    {
        ii(arr[i]>high)
        {
            return inf;
        }
        eii(sum+arr[i]==high)
        {
            sum=0;
            steps++;
        }
        eii(sum+arr[i]>high)
        {
            sum=arr[i];
            steps++;
        }
        eii(sum+arr[i]<high)
        {
            sum+=arr[i];
        }
    }
    ii(sum)steps++;
    return steps;
}
void sim(ll high)
{
    ll sum=0;
    ll steps=0;
    foor(i,n+1)
    {
        ii(sum+arr[i]>high)
        {
            printf("%lld\n",sum);
            sum=arr[i];
            steps++;
        }
        eii(sum+arr[i]==high)
        {
            printf("%lld\n",sum+arr[i]);
            sum=0;
            steps++;
        }
        eii(n+1-i==k-steps)
        {
            printf("%lld\n",sum+arr[i]);
            sum=0;
            steps++;
        }
        else
        {
            sum+=arr[i];
        }
    }
}
int main()
{
    sc(tes);
    foor(l,tes)
    {
        sc(n);sc(k);
        sum=0;
        foor(i,n+1)
        {
            sc(arr[i]);
            sum+=arr[i];
        }
        ll low=0;
        ll high=sum;
        ll mid;
        ll ans;
        while(low<=high)
        {
            mid=(low+high)>>1;
            ll steps=how_many(mid);
            ii(steps<=k+1)
            {
                ans=mid;
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
        }
        printf("Case %lld: %lld\n",l,ans);
        sim(ans);
    }
    return 0;
}
