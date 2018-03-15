#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll tes,n;
    scanf("%lld",&tes);
    for(ll cas=1;cas<=tes;cas++)
    {
        scanf("%lld",&n);
        ll sq=(ll)sqrt(n);
        if((sq*sq)==n)
        {
            ll res=0;
            for(ll i=1;i<sq;i++)
            {
                ll res1=(long long)(n/i);
                ll right_range=(long long)(n/i);
                ll left_range=(long long)(n/(i+1));
                left_range++;
                ll res2=(i*(right_range-left_range+1));
                res+=(res1+res2);
            }
            res+=sq;
            printf("Case %lld: %lld\n",cas,res);
        }
        else
        {
            ll res=0;
            for(ll i=1;i<=sq;i++)
            {
                ll res1=(long long)(n/i);
                ll right_range=(long long)(n/i);
                ll left_range=(long long)(n/(i+1));
                left_range++;
                ll res2;
                if(left_range>right_range)
                {
                    res2=0;
                }
                else
                {
                    res2=(i*(right_range-left_range+1));
                }
                res+=(res1+res2);
            }
            printf("Case %lld: %lld\n",cas,res);
        }
    }
    return 0;
}
