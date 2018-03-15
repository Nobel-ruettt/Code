#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define dd double
#define pi acos(-1)
struct point
{
    ll x,y;
    point(){}
    point(ll a,ll b)
    {
        x=a;
        y=b;
    }
};
ll n;
double sum;
int main()
{
    ll tes;
    scanf("%lld",&tes);
    for(ll cas=1;cas<=tes;cas++)
    {
        sum=0;
        scanf("%lld",&n);
        for(ll i=1;i<=n;i++)
        {
            point f1,f2;
            scanf("%lld%lld%lld%lld",&f1.x,&f1.y,&f2.x,&f2.y);
            dd angle=fabs(atan2(f1.y,f1.x)-atan2(f2.y,f2.x));
            if(angle>pi)
            {
                angle=pi*2-angle;
            }
            sum+=angle;
        }
        printf("%0.5lf\n",sum/pi/2);
    }
    return 0;
}
