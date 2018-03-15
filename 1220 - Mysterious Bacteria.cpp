#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll tes,n,sq,number,now_choto;
    scanf("%lld",&tes);
    for(ll i=1; i<=tes; i++)
    {
        scanf("%lld",&n);
        if(n==0)
        {
            printf("Case %lld: 1\n",i);
            continue;
        }
        if(n<0)
        {
            ll absolute=fabs(n);
            ll sq=sqrt(absolute);
            ll maxi=1;
            for(ll j=2; j<=sq+5; j++)
            {
                ll number=absolute;
                ll now_choto=j;
                if(number%now_choto==0)
                {
                    ll count1=0;
                    while(number%now_choto==0)
                    {
                        number/=now_choto;
                        count1++;
                    }
                    if(number==1)
                    {
                        if(count1%2==1)
                        {
                            if(count1>maxi)
                            {
                                maxi=count1;
                            }
                        }
                    }
                }
            }
            printf("Case %lld: %lld\n",i,maxi);
        }
        else if(n>0)
        {
            ll sq=sqrt(n);
            ll maxi=1;
            ll poe;
            for(ll j=2; j<=sq+5; j++)
            {
                ll number=n;
                ll now_choto=j;
                if(number%now_choto==0)
                {
                    ll count1=0;
                    while(number%now_choto==0)
                    {
                        number/=now_choto;
                        count1++;
                    }
                    if(number==1)
                    {
                        if(count1>maxi)
                        {
                            poe=now_choto;
                            maxi=count1;
                        }
                    }
                }
            }
            printf("Case %lld: %lld\n",i,maxi);
        }
    }
    return 0;
}
