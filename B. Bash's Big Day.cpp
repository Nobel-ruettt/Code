#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxii 100005
#define maxi 400
bool status[maxi];
vector<ll>primes;
void sieve()
{
    for(ll i=2;i<maxi;i++)
    {
        if(status[i]==0)
        {
            for(ll j=i*2;j<maxi;j+=i)
            {
                status[j]=1;
            }
        }
    }
    for(ll i=2;i<maxi;i++)
    {
        if(status[i]==0)
        {
            primes.push_back(i);
           /// cout<<i<<endl;
        }
    }
}
ll numbers[maxii];
int main()
{
    sieve();
    ll n,maximum=0;
    scanf("%lld",&n);
    for(ll i=0;i<n;i++)
    {
        scanf("%lld",&numbers[i]);
    }
    ll now_prime;
    for(ll i=0;i<primes.size();i++)
    {
        now_prime=primes[i];
        ll tot=0;
        for(ll i=0;i<n;i++)
        {
            if(numbers[i]%now_prime==0)
            {
                tot++;
            }
        }
        if(tot>maximum)
        {
            maximum=tot;
        }
    }
    cout<<maximum<<endl;
    return 0;
}
