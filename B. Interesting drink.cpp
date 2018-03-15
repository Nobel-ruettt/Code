#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n,price;
vector<ll>pr;
int main()
{
    scanf("%lld",&n);
    for(ll i=1;i<=n;i++)
    {
        scanf("%lld",&price);
        pr.push_back(price);
    }
    sort(pr.begin(),pr.end());
    ll q;
    scanf("%lld",&q);
    for(ll i=1;i<=q;i++)
    {
        ll now_price;
        scanf("%lld",&now_price);
        if(now_price<pr[0])
        {
            cout<<"0"<<endl;
            continue;
        }
        else if(now_price>pr[pr.size()-1])
        {
            cout<<pr.size()<<endl;
            continue;
        }
        ll low=0;
        ll high=pr.size()-1;
        ll mid;
        while(low<=high)
        {
            mid=(low+high)/2;
            if(pr[mid]<=now_price)
            {
                low=mid+1;
            }
            else
            {
                high=mid-1;
            }
        }
        cout<<high+1<<endl;
    }
    return 0;
}
