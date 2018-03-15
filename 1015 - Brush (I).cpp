#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll tes,n,sum,dust;
    scanf("%lld",&tes);
    for(ll i=1;i<=tes;i++)
    {
        scanf("%lld",&n);
        sum=0;
        for(ll i=0;i<n;i++)
        {
            scanf("%lld",&dust);
            if(dust>0)
            {
                sum+=dust;
            }
        }
        printf("Case %lld: %lld\n",i,sum);
    }
    return 0;
}
