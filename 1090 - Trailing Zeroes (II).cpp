#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll number_of_twos_in_fac(ll number)
{
    ll s=2;
    ll sum=0;
    while(number/s>0)
    {
        sum+=(long long)(number/s);
        s=s*2;
    }
    return sum;
}
ll number_of_fives_in_fac(ll number)
{
    ll s=5;
    ll sum=0;
    while(number/s>0)
    {
        sum+=(long long)(number/s);
        s=s*5;
    }
    return sum;
}
ll number_of_twos_in_pow(ll number,ll power)
{
    ll num=number;
    ll sum=0;
    while(num%2==0)
    {
        num/=2;
        sum++;
    }
    return sum*power;
}
ll number_of_fives_in_pow(ll number,ll power)
{
    ll num=number;
    ll sum=0;
    while(num%5==0)
    {
        num/=5;
        sum++;
    }
    return sum*power;
}
int main()
{
    ll tes,n,r,p,q;
    scanf("%lld",&tes);
    for(ll i=1; i<=tes; i++)
    {
        scanf("%lld%lld%lld%lld",&n,&r,&p,&q);
        ll two_fa=number_of_twos_in_fac(n)-(number_of_twos_in_fac(r)+number_of_twos_in_fac(n-r));
        ll five_fa=number_of_fives_in_fac(n)-(number_of_fives_in_fac(r)+number_of_fives_in_fac(n-r));
        ll two_p=number_of_twos_in_pow(p,q);
        ll five_p=number_of_fives_in_pow(p,q);
        ll two=two_fa+two_p;
        ll five=five_fa+five_p;
        ll ans;
        if(two>five)
        {
            ans=five;
        }
        else if(five>two)
        {
            ans=two;
        }
        else if(five==two)
        {
            ans=two;
        }
        printf("Case %lld: %lld\n",i,ans);
    }
    return 0;
}
