#include <bits/stdc++.h>
using namespace std;
#define ll long long
string s;
ll dp[60][10][10];
ll solve(ll pos,ll vowel_count,ll consonant_count)
{
    if(dp[pos][vowel_count][consonant_count]!=-1)
    {
        return dp[pos][vowel_count][consonant_count];
    }
    if(pos==s.size())
    {
        if(vowel_count<3 && consonant_count <5)
        {
            return 1;
        }
        else
        {
            return 2;
        }
    }
    if(vowel_count==3 || consonant_count ==5)
    {
        return dp[pos][vowel_count][consonant_count]=2;
    }
    if(s[pos]=='?')
    {
        ll ans1=solve(pos+1,0,consonant_count+1);
        ll ans2=solve(pos+1,vowel_count+1,0);
        if(ans1==1 && ans2==1)
        {
            return dp[pos][vowel_count][consonant_count]=1;
        }
        if(ans1==2 && ans2==2)
        {
            return dp[pos][vowel_count][consonant_count]=2;
        }
        if(ans1==1 && ans2==2)
        {
            return dp[pos][vowel_count][consonant_count]=3;
        }
        if(ans1==2 && ans2==1)
        {
            return dp[pos][vowel_count][consonant_count]=3;
        }
        if(ans1==3 || ans2==3)
        {
            return dp[pos][vowel_count][consonant_count]=3;
        }
    }
    if(s[pos]!='?')
    {
        if(s[pos]=='A' || s[pos]=='E' || s[pos]=='I' || s[pos]=='O' || s[pos]=='U')
        {
            return dp[pos][vowel_count][consonant_count]=solve(pos+1,vowel_count+1,0);
        }
        else
        {
            return dp[pos][vowel_count][consonant_count]=solve(pos+1,0,consonant_count+1);
        }
    }
}
int main()
{
    ll tes;
    scanf("%lld",&tes);
    for(ll cas=1;cas<=tes;cas++)
    {
        cin>>s;
        memset(dp,-1,sizeof(dp));
        ll ans=solve(0,0,0);
        if(ans==3)
        {
            printf("Case %lld: MIXED\n",cas);
        }
        else if(ans==2)
        {
            printf("Case %lld: BAD\n",cas);
        }
        else if(ans==1)
        {
            printf("Case %lld: GOOD\n",cas);
        }
    }
    return 0;
}
