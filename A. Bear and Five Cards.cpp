#include <bits/stdc++.h>
using namespace std;
#define ll long long
map<ll,ll>count1;
int main()
{
    ll arr[5];
    ll sum1=0;
    for(ll i=0; i<5; i++)
    {
        scanf("%lld",&arr[i]);
        count1[arr[i]]++;
        sum1+=arr[i];
    }
    ll mini=sum1;
    for(ll i=0; i<5; i++)
    {
        if(count1[arr[i]]>=3)
        {
            if((sum1-(arr[i]*3))<mini)
            {
                mini=sum1-(arr[i]*3);
            }
        }
        else if(count1[arr[i]]==2)
        {
            if((sum1-(arr[i]*2))<mini)
            {
                mini=sum1-(arr[i]*2);
            }
        }
    }
    cout<<mini<<endl;
    return 0;
}
