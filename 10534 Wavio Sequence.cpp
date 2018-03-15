#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<ll>main_arr;
vector<ll>revesed_arr;
vector<ll>L_reverse;
ll I[10005];
ll L[10005];
ll I2[10006];
ll L2[10005];
ll n,lis_length,lds_length;
void take_input()
{
    main_arr.clear();
    revesed_arr.clear();
    L_reverse.clear();
    ll value;
    for(ll i=0;i<n;i++)
    {
        scanf("%lld",&value);
        main_arr.push_back(value);
    }
    reverse(main_arr.begin(),main_arr.end());
    revesed_arr=main_arr;
    reverse(main_arr.begin(),main_arr.end());
}
void longest_increasing_subsequence()
{
    ll low,high,mid,key;
    I[0]=LLONG_MIN;
    for(ll i=1;i<=n;i++)
    {
        I[i]=LLONG_MAX;
    }
    lis_length=0;
    for(ll i=0;i<n;i++)
    {
        key=main_arr[i];
        low=0;
        high=lis_length;
        while(low<=high)
        {
            mid=(low+high)/2;
            if(I[mid]<key)
            {
                low=mid+1;
            }
            else
            {
                high=mid-1;
            }
        }
        I[low]=key;
        L[i]=low;
        if(lis_length<low)
        {
            lis_length=low;
        }
    }
}
void longest_decreasing_subsequence()
{
    ll low,high,mid,key;
    I2[0]=LLONG_MIN;
    for(ll i=1;i<=n;i++)
    {
        I2[i]=LLONG_MAX;
    }
    lds_length=0;
    for(ll i=0;i<n;i++)
    {
        key=revesed_arr[i];
        low=0;
        high=lds_length;
        while(low<=high)
        {
            mid=(low+high)/2;
            if(I2[mid]<key)
            {
                low=mid+1;
            }
            else
            {
                high=mid-1;
            }
        }
        I2[low]=key;
        L2[i]=low;
        if(lds_length<low)
        {
            lds_length=low;
        }
    }
    for(ll i=0;i<n;i++)
    {
        L_reverse.push_back(L2[i]);
    }
    reverse(L_reverse.begin(),L_reverse.end());
}
int main()
{
    while(scanf("%lld",&n)!=EOF)
    {
        take_input();
        longest_increasing_subsequence();
        longest_decreasing_subsequence();
        ll maximum=0;
        for(ll i=0;i<n;i++)
        {
            ll minimum=min(L[i],L_reverse[i]);
            if(maximum<minimum)
            {
                maximum=minimum;
            }
        }
        printf("%lld\n",maximum*2-1);
    }
    return 0;
}
