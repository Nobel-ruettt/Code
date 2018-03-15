
#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll first,k,sum,num;
    scanf("%lld%lld",&first,&k);
    sum=0;
    for(ll i=1;i<=first;i++)
    {
        scanf("%lld",&num);
        sum+=num;
    }
    if((sum/first)==k)
    {
        printf("0\n");
        return 0;
    }
    ll sum1=(k-1)*2;
    sum1++;
    ll ans;
    ans=((sum1*first)-(2*sum))/(2*k-sum1);
    cout<<ans<<endl;
    return 0;
}
