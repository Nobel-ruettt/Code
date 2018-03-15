#include <bits/stdc++.h>
using namespace std;
#define ll long long
string s1,s2,pattern;
ll lps[110];
string dp[110][110][110];
bool visited[110][110][110];
void computeLPSArray()
{
    ll len = 0;
    lps[0] = 0;
    ll i = 1;
    while (i < pattern.size())
    {
        if (pattern[i] == pattern[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else
        {
            if (len != 0)
            {
                len = lps[len-1];
            }
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}
string solve(ll pos1,ll pos2,ll pattern_matched)
{
    if(s1[pos1]=='\0' or s2[pos2]=='\0')
    {
        return "";
    }
	if(visited[pos1][pos2][pattern_matched])
    {
        return dp[pos1][pos2][pattern_matched];
    }
    string ans;
    if(s1[pos1]==s2[pos2])
    {
        if(s1[pos1]==pattern[pattern_matched])
        {
            string ans1,ans2,ans3;
            if(pattern_matched+1==pattern.size())
            {
                ans1=solve(pos1+1,pos2+1,pattern_matched);
            }
            else
            {
                ans1.push_back(s1[pos1]);
                ans1+=solve(pos1+1,pos2+1,pattern_matched+1);
            }
            ans2=solve(pos1+1,pos2,pattern_matched);
            ans3=solve(pos1,pos2+1,pattern_matched);
            if(ans1.size()>=ans2.size()&& ans1.size()>=ans3.size())
            {
                ans=ans1;
            }
            else if(ans2.size()>=ans1.size() && ans2.size()>=ans3.size())
            {
                ans=ans3;
            }
            else if(ans3.size()>=ans1.size() && ans3.size()>=ans2.size())
            {
                ans=ans3;
            }
        }
        else
        {
            string ans1,ans2,ans3;
            ll j=lps[pattern_matched-1];
            while(s1[pos1]!=pattern[j] && j!=0)
            {
                j=lps[j-1];
            }
            if(pattern[j]==s1[pos1])
            {
                j++;
            }
            ans1.push_back(s1[pos1]);
            ans1+=solve(pos1+1,pos2+1,j);
            ans2=solve(pos1+1,pos2,pattern_matched);
            ans3=solve(pos1,pos2+1,pattern_matched);
            if(ans1.size()>=ans2.size()&& ans1.size()>=ans3.size())
            {
                ans=ans1;
            }
            else if(ans2.size()>=ans1.size() && ans2.size()>=ans3.size())
            {
                ans=ans3;
            }
            else if(ans3.size()>=ans1.size() && ans3.size()>=ans2.size())
            {
                ans=ans3;
            }
        }
    }
    else
    {
        string ans1=solve(pos1+1,pos2,pattern_matched);
        string ans2=solve(pos1,pos2+1,pattern_matched);
        if(ans1.size()>ans2.size())
        {
            ans=ans1;
        }
        else
        {
            ans=ans2;
        }
    }
    visited[pos1][pos2][pattern_matched]=1;
    return dp[pos1][pos2][pattern_matched]=ans;
}
int main()
{
    cin>>s1;
    cin>>s2;
    cin>>pattern;
    computeLPSArray();
    string ans=solve(0,0,0);
    if(ans.size()==0)
    {
        cout<<"0"<<endl;
    }
    else
    {
        cout<<ans<<endl;
    }
    return 0;
}
