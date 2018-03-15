#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll arr[1004],n;
int main()
{
    ll tes;
    scanf("%lld",&tes);
    for(ll cas=1; cas<=tes; cas++)
    {
        scanf("%lld",&n);
        for(ll i=1; i<=n; i++)
        {
            scanf("%lld",&arr[i]);
        }
        ll check=0;
        for(ll i=2; i<=n; i++)
        {
            if(arr[i]!=arr[i-1])
            {
                check=1;
                break;
            }
        }
        if(check==0)
        {
            cout<<"neutral"<<endl;
            continue;
        }
        check=0;
        for(ll i=2; i<=n; i++)
        {
            if(arr[i]<arr[i-1])
            {
                check=1;
                break;
            }
        }
        if(check==0)
        {
            cout<<"allGoodDays"<<endl;
            continue;
        }
        check=0;
        for(ll i=2; i<=n; i++)
        {
            if(arr[i]>arr[i-1])
            {
                check=1;
                break;
            }
        }
        if(check==0)
        {
            cout<<"allBadDays"<<endl;
            continue;
        }
        ll maximum=0;
        ll prev_flag=-1;
        for(ll i=2; i<n; i++)
        {
            if(arr[i]>arr[i-1] && arr[i]>arr[i+1])
            {
                if(prev_flag==-1)
                {
                    prev_flag=i;
                }
                else if(prev_flag!=-1)
                {
                    if((i-prev_flag-1)>maximum)
                    {
                        maximum=i-prev_flag-1;
                    }
                    prev_flag=i;
                }
            }
        }
        if(maximum==0)
        {
            cout<<"none"<<endl;
        }
        else
        {
           cout<<maximum<<endl;
        }
    }
    return 0;
}
