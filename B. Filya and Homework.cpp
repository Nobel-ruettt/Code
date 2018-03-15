#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxi 100005
ll arr[maxi];
int main()
{
    ll n;
    scanf("%lld",&n);
    ll sum=0;
    for(ll i=1;i<=n;i++)
    {
        scanf("%lld",&arr[i]);
        sum+=arr[i];
    }
    if(sum%n!=0)
    {
        cout<<"NO"<<endl;
    }
    else
    {
        ll bana=sum/n;
        ll dif=0;
        for(ll i=1;i<=n;i++)
        {
//            if((labs(arr[i]-bana))!=dif && arr[i]!=bana)
//            {
//                cout<<"NO"<<endl;
//                return 0;
//            }
              if(arr[i]!=bana)
              {
                  dif=labs(arr[i]-bana);
              }
        }
        for(ll i=1;i<=n;i++)
        {
            if((labs(arr[i]-bana))!=dif && arr[i]!=bana)
            {
                cout<<"NO"<<endl;
                return 0;
            }
//              if(arr[i]!=bana)
//              {
//                  dif=labs(arr[i]-bana);
//              }
        }
        cout<<"YES"<<endl;
    }
    return 0;
}
