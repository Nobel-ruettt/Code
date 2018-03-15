#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<ll>dii;
vector<ll>digits;
vector<ll>new_digits;
int main()
{
    string num;
    ll mod;
    ll high_dig;
    while(cin>>num)
    {
        if(num[0]=='-')
        {
            break;
        }
        else if(num[1]=='\0')
        {
            cout<<"1"<<num[0]<<endl;
            continue;
        }
        digits.clear();
        dii.clear();
        new_digits.clear();
        for(ll i=0; i<num.size(); i++)
        {
            digits.push_back((num[i]-'0'));
        }
        for(ll i=9; i>=2; i--)
        {
            high_dig=i;
            while(1)
            {
                mod=0;
                new_digits.clear();
                for(ll j=0; j<digits.size(); j++)
                {
                    mod=mod*10+digits[j];
                    new_digits.push_back((long long)(mod/high_dig));
                    mod=mod%high_dig;
                }
                if(mod==0)
                {
                    dii.push_back(high_dig);
                    digits.clear();
                    ll count1=0;
                    while(new_digits[count1]==0)count1++;
                    for(ll j=count1;j<new_digits.size();j++)
                    {
                        digits.push_back(new_digits[j]);
                    }
                }
                else if(mod!=0)
                {
                    break;
                }
            }
        }
        if(digits.size()==1)
        {
            for(ll i=0;i<dii.size();i++)
            {
                cout<<dii[i];
            }
            cout<<endl;
        }
        else
        {
            cout<<"There is no such number.\n";
        }
    }
    return 0;
}
