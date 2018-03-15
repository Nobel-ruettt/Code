#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    double prev=2.00;
    double now_sum=0.00;
    now_sum+=(1.00/sqrt(prev));
    for(ll i=1;i<=60;i++)
    {
        prev*=2.00;
        now_sum+=(1.00/sqrt(prev));
    }
    ll tes,r;
    cin>>tes;
    for(ll cas=1;cas<=tes;cas++)
    {
        scanf("%lld",&r);
        double rr=(double)r;
        double ans;
        ans=rr;
        ans+=rr*now_sum;
        printf("%0.1lf\n",ans);
    }
    return 0;
}
