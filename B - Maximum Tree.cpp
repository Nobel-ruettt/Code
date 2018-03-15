#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<ll>sa;
int main()
{
    ll n,d;
    scanf("%lld",&n);
    for(ll i=1;i<=n;i++)
    {
       scanf("%lld",&d);
       sa.push_back(d);
    }
    sort(sa.begin(),sa.end());
    reverse(sa.begin(),sa.end());
    ll sum=1;
    ll prev=sa[0];
    sum+=prev;
    for(ll i=1;i<sa.size();i++)
    {
        sum+=(prev*sa[i]);
        prev*=sa[i];
    }
    cout<<sum<<endl;
    return 0;
}
