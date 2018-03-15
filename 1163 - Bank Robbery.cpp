#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll tes;
    scanf("%lld",&tes);
    for(ll i=1;i<=tes;i++)
    {
        ll n;
        scanf("%lld",&n);
        printf("Case %lld:",i);
        for(ll j=9;j>=0;j--)
        {
            if(((n-j)%9)==0)
            {
                printf(" %lld",n+(n-j)/9);
            }
        }
        printf("\n");
    }
    return 0;
}
