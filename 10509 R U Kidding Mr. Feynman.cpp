#include <bits/stdc++.h>
using namespace std;
int main()
{

    double a,ans,dx;
    while(scanf("%lf",&a))
    {
        if(a==0)
        {
            break;
        }
         ans = floor(pow(a,1.0/3.0)+0.0000000001);
        dx=((a-(ans*ans*ans))/(3*ans*ans));
        ans=(ans+dx);
        cout<<fixed<<setprecision(4)<<ans<<endl;
    }
    return 0;
}
