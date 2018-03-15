#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxi 900
ll status[maxi+10];
vector<ll>prime;
void sieve()
{
    for(ll i=2; i<maxi; i++)
    {
        if(status[i]==0)
        {
            for(ll j=i*2; j<maxi; j+=i)
            {
                status[j]=1;
            }
        }
    }
    for(ll i=2; i<maxi; i++)
    {
        if(status[i]==0)
        {
            prime.push_back(i);
        }
    }
}
vector<pair<ll,ll> >factor_base;
vector<pair<ll,ll> >factor_fac;
ll zeros(ll faccc,ll basee)
{
    factor_base.clear();
    ll sq=sqrt(basee);
    ll num=basee;
    ll count1;
    ll prime_base;
    for(ll i=0; prime[i]<=sq; i++)
    {
        if(num%prime[i]==0)
        {
             count1=0;
             while(num%prime[i]==0)
             {
                 num/=prime[i];
                 count1++;
             }
             factor_base.push_back(make_pair(prime[i],count1));
        }
    }
    if(num!=1)
    {
        factor_base.push_back(make_pair(num,1));
    }
    factor_fac.clear();
    for(ll i=0;i<factor_base.size();i++)
    {
        prime_base=factor_base[i].first;
        count1=0;
        while((faccc/prime_base)>0)
        {
            count1+=(long long)(faccc/prime_base);
            prime_base*=factor_base[i].first;
        }
        factor_fac.push_back(make_pair(factor_base[i].first,count1));
    }
    ll minimum=LLONG_MAX;
    ll v;
    for(ll i=0;i<factor_fac.size();i++)
    {
        v=(long long)(factor_fac[i].second/factor_base[i].second);
        if(v<minimum)
        {
            minimum=v;
        }
    }
    return minimum;
}
ll digits(ll faccc,ll basee)
{
    double sum=0;
    for(ll i=1; i<=faccc; i++)
    {
        sum+=log10(i)/log10(basee);
    }
    ll sum2=((long long)(sum))+1;
    return sum2;
}
int main()
{
    sieve();
    ll facc,base;
    while(scanf("%lld%lld",&facc,&base)==2)
    {
        ll digit=digits(facc,base);
        ll zero=zeros(facc,base);
        printf("%lld %lld\n",zero,digit);
    }
    return 0;
}
