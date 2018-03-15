#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll tes,t,d;
    double ans;
    scanf("%lld",&tes);
    for(ll i=1;i<=tes;i++)
    {
        ans=0.000;
        scanf("%lld%lld",&t,&d);
        if(t%2==1)
        {
            printf("Case %lld: %0.9lf\n",i,ans);
            continue;
        }
        else
        {
            ans=1.00;
            ans/=(double)(t+1);
            printf("Case %lld: %0.9lf\n",i,ans);
        }
    }
    return 0;
}
