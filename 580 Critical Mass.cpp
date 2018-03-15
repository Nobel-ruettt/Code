#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll fib[35];
void pre()
{
    fib[1]=2;
    fib[2]=4;
    fib[3]=7;
    for(ll i=4;i<=30;i++)
    {
        fib[i]=fib[i-1]+fib[i-2]+fib[i-3];
    }
}
int main()
{
    pre();
    ll n;
    while(cin>>n)
    {
        if(n==0)
        {
            break;
        }
        ll p=1;
        for(ll i=1;i<=n;i++)
        {
            p=p*2;
        }
        printf("%lld\n",p-fib[n]);
    }
    return 0;
}
