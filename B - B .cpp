#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define MAXN   100005
ll spf[MAXN];
ll is_on[MAXN];
ll is_fac_on[MAXN];
void sieve()
{
    spf[1] = 1;
    for (ll i=2; i<MAXN; i++)
         spf[i] = i;

    for (ll i=4; i<MAXN; i+=2)
        spf[i] = 2;

    for (ll i=3; i*i<MAXN; i++)
    {
        if (spf[i] == i)
        {
            for (ll j=i*i; j<MAXN; j+=i)
                if (spf[j]==j)
                    spf[j] = i;
        }
    }
}
void getFactorization(ll x,ll type)
{
    if(type==0)
    {
        if(is_on[x]==0)
        {
             cout<<"Already off"<<endl;
             return ;
        }
    }
    if(type==1)
    {
        if(is_on[x]==1)
        {
            cout<<"Already on"<<endl;
            return ;
        }
    }
    set<ll> ret;
    set<ll>:: iterator it;
    ll num=x;
    while (num != 1)
    {
        ret.insert(spf[num]);
        num = num / spf[num];
    }
    if(type==0)
    {
        for(it=ret.begin();it!=ret.end();it++)
        {
            is_fac_on[*it]=0;
        }
        is_on[x]=0;
        cout<<"Success"<<endl;
        return ;
    }
    if(type==1)
    {
        bool flag=0;
        ll ans;
        for(it=ret.begin();it!=ret.end();it++)
        {
            if(is_fac_on[*it]!=0)
            {
                flag=1;
                ans=is_fac_on[*it];
                break;
            }
        }
        if(flag==1)
        {
            printf("Conflict with %lld\n",ans);
            return;
        }
        is_on[x]=1;
        for(it=ret.begin();it!=ret.end();it++)
        {
            is_fac_on[*it]=x;
        }
        cout<<"Success"<<endl;
        return ;
    }
}
ll n,m,d;
char c;
int main()
{
    sieve();
    scanf("%lld%lld",&n,&m);
    for(ll i=1;i<=m;i++)
    {
        scanf(" %c %lld",&c,&d);
        if(c=='-')
        {
           getFactorization(d,0);
        }
        else
        {
            getFactorization(d,1);
        }
    }
    return 0;
}
