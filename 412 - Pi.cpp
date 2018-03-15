#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<ll>numbers;
ll gcd(ll a, ll b)
{
    if (a == 0)
    {
       return b;
    }
    return gcd(b%a, a);
}

int main()
{
    ll num,n,count1,first,second,gcdd,no_factor;
    double ans;
    while(scanf("%lld",&num)==1)
    {
        if(num==0)
        {
            break;
        }
        numbers.clear();
        for(ll i=0;i<num;i++)
        {
            scanf("%lld",&n);
            numbers.push_back(n);
        }
        count1=0;
        no_factor=0;
        for(ll i=0;i<numbers.size();i++)
        {
            for(ll j=i+1;j<numbers.size();j++)
            {
                count1++;
                first=numbers[i];
                second=numbers[j];
                gcdd=gcd(first,second);
                if(gcdd==1)
                {
                    no_factor++;
                }
            }
        }
        if(no_factor==0)
        {
            printf("No estimate for this data set.\n");
        }
        else
        {
            ans=(double)(no_factor)/(double)(count1);
            ans=6.00/ans;
            ans=sqrt(ans);
            printf("%0.6lf\n",ans);
        }
    }
    return 0;
}
