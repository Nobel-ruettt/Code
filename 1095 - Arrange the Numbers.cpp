#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
#define MAX 1010
ll fact[MAX];
void pre()
{
    for(ll i=0; i<MAX; i++)
    {
        if(i==0)
        {
            fact[i]=1;
        }
        else if(i==1)
        {
            fact[i]=1;
        }
        else
        {
            fact[i]=((i%mod)*(fact[i-1]%mod))%mod;
        }
    }
}
ll n,m,k;
ll extend_gcd(ll a,ll b,ll & x,ll & y)
{
    ll d=a;
    if(b!=0)
    {
        d=extend_gcd(b,a%b,y,x);
        y-=(a/b)*x;
    }
    else
    {
        x=1;
        y=0;
    }
    return d;
}
ll ncr(ll n,ll r)
{
    ll upore,niche;
    upore=fact[n]%mod;
    niche=((fact[r]%mod)*(fact[n-r]%mod))%mod;
    ll k1,k2;
    ll gcd=extend_gcd(niche,mod,k1,k2);
    while(k1 < 0)
    {
        k1+=mod;
    }
    k1%=mod;
    ll ans=((upore%mod)*(k1%mod))%mod;
    return ans;
}
int main()
{
    pre();
    ll tes;
    scanf("%lld",&tes);
    for(ll cas=1;cas<=tes;cas++)
    {
        scanf("%lld%lld%lld",&n,&m,&k);
        if(m==k)
        {
            printf("Case %lld: %lld\n",cas,fact[n-k]);
            continue;
        }
        ll ans=ncr(m,k);
        ll ans2=fact[(n-k)]%mod;
        ll ans3=0;
        ll upor_ncr=(m-k);
        ll niche_ncr=1;
        ll sathe_gun=n-k-1;
        ll count1=1;
        while(1)
        {
            if(count1%2==1)
            {
                //cout<<count1<<endl;
                ll now_gun1=ncr(upor_ncr,niche_ncr);
                //cout<<now_gun1<<endl;
                ll now_gun2=fact[sathe_gun];
                //cout<<now_gun2<<endl;
                ll now_gun=((now_gun1%mod)*(now_gun2%mod))%mod;
                //cout<<now_gun<<endl;
                ans3=((ans3%mod)+(now_gun%mod))%mod;
                //cout<<ans3<<endl<<endl;
            }
            else if(count1%2==0)
            {
                //cout<<count1<<endl;
                ll now_gun1=ncr(upor_ncr,niche_ncr);
                //cout<<now_gun1<<endl;
                ll now_gun2=fact[sathe_gun];
                ///cout<<now_gun2<<endl;
                ll now_gun=((now_gun1%mod)*(now_gun2%mod))%mod;
                ///cout<<now_gun<<endl;
                ans3=((ans3%mod)-(now_gun%mod));
                if(ans3<0)
                {
                    while(ans3<0)
                    {
                        ans3+=mod;
                    }
                    ans3=ans3%mod;
                }
                ///cout<<ans3<<endl<<endl;
            }
            if(upor_ncr==niche_ncr)
            {
                break;
            }
            niche_ncr++;
            sathe_gun--;
            count1++;
        }
        ///cout<<ans3<<endl;
        ll real_ans=((ans2%mod)-(ans3%mod));
        if(real_ans<0)
        {
            while(real_ans<0)
            {
                real_ans+=mod;
            }
            real_ans=real_ans%mod;
        }
        ans=((ans%mod)*(real_ans%mod))%mod;
        printf("Case %lld: %lld\n",cas,ans);
    }
    return 0;
}
