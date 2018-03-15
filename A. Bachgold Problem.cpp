#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll n;
    cin>>n;
    ll t;
    t=n/2;
    cout<<t<<endl;
    if(n%2==1)t--;
    for(ll i=1;i<=t;i++)
    {
        printf("2 ");
    }
    if(n%2==1)
    {
        printf("3\n");
    }
    return 0;
}
