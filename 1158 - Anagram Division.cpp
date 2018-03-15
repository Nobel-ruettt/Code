#include <bits/stdc++.h>
using namespace std;
#define ll int
ll Set(ll N,ll pos){return N=N | (1<<pos);}
ll reset(ll N,ll pos){return N= N & ~(1<<pos);}
bool check(ll N,ll pos){return (bool)(N & (1<<pos));}
string s;
ll divisor;
ll num_arr[22];
ll ase[12];
ll maxi;
ll dp[1<<10][1001];
ll fac[12];
void pre()
{
    fac[0]=1;
    for(ll i=1;i<=10;i++)
    {
        fac[i]=fac[i-1]*i;
    }
}
void convert()
{
    memset(ase,0,sizeof ase);
    for(ll i=0; i<s.size(); i++)
    {
        num_arr[i]=s[i]-48;
        ase[num_arr[i]]++;
    }
    maxi=(1<<s.size())-1;
}
ll solve(ll mask,ll remainder)
{
    if(mask==maxi)
    {
        if(remainder==0)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    if(dp[mask][remainder]!=-1)
    {
        return dp[mask][remainder];
    }
    ll sum=0;
    for(ll i=0;i<s.size();i++)
    {
        if(check(mask,i)==0)
        {
            ll mask2=mask;
            sum+=solve(Set(mask2,i),(remainder*10+num_arr[i])%divisor);
        }
    }
    return dp[mask][remainder]=sum;
}
int main()
{
    pre();
    ll tes;
    scanf("%lld",&tes);
    for(ll cas=1; cas<=tes; cas++)
    {
        cin>>s>>divisor;
        convert();
        memset(dp,-1,sizeof dp);
        ll ans=solve(0,0);
        ll niche=1;
        for(ll i=0;i<=9;i++)
        {
            niche=niche*fac[ase[i]];
        }
        printf("Case %d: %d\n",cas,ans/niche);
    }
    return 0;
}
