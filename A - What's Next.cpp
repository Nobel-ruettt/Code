#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll a1,a2,a3;
    while(1)
    {
        scanf("%lld%lld%lld",&a1,&a2,&a3);
        if(a1==0 && a2==0 && a3==0)
        {
            break;
        }
        if((a2-a1)==(a3-a2))
        {
            printf("AP %lld\n",a3+(a2-a1));
        }
        else
        {
            printf("GP %lld\n",a3*(a2/a1));
        }
    }
    return 0;
}
