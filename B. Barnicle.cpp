#include <bits/stdc++.h>
using namespace std;
#define ll long long
string s;
int main()
{
    cin>>s;
    ll i;
    for(i=0;i<s.size();i++)
    {
        if(s[i]=='e')
        {
            break;
        }
    }
    ll power=0;
    for(ll j=i+1;j<s.size();j++)
    {
        power=(power*10)+(s[j]-'0');
    }
    ll number_after_point=0;
    for(i=0;i<s.size();i++)
    {
        if(s[i]=='.')
        {
            break;
        }
    }
    for(ll j=i+1;j<s.size();j++)
    {
        if(s[j]=='e')
        {
            break;
        }
        number_after_point++;
    }
    if(power==0)
    {
        for(ll i=0;i<s.size();i++)
        {
            if(s[i]=='e')
            {
                break;
            }
            cout<<s[i];
        }
        return 0;
    }
    else
    {
        if(number_after_point==power)
        {
            for(i=0;i<s.size();i++)
            {
                if(s[i]=='.')
                {
                    continue;
                }
                if(s[i]=='e')
                {
                    break;
                }
                cout<<s[i];
            }
            return 0;
        }
        if(number_after_point>power)
        {
            ll j;
            cout<<s[0];
            for(i=2,j=1;i<s.size()&&j<=power;i++,j++)
            {
                cout<<s[i];
            }
            cout<<".";
            for(i=i;i<s.size();i++)
            {
                if(s[i]=='e')
                {
                    break;
                }
                cout<<s[i];
            }
            return 0;
        }
        if(number_after_point<power)
        {
            ll zero=power-number_after_point;
            for(i=0;i<s.size()&&s[i]!='e';i++)
            {
                if(s[i]=='.')
                {
                    continue;
                }
                cout<<s[i];
            }
            for(ll i=1;i<=zero;i++)
            {
                cout<<"0";
            }
            return 0;
        }
    }
    return 0;
}
