#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n;
ll digits[100];
vector<ll>digit;
ll dp[100][3][200];
ll dp2[100][3][200][2];
void bin(ll number)
{
    if (number>1)
    {
        bin(number/2);
    }
    digit.push_back(number%2);
}
void make_binary_array()
{
    digits[0]=0;
    for(ll i=1; i<=digit.size(); i++)
    {
        digits[i]=digit[i-1];
    }
}
ll solve0(ll pos,ll now_digit,ll count1)
{
    if(pos==digit.size())
    {
        return count1;
    }
    if(dp[pos][now_digit][count1]!=-1)
    {
        return dp[pos][now_digit][count1];
    }
    if(now_digit==0)
    {
        return dp[pos][now_digit][count1]=solve0(pos+1,0,count1)+solve0(pos+1,1,count1);
    }
    else if(now_digit==1)
    {
        return dp[pos][now_digit][count1]=solve0(pos+1,0,count1)+solve0(pos+1,1,count1+1);
    }
}
ll solve1(ll pos,ll now_digit,ll count1,ll tt)
{
    if(pos==digit.size())
    {
        return count1;
    }
    if(dp2[pos][now_digit][count1][tt]!=-1)
    {
        return dp2[pos][now_digit][count1][tt];
    }
    if(now_digit==1)
    {
        ll sum=0;
        if(digits[pos+1]==1)
        {
            if(tt==1)
            {
               sum+=solve1(pos+1,0,count1,0);
               sum+=solve1(pos+1,1,count1+1,1);
            }
            else if(tt==0)
            {
                sum+=solve1(pos+1,0,count1,0);
                sum+=solve1(pos+1,1,count1+1,0);
            }
        }
        else if(digits[pos+1]==0)
        {
            if(tt==0)
            {
                sum+=solve1(pos+1,0,count1,0);
                sum+=solve1(pos+1,1,count1+1,0);
            }
            else if(tt==1)
            {
                sum+=solve1(pos+1,0,count1,1);
            }
        }
        return dp2[pos][now_digit][count1][tt]=sum;
    }
    else if(now_digit==0)
    {
        ll sum=0;
        if(digits[pos+1]==1)
        {
            if(tt==1)
            {
               sum+=solve1(pos+1,0,count1,0);
               sum+=solve1(pos+1,1,count1,1);
            }
            else if(tt==0)
            {
                sum+=solve1(pos+1,0,count1,0);
                sum+=solve1(pos+1,1,count1,0);
            }
        }
        else if(digits[pos+1]==0)
        {
            if(tt==0)
            {
                sum+=solve1(pos+1,0,count1,0);
                sum+=solve1(pos+1,1,count1,0);
            }
            else if(tt==1)
            {
                sum+=solve1(pos+1,0,count1,1);
            }
        }
        return dp2[pos][now_digit][count1][tt]=sum;
    }
}
int main()
{
    ll tes;
    scanf("%lld",&tes);
    for(ll cas=1; cas<=tes; cas++)
    {
        scanf("%lld",&n);
        digit.clear();
        bin(n);
        make_binary_array();
        memset(dp,-1,sizeof(dp));
        ll ans1=solve0(1,0,0);
        memset(dp2,-1,sizeof(dp));
        ll ans2=solve1(1,1,0,1);
        printf("Case %lld: %lld\n",cas,ans1+ans2);
    }
    return 0;
}
