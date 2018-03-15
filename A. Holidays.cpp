#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll n;
    scanf("%lld",&n);
    ll maxi=0;
    ll mini=0;
    for(ll i=1;i<=n;i++)
    {
        if(i%7==1 || i%7==2)
        {
            maxi++;
        }
        if(i%7==6 || i%7==0)
        {
            mini++;
        }
    }
    cout<<mini<<" "<<maxi<<endl;
    return 0;
}
