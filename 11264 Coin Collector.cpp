#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll coin[1004],coins;
    ll tes,sum,taken,now_sum;
    scanf("%lld",&tes);
    for(int i=1; i<=tes; i++)
    {
        scanf("%lld",&coins);
        for(int j=0; j<coins; j++)
        {
            scanf("%lld",&coin[j]);
        }
        sort(coin,coin+coins);
        sum=1;
        taken=1;
        for(int j=1; j<coins; j++)
        {
            now_sum=sum+coin[j];
            if(now_sum%coin[j]==sum)
            {
                taken++;
                sum=now_sum;
            }
            else if(now_sum%coin[j]<sum)
            {
                sum=sum-coin[j-1];
                sum=sum+coin[j];
            }
        }
        printf("%lld\n",taken);
    }
    return 0;
}
