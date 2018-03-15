#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define max1 50500
int status[max1+3];
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
map<ll,ll>m_prime;
vector<ll>m_big_prime;
void factor_m(ll mi)
{
    ll sq=sqrt(mi);
    ll num=mi;
    ll power;
    for(int i=0;prime[i]<=sq;i++)
    {
        if(num%prime[i]==0)
        {
            power=0;
            while(num%prime[i]==0)
            {
                power++;
                num/=prime[i];
            }
            m_prime[prime[i]]=power;
        }
    }
    if(num>1)
    {
         m_big_prime.push_back(num);
    }
}
ll n_prime[max1+3];
void factor_n(ll n)
{
    ll num,primes,power;
    for(ll i=0;prime[i]<=n && i<prime.size();i++)
    {
        primes=prime[i];
        power=0;
        while((long long)(n/primes)>0)
        {
             power+=(long  long)(n/primes);
             primes*=prime[i];
        }
        n_prime[prime[i]]=power;
    }
}
int main()
{
    sieve();
    ll m,n,falsee;
    while(scanf("%lld%lld",&n,&m)!=EOF)
    {
        if(n==0 || n==1)
        {
            if(m==1)
            {
                printf("%lld divides %lld!\n",m,n);
               continue;
            }
            else if(m>1)
            {
                printf("%lld does not divide %lld!\n",m,n);
                continue;
            }
        }
        if(m==1)
        {
            printf("%lld divides %lld!\n",m,n);
            continue;
        }
        if(m==0)
        {
              printf("%lld does not divide %lld!\n",m,n);
            continue;
        }
        factor_m(m);
        factor_n(n);
        falsee=0;
        map<ll,ll>:: iterator it;
        for(it=m_prime.begin();it!=m_prime.end();it++)
        {
            if(n_prime[it->first]<it->second)
            {
                falsee=1;
                break;
            }
        }
        if(falsee==1)
        {
            printf("%lld does not divide %lld!\n",m,n);
        }
        else if(falsee==0)
        {
            if(m_big_prime.size()==0)
            {
                printf("%lld divides %lld!\n",m,n);
            }
            else if(m_big_prime.size()==1)
            {
                if(m_big_prime[0]<=n)
                {
                    printf("%lld divides %lld!\n",m,n);
                }
                else if(m_big_prime[0]>n)
                {
                    printf("%lld does not divide %lld!\n",m,n);
                }
            }
        }
        for(int i=0;i<=max1;i++)
        {
            n_prime[i]=0;
        }
        m_big_prime.clear();
        m_prime.clear();
    }
    return 0;
}
