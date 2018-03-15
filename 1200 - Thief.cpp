#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll dp[11000];
struct node
{
    ll weight;
    ll price;
    ll lagbe;
    bool operator<(const node &p)const
    {

        return p.weight>weight;
    }


} main_arr[110];
ll n,make,tot_weight,p,l,w;
void pre()
{
    for(ll i=0;i<11000;i++)
    {
        dp[i]=0;
    }
}
int main()
{
    ll tes;
    scanf("%lld",&tes);
    for(ll cas=1; cas<=tes; cas++)
    {
        scanf("%lld%lld",&n,&tot_weight);
        pre();
        ll weight_lagbe=0;
        for(ll i=1; i<=n; i++)
        {
            scanf("%lld%lld%lld",&p,&l,&w);
            main_arr[i].price=p;
            main_arr[i].weight=w;
            main_arr[i].lagbe=l;
            weight_lagbe+=(l*w);
        }
        if(weight_lagbe>tot_weight)
        {
            printf("Case %lld: Impossible\n",cas);
            continue;
        }
        ll weight_baki_ase=tot_weight-weight_lagbe;
        if(weight_baki_ase==0)
        {
            printf("Case %lld: 0\n",cas);
            continue;
        }
        make=weight_baki_ase;
        sort(main_arr+1,main_arr+1+n);
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<=make;j++)
            {
                if(main_arr[i].weight>j)
                {
                    dp[j]=dp[j];
                }
                else
                {
                    dp[j]=max(dp[j],main_arr[i].price+dp[j-main_arr[i].weight]);
                }
            }
        }
        printf("Case %lld: %lld\n",cas,dp[make]);
    }
    return 0;
}
