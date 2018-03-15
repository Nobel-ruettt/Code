#include <bits/stdc++.h>
using namespace std;
#define ll long long
string s;
int main()
{
    cin>>s;
    for(ll i=1;i<s.size();i++)
    {
        if(s[i]==s[i-1])
        {
            cout<<"impossible"<<endl;
            return 0;
        }
    }
    char dublicate,now;
    for(ll i=0;i<s.size();i++)
    {
        now=s[i];
        for(ll j=0;j<s.size();j++)
        {
            if(s[j]==now&&i!=j)
            {
                dublicate=now;
            }
        }
    }
    ll count1=0;
    string s1="";
    char stop;
    for(ll i=0;i<s.size();i++)
    {
        if(s[i]==dublicate)
        {
            if(count1==0)
            {
                s1+=s[i];
                count1++;
            }
            else if(count1==1)
            {
                stop=s[i-1];
                continue;
            }
        }
        else
        {
            s1+=s[i];
        }
    }
    string s2="";
    for(ll i=0;i<13;i++)
    {
        s2+=s1[i];
    }
    string s3="";
    for(ll i=13;i<s1.size();i++)
    {
        s3+=s1[i];
    }
    reverse(s3.begin(),s3.end());
//    cout<<s2<<endl<<s3<<endl<<stop<<endl;;
    while(1)
    {
        ll dub_in=-5;
        ll stop_in=-10;
        for(ll i=0;i<s2.size();i++)
        {
            if(s2[i]==stop)
            {
                stop_in=i;
            }
        }
        for(ll i=0;i<s3.size();i++)
        {
            if(s3[i]==dublicate)
            {
                dub_in=i;
            }
        }
        if(labs(stop_in-dub_in)==0||labs(stop_in-dub_in)==1)
        {
            cout<<s2<<endl<<s3<<endl;
            break;
        }
        else
        {
            string s4,s5;
            s4="";
            s5="";
            s4+=s3[0];
            for(ll i=0;i<s2.size()-1;i++)
            {
                s4+=s2[i];
            }
            for(ll i=1;i<s3.size();i++)
            {
                s5+=s3[i];
            }
            s5+=s2[s2.size()-1];
            s2=s4;
            s3=s5;
        }
    }
    return 0;
}
