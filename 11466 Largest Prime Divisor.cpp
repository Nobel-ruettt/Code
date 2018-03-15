#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define max1 10000100
ll status[max1+3];
vector<ll>prime;
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
    for(ll i=2; i<max1; i++)
    {
        if(status[i]==0)
        {
            prime.push_back(i);
        }
    }
}
ll get_max_prime(ll number)
{
    ll sq=sqrt(number);
    ll num=number;
    ll max2=0;
    for(int i=0; prime[i]<=sq; i++)
    {
        if(num%prime[i]==0)
        {
            if(prime[i]>max2)
            {
                max2=prime[i];
            }
            while(num%prime[i]==0)
            {
                num=num/prime[i];
            }
        }
    }
    if(num>1)
    {
        if(num>max2)
        {
            max2=num;
        }
    }
    return max2;
}
int main()
{
    sieve();
    ll number,max_prime;
    while(scanf("%lld",&number))
    {
        if(number==0)
        {
            break;
        }
        if(number<0)
        {
            number=number*(-1);
        }
        max_prime=get_max_prime(number);
        if(max_prime==number)
        {
            printf("-1\n");
        }
        else
        {
            printf("%lld\n",max_prime);
        }
    }
    return 0;
}
