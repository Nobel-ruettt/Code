#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll n,tes;
    scanf("%lld",&tes);
    for(ll i=1;i<=tes;i++)
    {
        scanf("%lld",&n);
        printf("Case %lld: %lld\n",i,n/2);
    }
    return 0;
}
