#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll arr[200005];
int main()
{
    ll n;
    cin>>n;
    for(ll i=0;i<n;i++)
    {
        scanf("%lld",&arr[i]);
    }
    arr[n]=0;
    for(ll i=0;i<n;i++)
    {
        if(arr[i]%2==0)
        {
            continue;
        }
        else if(arr[i]%2==1)
        {
            arr[i+1]--;
        }
        else if(arr[i]<0)
        {
            cout<<"NO"<<endl;
            break;
        }
    }
    if(arr[n]<0)
    {
        cout<<"NO"<<endl;
    }
    else
    {
        cout<<"YES"<<endl;
    }
    return 0;
}
