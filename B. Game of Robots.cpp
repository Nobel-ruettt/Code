#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll cumsum[100005];
ll arr[100005];
int main()
{
    cumsum[0]=0;
    for(ll i=1;i<=100000;i++)
    {
        cumsum[i]=cumsum[i-1]+i;
    }
    ll n,k;
    scanf("%lld%lld",&n,&k);
    for(ll i=1;i<=n;i++)
    {
        scanf("%lld",&arr[i]);
    }
    ll ase,ager;
    for(ll i=1;i<=n;i++)
    {
        if(cumsum[i]>=k)
        {
            ase=i;
            ager=i-1;
            break;
        }
    }
    ll first;
    first=((ager*(ager+1))/2)+1;
    ll tomo=k-first+1;
    cout<<arr[tomo]<<endl;
    return 0;
}
