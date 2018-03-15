#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define dd double
int main()
{
    ll tes;
    scanf("%lld",&tes);
    for(ll i=1;i<=tes;i++)
    {
        dd a,b,c,d;
        scanf("%lf%lf%lf%lf",&a,&b,&c,&d);
        if(a<c)
        {
            swap(a,c);
        }
        dd f=(a-c);
        dd s=b;
        dd t=d;
        dd ss=(f+s+t)/2.00;
        dd area=sqrt(ss*(ss-f)*(ss-s)*(ss-t));
        dd h=(area*2.00)/f;
        dd area2=((a+c)*h)/2.00;
        printf("Case %lld: %0.6lf\n",i,area2);
    }
    return 0;
}
