#include <bits/stdc++.h>
using namespace std;
#define ll long long
map<ll,ll>ase;
vector<ll>num;
int main()
{
    ll n;
    ll count1=0;
    scanf("%lld",&n);
    for(ll i=1;i<=n;i++)
    {
        ll card;
        scanf("%lld",&card);
        if(ase[card]==0)
        {
            num.push_back(card);
        }
        ase[card]++;
    }
    if(num.size()>2 || num.size()<2)
    {
        cout<<"NO"<<endl;
    }
    else
    {
        if(ase[num[0]]==ase[num[1]])
        {
            cout<<"YES"<<endl;
            cout<<num[0]<<" "<<num[1]<<endl;
            return 0;
        }
        else
        {
            cout<<"NO"<<endl;
        }
    }
    return 0;
}
