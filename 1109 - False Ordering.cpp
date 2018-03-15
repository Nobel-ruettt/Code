#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxi 40
ll status[maxi+10];
vector<ll>prime;
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
            prime.push_back(i);
            cout<<i<<" ";
        }
    }
}
int main()
{
    sieve();
    return 0;
}
