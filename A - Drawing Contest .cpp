#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<ll>h,l;
ll n;
int main()
{
    ll tes;
    scanf("%lld",&tes);
    for(ll cas=1;cas<=tes;cas++)
    {
        scanf("%lld",&n);
        h.clear();
        l.clear();
        for(ll i=1;i<=n;i++)
        {
            ll hh;
            scanf("%lld",&hh);
            h.push_back(hh);
        }
        for(ll i=1;i<=n;i++)
        {
            ll hh;
            scanf("%lld",&hh);
            l.push_back(hh);
        }
        sort(h.begin(),h.end());
        sort(l.begin(),l.end());
        ll sum=0;
        for(ll i=0;i<h.size();i++)
        {
            sum+=abs(h[i]-l[i]);
        }
        printf("Case %lld: %lld\n",cas,sum);
    }
    return 0;
}
