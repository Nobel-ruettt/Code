#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll gcd(ll m, ll n)
{
    ll r = m%n;
    while (r)
    {
        m = n;
        n = r;
        r = m%n;
    }
    return n;
}
int main()
{
    string s;
    ll n,cases=1;
    ll number1,number2,digits,nominator,niche1,niche2,dinominator,gc;
    while(scanf("%lld",&n)==1)
    {
        if(n==-1)
        {
            break;
        }
        cin>>s;
        number1=0;
        for(ll i=2; i<s.size(); i++)
        {
            number1=number1*10+(s[i]-'0');
        }
        //cout<<number1<<endl;
        number2=0;
        for(ll i=2; i<=((s.size()-1)-n); i++)
        {
            number2=number2*10+(s[i]-'0');
        }
        //cout<<number2<<endl;
        nominator=number1-number2;
        niche1=1;
        for(ll i=1; i<=(s.size()-2); i++)
        {
            niche1*=10;
        }
        niche2=1;
        for(ll i=1; i<=(s.size()-2-n); i++)
        {
            niche2*=10;
        }
        dinominator=niche1-niche2;
        if(nominator==0)
        {
            printf("Case %lld: %lld/1\n",cases,nominator);
            cases++;
            continue;
        }
        gc=gcd(nominator,dinominator);
        nominator=nominator/gc;
        dinominator=dinominator/gc;
        printf("Case %lld: %lld/%lld\n",cases,nominator,dinominator);
        cases++;
    }
    return 0;
}
