#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll arr[1000000];
int main()
{
    ll n,k;
    cin>>n>>k;
    for(ll i=1;i<=n;i++)
    {
        scanf("%lld",&arr[i]);
    }
    ll sum=0;
    for(ll i=1;i<=n;i++)
    {
        sum+=arr[i];
        if(sum<8)
        {
            k-=sum;
            sum=0;
            if(k<=0)
            {
                cout<<i<<endl;
                return 0;
            }
        }
        else if(sum>=8)
        {
            k-=8;
            sum-=8;
            if(k<=0)
            {
                cout<<i<<endl;
                return 0;
            }
        }
    }
    cout<<"-1"<<endl;
    return 0;
}
