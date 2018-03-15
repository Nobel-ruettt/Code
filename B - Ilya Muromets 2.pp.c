#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxi 200005
ll arr1[maxi];
ll cumsum1[maxi];
ll arr2[maxi];
ll cumsum2[maxi];
int main()
{
    ll n,k;
    ll sum=0;
    cumsum1[0]=0;
    scanf("%lld%lld",&n,&k);
    for(ll i=1;i<=n;i++)
    {
        scanf("%lld",&arr1[i]);
        sum+=arr1[i];
        cumsum1[i]=cumsum1[i-1]+arr1[i];
    }
    if(2*k>=n)
    {
        cout<<sum<<endl;
        return 0;
    }
    ll left_pointer=1;
    ll right_pointer=k;
    ll maxi=0;
    ll maxi_left,maxi_right;
    while(right_pointer<=n)
    {
        ll now_sum=cumsum1[right_pointer]-cumsum1[left_pointer-1];
        if(now_sum>maxi)
        {
            maxi=now_sum;
            maxi_left=left_pointer;
            maxi_right=right_pointer;
        }
        left_pointer++;
        right_pointer++;
    }
    ll cumsum2[0]=0;
    ll count1=1;
    for(ll i=1;i<=n;i++)
    {
        if(i>=maxi_left&&i<=maxi_right)
        {
            continue;
        }
        arr2[count1]=arr1[i];
        cumsum2[count1]=cumsum2[count1-1]+arr2[count1];
        count1++;
    }
    ll new_n=count1-1;
    left_pointer=1;
    right_pointer=k;
    ll maxi2=0;
    while(right_pointer<=new_n)
    {
        ll now_sum=cumsum2[right_pointer]-cumsum2[left_pointer-1];
        if(now_sum>maxi2)
        {
            maxi2=now_sum;
            maxi_left=left_pointer;
            maxi_right=right_pointer;
        }
        left_pointer++;
        right_pointer++;
    }
    cout<<maxi1+maxi2<<endl;
    return 0;
}
