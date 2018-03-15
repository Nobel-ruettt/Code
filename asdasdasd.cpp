#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll n;
    while(1)
    {
        cin>>n;
        for(ll i=1;i<=((ll)(n/2));i++)
        {
            cout<<i<<","<<n/i<<"  ";
        }
        cout<<endl;
    }
    return 0;
}
