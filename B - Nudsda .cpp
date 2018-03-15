#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxi 500005
ll arr[maxi];
ll cumsum[maxi];
int main()
{
    ll n;
    scanf("%lld",&n);
    ll tot=0;
    for(ll i=1;i<=n;i++)
    {
        scanf("%lld",&arr[i]);
        tot+=arr[i];
    }
    if(tot%3!=0)
    {
        cout<<"0"<<endl;
        return 0;
    }
    cumsum[1]=arr[1];
//    cout<<cumsum[1]<<" ";
    for(ll i=2;i<=n;i++)
    {
        cumsum[i]=cumsum[i-1]+arr[i];
//        cout<<cumsum[i]<<" ";
    }
    ll first=tot/3;
    ll second=first+first;
//    cout<<first<<endl;
    if(first==0)
    {
        ll tot_zero=0;
        for(ll i=1;i<=n;i++)
        {
            if(cumsum[i]==0)
            {
                tot_zero++;
            }
        }
        tot_zero-=2;
        if(tot_zero<0)
        {
            cout<<"0"<<endl;
        }
        else
        {
            cout<<(tot_zero*(tot_zero+1))/2<<endl;
        }
        return 0;
    }
//    cout<<first<<" "<<second<<endl;
    ll first_ase=0;
    ll second_ase=0;
    for(ll i=1;i<n;i++)
    {
        if(cumsum[i]==first)
        {
            first_ase++;
        }
        else if(cumsum[i]==second)
        {
            second_ase++;
        }
    }
    cout<<first_ase*second_ase<<endl;
    return 0;
}
