#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll mor[105];
    ll eve[105];
    ll n,d,r,sum;
    while(scanf("%lld%lld%lld",&n,&d,&r))
    {
        if(n==0&&d==0&&r==0)
        {
            break;
        }
        for(int i=0;i<n;i++)
        {
            scanf("%lld",&mor[i]);
        }
        sort(mor,mor+n);
        for(int i=0;i<n;i++)
        {
            scanf("%lld",&eve[i]);
        }
        sort(eve,eve+n,greater<ll>());
        sum=0;
        for(int i=0;i<n;i++)
        {
            if((mor[i]+eve[i])>d)
            {
                sum=sum+((mor[i]+eve[i]-d)*r);
            }
        }
        printf("%lld\n",sum);
    }
    return 0;
}
