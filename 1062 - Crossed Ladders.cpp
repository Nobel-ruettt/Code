#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sc(n) scanf("%lld",&(n))
#define scc(r) scanf("%lf",&(r))
#define foor(i,n) for(long long (i)=1;(i)<=(n);(i)++)
#define inf LLONG_MAX
#define ii if
#define eii else if
#define dd double
ll tes;
dd x,y,h,low,high,mid,prev,ans_now,upor,nich,g,now_ratio;
int main()
{
    sc(tes);
    foor(l,tes)
    {
        scc(x);
        scc(y);
        scc(h);
        low=0.00;
        ii(x>=y)
        {
            high=y;
        }
        else
        {
            high=x;
        }
        prev=-1000.00;
        ///cout<<high<<endl;
        while(low<=high)
        {
            mid=(low+high)/2.00;
            g=mid;
            ans_now=mid;
            upor=sqrt((x*x-g*g)*(y*y-g*g));
            nich=(sqrt(x*x-g*g))+(sqrt(y*y-g*g));
            now_ratio=upor/nich;
            ///cout<<mid<<" "<<now_ratio<<endl;
            if(now_ratio<=h)
            {
                high=mid;
            }
            else
            {
                low=mid;
            }
            //cout<<ans_now<<"  "<<prev<<endl;
            ///cout<<fabs(ans_now-prev)<<endl;
            if(fabs(ans_now-prev)<0.0000000001)
            {
                break;
            }
            prev=ans_now;
        }
        printf("Case %lld: %0.9lf\n",l,ans_now);
    }
    return 0;
}
