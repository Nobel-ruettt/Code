#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxi 65540
#define mod 1000000007
ll status[maxi+10];
vector<ll>prime;
vector< pair<ll,ll> >prime_factorization;
void sieve()
{
    for(ll i=2;i<maxi;i++)
    {
        if(status[i]==0)
        {
            for(ll j=2*i;j<maxi;j+=i)
            {
                status[j]=1;
            }
        }
    }
    for(ll i=2;i<maxi;i++)
    {
        if(status[i]==0)
        {
            prime.push_back(i);
        }
    }
}
ll fast_expo_modulo(ll x, ll y)
{
    ll res = 1;
    x = x % mod;
    while (y > 0)
    {
        if (y & 1)
        {
               res = (res*x) % mod;
        }
        y = y>>1;
        x = (x*x) % mod;
    }
    return res;
}
ll sum(ll base,ll power)
{
    ll res1=((fast_expo_modulo(base,power+1)%mod)-1)%mod;
    res1=(res1*fast_expo_modulo(base-1,mod-2))%mod;
    return (res1+mod)%mod;
}
int main()
{
    ll base,power,tes;
    sieve();
    scanf("%lld",&tes);
    for(ll i=1; i<=tes; i++)
    {
        prime_factorization.clear();
        scanf("%lld%lld",&base,&power);
        ll sq=sqrt(base);
        ll number=base;
        ll count1;
        for(ll j=0;prime[j]<=sq;j++)
        {
             if(number%prime[j]==0)
             {
                count1=0;
                while(number%prime[j]==0)
                {
                    count1++;
                    number=number/prime[j];
                }
                prime_factorization.push_back(make_pair(prime[j],count1*power));
             }
        }
        if(number!=1)
        {
            prime_factorization.push_back(make_pair(number,1*power));
        }
        ll result=1;
        for(ll j=0;j<prime_factorization.size();j++)
        {
            result=((result)*(sum(prime_factorization[j].first,prime_factorization[j].second)%mod))%mod;
        }
        printf("Case %lld: %lld\n",i,result);
    }
    return 0;
}
