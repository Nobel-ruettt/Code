#include <bits/stdc++.h>
using namespace std;
#define ll long long
string s;
ll n;
int main()
{
    scanf("%lld",&n);
    cin>>s;
//    if(n==1)
//    {
//        cout<<s<<endl;
//        cout<<s<<endl;
//        cout<<s<<endl;
//        return 0;
//    }
    ll sum=0;
    sum+=s[0]-'0';
    cout<<s[0];
    for(ll i=1;i<s.size();i++)
    {
        sum+=s[i]-'0';
        cout<<"+"<<s[i];
    }
    cout<<endl;
     vector<ll>digits;
    ll num2=sum;
    while(num2!=0)
    {
        digits.push_back(num2%10);
        num2/=10;
    }
    sum=0;
    reverse(digits.begin(),digits.end());
    cout<<digits[0];
    sum+=digits[0];
    for(ll i=1;i<digits.size();i++)
    {
        sum+=digits[i];
        cout<<"+"<<digits[i];
    }
    cout<<endl;
//    if(((ll)(sum/10))==0)
//    {
//        cout<<sum<<endl;
//        return 0;
//    }
    digits.clear();
    num2=sum;
    while(num2!=0)
    {
        digits.push_back(num2%10);
        num2/=10;
    }
    sum=0;
    reverse(digits.begin(),digits.end());
    cout<<digits[0];
    sum+=digits[0];
    for(ll i=1;i<digits.size();i++)
    {
        sum+=digits[i];
        cout<<"+"<<digits[i];
    }
    cout<<endl;
    return 0;
}
