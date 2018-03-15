#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define max1 40000
ll status[max1];
ll prime[max1];
void sieve()
{
    for(int i = 2; i <= max1; i++ )
    {
        if( status[i] == 0 )
        {
            for(int  j = 2 * i; j <= max1; j += i )
            {
                status[j] = 1;
            }
        }
    }
    ll count1=0;
    for(ll i=2; i<max1; i++)
    {
        if(status[i]==0)
        {
            prime[count1]=i;
            count1++;
        }
    }
}
ll num_of_divisors(ll number)
{
    ll sq=sqrt(number);
    ll num=number;
    ll sum=1;
    ll pow;
    for(int i=0; prime[i]<=sq; i++)
    {
        if(num%prime[i]==0)
        {
            pow=0;
            while(num%prime[i]==0)
            {
                pow++;
                num=num/prime[i];
            }
            pow++;
            sum*=pow;
        }
    }
    if(num>1)
    {
        sum*=2;
    }
    return sum;
}
int main()
{
    sieve();
    ll tes,low,up,max_div,max_div_pos,divisors;
    scanf("%lld",&tes);
    for(int i=1;i<=tes;i++)
    {
        max_div=0;
        max_div_pos=0;
        scanf("%lld%lld",&low,&up);
        for(ll i=low;i<=up;i++)
        {
            divisors=num_of_divisors(i);
            if(divisors>max_div)
            {
                max_div=divisors;
                max_div_pos=i;
            }
        }
        printf("Between %lld and %lld, %lld has a maximum of %lld divisors.\n",low,up,max_div_pos,max_div);
    }
    return 0;
}
