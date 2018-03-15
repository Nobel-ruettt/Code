#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define pb push_back
#define pii pair<int,int>
#define pll pair<ll,ll>
#define uu first
#define vv second
#define msz 4
#define cn 3
#define rn 3
#define mod 1000000009
#define inf 1000000000
#define limit 31622790
vector <ll> v;
bool stat[31622800];

ll prime[15811400];

void primegen()
{
    ll i, j, k, sq=sqrt(limit);

    k=0;
    prime[k++]=2;

    for(i=4; i<=limit; i+=2)
        stat[i]=1;

    for(i=3; i<=limit; i+=2)
    {
        if(stat[i]==0)
        {
            prime[k++]=i;
            if(i<=sq);
            {
                for(j=i*i; j<=limit; j+=(i+i))
                {
                    stat[j]=1;
                }
            }
        }
    }
}


bool isprime(ll x)
{
    if(x<31622790)
    {
        if(stat[x]==1)
            return 0;
        else
            return 1;
    }
    else
    {
        ll i, sq=sqrt(x);

        for(i=0;prime[i]<=sq;i++)
        {
            if(x%prime[i]==0)
                return 0;
        }

        return 1;
    }

//    if(x<2)
//        return 0;
//    else if(x==2 || x==3)
//        return 1;
//    else if(x%2==0 || x%3==0)
//        return 0;
//    else
//    {
//        ll r=5, sq=sqrt(x);
//
//        while(r<=sq)
//        {
//            if(x%r==0)
//                return 0;
//            else if(x%(r+2)==0)
//                return 0;
//
//            r+=6;
//        }
//
//        return 1;
//    }
}

int main()
{
    ll a, b, i, dif, f, l;
    primegen();

//    for(i=1;i<=111;i++)
//    {
//        if(isprime(i)==1)
//            printf("%lld\n",i);
//    }

    scanf("%lld %lld", &a, &b);

    f=0;

    if(a==2)
        v.pb(a);
    else
    {
        v.pb(a);
        if(isprime(a-2)==1)
        {
            v.pb(2);
        }
        else if(isprime(a+2)==1)
        {
            v.pb(a+2);
            v.pb(2);
        }
        else
            f=1;
    }

    if(f==0)
    {
        if(b!=2)
        {
            if(isprime(b-2)==1)
            {
                v.pb(b);
            }
            else if(isprime(b+2)==1)
            {
                v.pb(b+2);
                v.pb(b);
            }
            else
                f=1;
        }
    }

    if(f==0)
    {
        l=v.size();

        for(i=0; i<l; i++)
        {
            if(i!=0)
                printf("->");
            printf("%lld",v[i]);
        }

        printf("\n");
    }
    else if(f==1)
        printf("Unlucky Benny\n");

    return 0;
}
