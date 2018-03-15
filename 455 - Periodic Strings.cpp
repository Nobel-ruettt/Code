#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll lps[110];
ll n,check,count1;
string txt,pattern;
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
void KMPSearch()
{
    int i = 0;
    int j  = 0;
    while (i < txt.size())
    {
        if (pattern[j] == txt[i])
        {
            j++;
            i++;
        }
        if (j == pattern.size())
        {
            count1++;
            j = lps[j-1];
        }
        else if (i < txt.size() && pattern[j] != txt[i])
        {
            if (j != 0)
                j = lps[j-1];
            else
                i = i+1;
        }
    }
}
int main()
{
    scanf("%lld",&n);
    for(ll cas=1;cas<=n;cas++)
    {
        check=0;
        cin>>txt;
        pattern.clear();
        for(ll i=0;i<=(ll)((txt.size()-1)/2);i++)
        {
            count1=0;
            pattern.push_back(txt[i]);
            computeLPSArray();
            KMPSearch();
            if(count1*pattern.size()==txt.size())
            {
                check=1;
                cout<<pattern.size()<<endl;
                break;
            }
        }
        if(check==0)
        {
            cout<<txt.size()<<endl;
        }
        cout<<endl;
    }
    return 0;
}
