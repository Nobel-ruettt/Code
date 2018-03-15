#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll tes,n,l;
ll arr[1000005];
ll cumsum[100004];
int main()
{
    scanf("%lld",&tes);
    for(ll cas=1;cas<=tes;cas++)
    {
        scanf("%lld%lld",&n,&l);
        for(ll i=1;i<=n;i++)
        {
            scanf("%lld",&arr[i]);
        }
        cumsum[0]=0;
        sort(arr+1,arr+1+n);
        for(ll i=1;i<=n;i++)
        {
            cumsum[i]=cumsum[i-1]+arr[i];
        }
        ll total=0;
        ll pos=-1;
        ll time=-1;
        for(ll i=1;i<=n;i++)
        {
            if(cumsum[i]<=l)
            {
                total+=cumsum[i];
                time=cumsum[i];
                pos=i;
            }
            else
            {
                break;
            }
        }
        if(pos==-1)
        {
            printf("Case %lld: 0 0 0\n",cas);
        }
        else
        {
            printf("Case %lld: %lld %lld %lld\n",cas,pos,time,total);
        }
    }
    return 0;
}
