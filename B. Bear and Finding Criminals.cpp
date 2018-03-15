#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll arr[103];
int main()
{
    ll n,a;
    scanf("%lld%lld",&n,&a);
    for(ll i=1;i<=n;i++)
    {
        scanf("%lld",&arr[i]);
    }
    ll left_pointer=a;
    ll right_pointer=a;
    ll tot=0;
    while(1)
    {
        if(left_pointer<1 || right_pointer >n)
        {
            break;
        }
        if(arr[left_pointer]==1 && arr[right_pointer]==1)
        {
            if(left_pointer!=right_pointer)
            {
               tot+=2;
            }
            else
            {
                tot++;
            }
        }
        left_pointer--;
        right_pointer++;
    }
    if(left_pointer==0 && right_pointer>n)
    {
        cout<<tot<<endl;
        return 0;
    }
    if(left_pointer==0 && right_pointer<=n)
    {
        for(ll i=right_pointer;i<=n;i++)
        {
            if(arr[i]==1)
            {
                tot++;
            }
        }
        cout<<tot<<endl;
        return 0;
    }
    else if(left_pointer>0 && right_pointer>n)
    {
        for(ll i=1;i<=left_pointer;i++)
        {
            if(arr[i]==1)
            {
                tot++;
            }
        }
        cout<<tot<<endl;
        return 0;
    }
    return 0;
}
