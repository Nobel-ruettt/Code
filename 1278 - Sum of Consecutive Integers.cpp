#include <bits/stdc++.h>
using namespace std;
#define maxx 10000007
#define ll long long
bitset<maxx/2>vis;
vector<int>prime;
void sieve()
{
    int x=maxx/2, y=sqrt(maxx)/2;
    for(int i=1; i<=y; i++)
    {
        if(vis[i]==0)
        {
            for(int j=(i*(i+1)*2); j<x; j+=(2*i)+1)
                vis[j]=1;
        }
    }
    prime.push_back(2);
    for(int i=3; i<maxx; i+=2)
        if(vis[i/2]==0)
            prime.push_back(i);
}
ll tes,n,ans;
void primeFactorize()
{
    ll i;
    ans=1;
    ll root=sqrt(n);
    for(i = 0; i<prime.size()&&prime[i]<=root; i++ )
    {
        if( n % prime[i] == 0 )
        {
            int count1=0;
            while( n % prime[i] == 0 )
            {
                n /= prime[i];
                count1++;
            }
            if(i>0)
            {
                ans*=(count1+1);
            }
            root=sqrt(n);
        }
    }
    if( n > 1 )
    {
        if(n>2)
        {
            ans*=2;
        }
    }
    ans--;
}
int main()
{
    sieve();
    scanf("%lld",&tes);
    for(ll cas=1; cas<=tes; cas++)
    {
        scanf("%lld",&n);
        primeFactorize();
        printf("Case %lld: %lld\n",cas,ans);
    }
    return 0;
}
