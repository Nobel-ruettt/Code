#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<pair<ll,ll> >number;
ll nim;
ll ncr(ll n,ll r)
{
    ll ans = 1;
    r =min(r, n - r);

    for(ll  j = 1; j <= r; j++, n--)
    {
        if (n % j == 0) {
            ans *= n / j;
        } else if (ans % j == 0) {
            ans = (ans / j) * n;
        } else {
            ans = (ans * n) / j;
        }
    }
    return ans;
}
int main()
{
    ll n;
    scanf("%lld",&n);
    for(ll i=0;i<n;i++)
    {
        scanf("%lld",&nim);
        number.push_back(make_pair(nim,i));
    }
    sort(number.begin(),number.end());
    ll mini=number[0].first;
    ll count1=0;
    for(ll i=0;i<number.size();i++)
    {
        if(number[i].first==mini)
        {
            count1++;
        }
    }
    if(count1>=3)
    {
        ll ans=ncr(count1,3);
        cout<<ans<<endl;
        return 0;
    }
    else if(count1==2)
    {
        ll count2=0;
        ll second_mini=number[2].first;
        for(ll i=0;i<number.size();i++)
        {
            if(number[i].first==second_mini)
            {
                count2++;
            }
        }
        ll ans=ncr(count2,1);
        cout<<ans<<endl;
        return 0;
    }
    else if(count1==1)
    {
        if(number[1].first==number[2].first)
        {
            ll count2=0;
            for(ll i=1;i<number.size();i++)
            {
                if(number[i].first==number[1].first)
                {
                    count2++;
                }
            }
            ll ans=ncr(count2,2);
            cout<<ans<<endl;
        }
        else if(number[1].first<number[2].first)
        {
            ll count2=0;
            for(ll i=2;i<number.size();i++)
            {
                if(number[i].first==number[2].first)
                {
                    count2++;
                }
            }
            ll ans=ncr(count2,1);
            cout<<ans<<endl;
        }
    }

    return 0;
}
