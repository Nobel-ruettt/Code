#include <bits/stdc++.h>
using namespace std;
#define ll long long
string str,s;
ll count1[30];
vector<char>pref[110];
void cle()
{
    for(ll i=0; i<30; i++)
    {
        count1[i]=0;
    }
    for(ll i=0; i<110; i++)
    {
        pref[i].clear();
    }
}
void making_count()
{
    for(ll i=0; i<str.size(); i++)
    {
        ll askii=str[i]-'a';
        count1[askii]++;
    }
}
void making_preference_list()
{
    for(ll i=1; i<=str.size(); i++)
    {
        cin>>s;
        for(ll j=0; j<s.size(); j++)
        {
            pref[i].push_back(s[j]);
        }
        sort(pref[i].begin(),pref[i].end());
    }
}
string solve(ll row)
{
    if(row==str.size()+1)
    {
        return "";
    }
    string ans="";
    for(ll i=0;i<pref[row].size();i++)
    {
        ll askii=pref[row][i]-'a';
        if(count1[askii]>0)
        {
            count1[askii]--;
            string now_ans;
            now_ans.push_back(pref[row][i]);
            now_ans+=solve(row+1);
            if(now_ans.size()==(str.size()-row+1))
            {
                ans=now_ans;
                return ans;
            }
            count1[askii]++;
        }
    }
    return ans;
}
int main()
{
    ll tes;
    scanf("%lld",&tes);
    for(ll cas=1; cas<=tes; cas++)
    {
        cle();
        cin>>str;
        making_count();
        making_preference_list();
        string ans=solve(1);
        if(ans.size()==str.size())
        {
            cout<<ans<<endl;
        }
        else
        {
            cout<<"NO SOLUTION"<<endl;
        }
    }
    return 0;
}
