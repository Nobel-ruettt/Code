#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<pair<ll,ll> > d;
vector<pair<ll,ll> > s;
ll  ans, n;
ll  binary_searc(ll key_l,ll key_m)
{
    ll  low=0;
    ll  high=d.size()-1;
    ll  mid;
    while(low<=high)
    {
        mid=(low+high)/2;
        if(d[mid].first<=key_l&&d[mid].second<=key_m)
        {
            low=mid+1;
        }
        else
        {
            high=mid-1;
        }
    }
    return low;
}
int main()
{
    ll  x,y;
    while(1)
    {
        scanf("%lld",&n);
        if(n==0)
        {
            cout<<"*"<<endl;
            break;
        }
        d.clear();
        s.clear();
        for (ll i=0; i<n; i++)
        {
            scanf("%lld%lld",&x,&y);
            s.push_back(make_pair(x,y));
        }
        sort(s.begin(),s.end());
        d.push_back(s[0]);
        for(ll i=1; i<n; i++)
        {
            ll  index=binary_searc(s[i].first,s[i].second);
            if (index == d.size())
            {
                d.push_back(s[i]);
            }
            else
            {
                d[index] = s[i];
            }
        }
        printf("%d\n",d.size());
    }
    return 0;
}
