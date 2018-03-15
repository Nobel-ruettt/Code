#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define dd double
#define pi 4*atan(1)
int main()
{
     ll tes;
     dd a1,b1,r1,a2,b2,r2;
     scanf("%lld",&tes);
     for(ll i=1;i<=tes;i++)
     {
         scanf("%lf%lf%lf%lf%lf%lf",&a1,&b1,&r1,&a2,&b2,&r2);

         if((r1<r2))
         {
             swap(a1,a2);
             swap(b1,b2);
             swap(r1,r2);
         }

         dd dis=sqrt(((a1-a2)*(a1-a2))+((b1-b2)*(b1-b2)));

         if(dis >= r1+r2)
        {
            printf("Case %lld: %.6f\n",i, 0.0);
            continue;
        }
        if(dis<=fabs(r1-r2))
        {
            printf("Case %d: %.6f\n",i, pi*min(r1, r2)*min(r1, r2));
            continue;
        }

        dd ang1=acos(((r1*r1)+(dis*dis)-(r2*r2))/(2.00*r1*dis));

        dd ang2=acos(((r2*r2)+(dis*dis)-(r1*r1))/(2.00*r2*dis));

       dd  area = .5 * r1*r1*(2*ang1) - .5 * r1*r1*sin(2*ang1) + .5*r2*r2*(2*ang2) - .5*r2*r2*sin(2*ang2);
       printf("Case %lld: %.6f\n",i,area);
     }
     return 0;
}
