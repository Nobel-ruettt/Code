#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxi 10010
int status[maxi+10];
vector<ll>prime;
vector<pair<ll,ll> >m_fac;
vector<pair<ll,ll> >fac;
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
int main()
{
    sieve();
    ll tes,m,n;
    ll num;
    ll number;
    ll sq;
    ll count1,count2;
    ll fac_number;
    ll primes_or;
    ll primes;
    scanf("%lld",&tes);
    for(ll i=1; i<=tes; i++)
    {
        scanf("%lld%lld",&m,&n);
        m_fac.clear();
        fac.clear();
        num=m;
        sq=sqrt(num);
        number=num;
        for(ll j=0; prime[j]<=sq; j++)
        {
            if(number%prime[j]==0)
            {
                count1=0;
                while(number%prime[j]==0)
                {
                    number/=prime[j];
                    count1++;
                }
                m_fac.push_back(make_pair(prime[j],count1));
            }
        }
        if(number!=1)
        {
            m_fac.push_back(make_pair(number,1));
        }
        ll minimum=LLONG_MAX;
        fac_number=n;
        for(ll j=0; j<m_fac.size(); j++)
        {
            primes_or=m_fac[j].first;
            primes=primes_or;
            count1=0;
            while((long long)(fac_number/primes)>0)
            {
                count1+=(long long)(fac_number/primes);
                primes*=primes_or;
            }
            count2=(long long)(count1/m_fac[j].second);
            minimum=min(minimum,count2);
        }
        if(minimum==0)
        {
            printf("Case %lld:\n",i);
            printf("Impossible to divide\n");
        }
        else
        {
            printf("Case %lld:\n",i);
            printf("%lld\n",minimum);
        }
    }
    return 0;
}
