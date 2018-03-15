#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll gcd(ll a, ll b)
{
    return (b != 0)? gcd(b, a % b): a;
}
int main()
{
    ll tes,cor_r1,cor_c1,cor_r2,cor_c2,y,x,ans;
    scanf("%lld",&tes);
    for(ll i=1;i<=tes;i++)
    {
        scanf("%lld%lld%lld%lld",&cor_r1,&cor_c1,&cor_r2,&cor_c2);
        if(cor_c2<cor_c1)
        {
            swap(cor_r1,cor_r2);
            swap(cor_c1,cor_c2);
        }
        y=labs(cor_c2-cor_c1);
        x=labs(cor_r2-cor_r1);
        ans=gcd(x,y);
        ans++;
        printf("Case %lld: %lld\n",i,ans);
    }
    return 0;
}
