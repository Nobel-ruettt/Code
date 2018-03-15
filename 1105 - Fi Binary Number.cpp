#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll faka[100];
ll bare[100];
void pre()
{
    faka[1]=1;
    faka[2]=1;
    bare[1]=1;
    bare[2]=2;
    bare[3]=3;
    ll i;
    for(i=4;;i++)
    {
        faka[i-1]=faka[i-2]+faka[i-3];
        bare[i]=bare[i-1]+faka[i-1];
        if(bare[i]>=1000000000)
        {
            break;
        }
    }
}
ll binary_low(ll number)
{
    ll low=1;
    ll high=44;
    ll mid;
    while(low<=high)
    {
        mid=(low+high)/2;
        if(bare[mid]==number)
        {
            return mid;
        }
        else if(bare[mid]<number)
        {
            low=mid+1;
        }
        else if(bare[mid]>number)
        {
            high=mid-1;
        }
    }
    return high;
}
ll n;
void solve(ll number,ll digit_count)
{
    if(number==0)
    {
        if(digit_count>0)
        {
            printf("0");
            solve(number,digit_count-1);
        }
        else if(digit_count==0)
        {
            printf("\n");
        }
        return ;
    }
    ll index=binary_low(number);
    if(index<digit_count)
    {nn
        printf("0");
        solve(number,digit_count-1);
    }
    else if(index==digit_count)
    {
        printf("1");
        solve(number-bare[index],digit_count-1);
    }
}
int main()
{
    pre();
    ll tes;
    scanf("%lld",&tes);
    for(ll cas=1;cas<=tes;cas++)
    {
       scanf("%lld",&n);
       printf("Case %lld: ",cas);
       printf("1");
       ll index=binary_low(n);
       solve(n-bare[index],index-1);
    }
    return 0;
}
