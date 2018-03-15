#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxi 46350
vector<ll>segment_prime;
vector<ll>sq_prime;
bool status[maxi];
void normal_sieve()
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
            sq_prime.push_back(i);
        }
    }
}
void segmentedsieve(ll lower,ll upper)
{
    ll limit=upper-lower+2;
    bool mark[limit+1];
    memset(mark,true,sizeof(mark));
    ll upper_prime=floor(sqrt(upper));
    ///cout<<upper_prime<<endl;
    for(ll i=0;i<sq_prime.size()&&sq_prime[i]<=upper_prime;i++)
    {
        ll now_prime=sq_prime[i];
        ll lower_limit_in_range=floor(lower/now_prime)*now_prime;
        if(lower_limit_in_range<lower)
        {
            lower_limit_in_range+=now_prime;
        }
        if(lower_limit_in_range==now_prime)
        {
            lower_limit_in_range+=now_prime;
        }
        for(ll j=lower_limit_in_range;j<upper;j+=now_prime)
        {
            mark[j-lower]=false;
        }
    }
    if(lower==1)
    {
        mark[1-lower]=false;
    }
    for(ll i=lower;i<upper;i++)
    {
        if(mark[i-lower]==1)
        {
            segment_prime.push_back(i);
        }
    }
//    for(ll i=0;i<segment_prime.size();i++)
//    {
//        cout<<segment_prime[i]<<endl;
//    }
}
int main()
{
    normal_sieve();
    ll tes,left,right;
    scanf("%lld",&tes);
    for(ll i=1; i<=tes; i++)
    {
        scanf("%lld%lld",&left,&right);
        segment_prime.clear();
        segmentedsieve(left,right+1);
        printf("Case %lld: %d\n",i,segment_prime.size());
    }
    return 0;
}
