#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[505],b[505];
string s1,s2;
vector<string>com;
int main()
{
        ll n,i,j,k,l;

        scanf("%lld",&n);
        for(i=1;i<=n;i++)
            scanf("%lld",&a[i]);
        scanf("%lld",&k);
        for(i=1;i<=k;i++)
            scanf("%lld",&b[i]);
        ll sum=0;
        j=1;
        ll start=1,stop=1;
        for(i=1;i<=n;i++)
        {
            if(sum<b[j])
            {
                sum+=a[i];
            }
            if(sum==b[j])
            {
                stop=i;
                ll falsee=0
                for(int k=start;k<=stop;k++)
                {
                   if(a[k]==a[k+1])
                }
            }
        }
}
