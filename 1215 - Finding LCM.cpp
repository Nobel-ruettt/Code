#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxi 1000005
bool status[maxi];
vector<ll>prime;
void sieve()
{
    for(ll i=2; i<maxi; i++)
    {
        if(status[i]==0)
        {
            for(ll j=i*i; j<maxi; j+=i)
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
vector<pair<ll,ll> >primes_of_l;
void factorize_l(ll number)
{
    primes_of_l.clear();
    ll sq=sqrt(number);
    for(ll i=0; prime[i]<=sq; i++)
    {
        if(number%prime[i]==0)
        {
            ll count1=0;
            while(number%prime[i]==0)
            {
                number/=prime[i];
                count1++;
            }
            primes_of_l.push_back(make_pair(prime[i],count1));
        }
    }
    if(number>1)
    {
        primes_of_l.push_back(make_pair(number,1));
    }
}
vector<pair<ll,ll> >primes_of_a;
void factorize_a(ll number)
{
    primes_of_a.clear();
    ll sq=sqrt(number);
    for(ll i=0; prime[i]<=sq; i++)
    {
        if(number%prime[i]==0)
        {
            ll count1=0;
            while(number%prime[i]==0)
            {
                number/=prime[i];
                count1++;
            }
            primes_of_a.push_back(make_pair(prime[i],count1));
        }
    }
    if(number>1)
    {
        primes_of_a.push_back(make_pair(number,1));
    }
}
vector<pair<ll,ll> >primes_of_b;
void factorize_b(ll number)
{
    primes_of_b.clear();
    ll sq=sqrt(number);
    for(ll i=0; prime[i]<=sq; i++)
    {
        if(number%prime[i]==0)
        {
            ll count1=0;
            while(number%prime[i]==0)
            {
                number/=prime[i];
                count1++;
            }
            primes_of_b.push_back(make_pair(prime[i],count1));
        }
    }
    if(number>1)
    {
        primes_of_b.push_back(make_pair(number,1));
    }
}
vector<pair<ll,ll> >lagbe;
ll binary_search_a(ll prime)
{
    ll low=0;
    ll high=primes_of_a.size()-1;
    ll ans=-1;
    while(low<=high)
    {
        ll mid=(low+high)/2;
        if(primes_of_a[mid].first==prime)
        {
            ans=primes_of_a[mid].second;
            break;
        }
        else if(primes_of_a[mid].first>prime)
        {
            high=mid-1;
        }
        else
        {
            low=mid+1;
        }
    }
    return ans;
}
ll binary_search_b(ll prime)
{
    ll low=0;
    ll high=primes_of_b.size()-1;
    ll ans=-1;
    while(low<=high)
    {
        ll mid=(low+high)/2;
        if(primes_of_b[mid].first==prime)
        {
            ans=primes_of_b[mid].second;
            break;
        }
        else if(primes_of_b[mid].first>prime)
        {
            high=mid-1;
        }
        else
        {
            low=mid+1;
        }
    }
    return ans;
}
ll power(ll x,ll y)
{
    ll res = 1;
    while (y > 0)
    {
        // If y is odd, multiply x with result
        if (y & 1)
            res = res*x;

        // n must be even now
        y = y>>1; // y = y/2
        x = x*x;  // Change x to x^2
    }
    return res;
}
ll lagbe_aro()
{
    lagbe.clear();
    for(ll i=0;i<primes_of_l.size();i++)
    {
        ll aro1=binary_search_a(primes_of_l[i].first);
        ll aro2=binary_search_b(primes_of_l[i].first);
        if(max(aro1,aro2)<primes_of_l[i].second)
        {
            lagbe.push_back(primes_of_l[i]);
        }
    }
    ll ans=1;
    for(ll i=0;i<lagbe.size();i++)
    {
        ans*=power(lagbe[i].first,lagbe[i].second);
    }
    return ans;
}
int main()
{
    sieve();
    ll tes,a,b,c,l;
    scanf("%lld",&tes);
    for(ll i=1; i<=tes; i++)
    {
        scanf("%lld%lld%lld",&a,&b,&l);
        if(l%a!=0||l%b!=0)
        {
            printf("Case %lld: impossible\n",i);
            continue;
        }
        factorize_l(l);
        factorize_a(a);
        factorize_b(b);
        ll ans=lagbe_aro();
        printf("Case %lld: %lld\n",i,ans);
    }
    return 0;
}
