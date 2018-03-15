#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll p6[25];
void pre()
{
    p6[0]=1;
    for(ll i=1; i<25; i++)
    {
        p6[i]=p6[i-1]*6;
    }
}
ll n,x;
ll dp[30][200];
ll solve(ll pos,ll count1)
{
    if(pos>n)
    {
        if(count1<x)
        {
            return 0;
        }
        else
        {
            return 1;
        }
    }
    if(dp[pos][count1]!=-1)
    {
        return dp[pos][count1];
    }
    ll sum=0;
    sum+=solve(pos+1,count1+1);
    sum+=solve(pos+1,count1+2);
    sum+=solve(pos+1,count1+3);
    sum+=solve(pos+1,count1+4);
    sum+=solve(pos+1,count1+5);
    sum+=solve(pos+1,count1+6);
    return dp[pos][count1]=sum;
}
int main()
{
    pre();
    ll tes;
    scanf("%lld",&tes);
    for(ll cas=1; cas<=tes; cas++)
    {
        scanf("%lld%lld",&n,&x);
        cout << "Case " <<cas<< ": ";
        memset(dp,-1,sizeof dp);
        ll upore=solve(1,0);
        ll niche=p6[n];
        ll g = __gcd(upore,niche);
        if (upore % niche == 0)
            cout << upore / niche << endl;
        else
            cout << upore / g << "/" <<  niche / g << endl;
    }
    return 0;
}
