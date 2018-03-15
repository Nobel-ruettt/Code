#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sc(n) scanf("%lld",&(n))
#define foor(i,n) for(long long (i)=1;(i)<=(n);(i)++)
#define inf LLONG_MAX
#define ii if
#define eii else if
#define dd double
ll tes,length,width;
dd low,high,mid,gunok,length_now,width_now,radius,thita,chap_pori,porisima,now,prev;
int main()
{
    sc(tes);
    for(ll i=1;i<=tes;i++)
    {
        scanf("%lld : %lld",&length,&width);
        low=0.00;
        high=400.00;
        prev=-1000.00;
        ll count1=0;
        while(low<=high)
        {
            mid=(low+high)/2.00;
            gunok=mid;
            now=mid;
            count1++;
            length_now=gunok*(double)length;
            width_now=gunok*(double)width;
            radius=sqrt((length_now*length_now)+(width_now*width_now));
            radius/=2.00;
            thita=((2.00*(radius*radius))-(width_now*width_now))/(2.00*radius*radius);
            thita=acos(thita);
            chap_pori=thita*radius;
            porisima=(2.00*chap_pori)+(2.00*length_now);
            if(porisima<=400.00)
            {
                low=mid;
            }
            else
            {
                high=mid;
            }
            if(fabs(now-prev)<0.000000001)
            {
                break;
            }
            prev=now;
        }
        printf("Case %lld: %0.7lf %0.7lf\n",i,length_now,width_now);
    }
    return 0;
}
