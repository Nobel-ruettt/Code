#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxi 47000
ll status[maxi+10];
vector<ll>prime;
vector<pair<ll,ll> >fac[110];
vector<pair<ll,ll> >giv_num;
ll facc,n;
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
void pre()
{
    ll num,prime_number,count1;
    fac[1].push_back(make_pair(1,1));
    fac[2].push_back(make_pair(2,1));
    for(ll i=3;i<=100;i++)
    {
        num=i;
        for(ll j=0;prime[j]<=num;j++)
        {
            prime_number=prime[j];
            count1=0;
            while((long long)(num/prime_number)>0)
            {
                count1+=(long long)(num/prime_number);
                prime_number*=prime[j];
            }
            fac[num].push_back(make_pair(prime[j],count1));
        }
    }
}
void given_num_fac()
{
    giv_num.clear();
    ll num=n;
    ll count1;
    ll sq=(long long)sqrt(num);
    for(ll i=0;prime[i]<=sq;i++)
    {
        if(num%prime[i]==0)
        {
            count1=0;
            while(num%prime[i]==0)
            {
                num/=prime[i];
                count1++;
            }
            giv_num.push_back(make_pair(prime[i],count1));
        }
    }
    if(num!=1)
    {
        giv_num.push_back(make_pair(num,1));
    }
}
void sol()
{
    ll num_now_prime,num_now_prime_pow,falsee,mul=1;
    for(ll i=0;i<giv_num.size();i++)
    {
        num_now_prime=giv_num[i].first;
        num_now_prime_pow=giv_num[i].second;
        falsee=0;
        for(ll j=0;j<fac[facc].size();j++)
        {
            if(fac[facc][j].first==num_now_prime)
            {
                if(fac[facc][j].second>=num_now_prime_pow)
                {
                    mul*=(fac[facc][j].second+1-num_now_prime_pow);
                    fac[facc][j].second=0;
                    falsee=1;
                }
            }
        }
        if(falsee==0)
        {
            break;
        }
    }
    if(falsee==0)
    {
        printf("0\n");
        return;
    }
    for(ll j=0;j<fac[facc].size();j++)
    {
        if(fac[facc][j].second!=0)
        {
            mul*=fac[facc][j].second+1;
        }
    }
    printf("%lld\n",mul);
}
int main()
{
    sieve();
    pre();
    while(scanf("%lld%lld",&facc,&n)==2)
    {
        if(facc==0 && n==0)
        {
            break;
        }
        if(facc==1 && n==1)
        {
            printf("1\n");
            continue;
        }
        else if(facc==1 && n>1)
        {
            printf("0\n");
            continue;
        }
        given_num_fac();
        sol();
    }
    return 0;
}
