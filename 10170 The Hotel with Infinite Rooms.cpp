#include <bits/stdc++.h>
using namespace std;
int main()
{
    double n;
    long long start,day,c,ans;
    while(scanf("%lld%lld",&start,&day)==2)
    {
        c=start-1;
        c=(c*(c+1))/2;
        c=c+day;
        c=c*2;
        c=1+(4*c);
        n=sqrt((double)c);
        n=(-1.00+n)/2.00;
        ans=ceil(n);
        cout<<ans<<endl;
    }
    return 0;
}
