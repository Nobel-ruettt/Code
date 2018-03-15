#include <bits/stdc++.h>
using namespace std;
#define ll int
struct point
{
    ll x,y;
}arr[3003];
double ans[40002];
ll n,q;
int main()
{
    while(scanf("%d%d",&n,&q))
    {
        if(n==0 && q==0)
        {
            break;
        }
        memset(ans , 0 ,sizeof (ans));
        for(ll i=1;i<=n;i++)
        {
            scanf("%d%d",&arr[i].x,&arr[i].y);
        }
        for(ll i=1;i<=n;i++)
        {
            for(ll j=1;j<=n;j++)
            {
                double now=sqrt(((arr[i].x-arr[j].x)*(arr[i].x-arr[j].x))+((arr[i].y-arr[j].y)*(arr[i].y-arr[j].y)));
                ans[(int)ceil(now)]++;
            }
        }
        for(ll i=1;i<=40001;i++)
        {
            ans[i]+=ans[i-1];
        }
        for(ll i=1;i<=q;i++)
        {
            ll r;
            scanf("%d",&r);
            printf("%0.2lf\n",ans[r]/n);
        }
        printf("\n");
    }
    return 0;
}
