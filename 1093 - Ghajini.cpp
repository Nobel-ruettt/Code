#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sc(n) scanf("%lld",&n)
#define maxi 100010
ll seg_main[maxi];
ll tes,n,d;
struct maxi_mini
{
    ll maximum;
    ll minimum;
} seg[maxi*3+10];
void build(ll n,ll b,ll e)
{
    if(b==e)
    {
        seg[n].maximum=seg_main[b];
        seg[n].minimum=seg_main[b];
        return ;
    }
    ll mid=(b+e)/2;
    build(n*2,b,mid);
    build(n*2+1,mid+1,e);
    seg[n].maximum=max(seg[n*2].maximum,seg[n*2+1].maximum);
    seg[n].minimum=min(seg[n*2].minimum,seg[n*2+1].minimum);
}
ll query_mini(ll n,ll b,ll e,ll i,ll j)
{
    if(b>j||e<i)
    {
        return LLONG_MAX;
    }
    else if(b>=i&&e<=j)
    {
        return seg[n].minimum;
    }
    ll mid=(b+e)/2;
    ll p1=query_mini(n*2,b,mid,i,j);
    ll p2=query_mini(n*2+1,mid+1,e,i,j);
    return min(p1,p2);
}
ll query_maxi(ll n,ll b,ll e,ll i,ll j)
{
    if(b>j||e<i)
    {
        return -1;
    }
    else if(b>=i&&e<=j)
    {
        return seg[n].maximum;
    }
    ll mid=(b+e)/2;
    ll p1=query_maxi(n*2,b,mid,i,j);
    ll p2=query_maxi(n*2+1,mid+1,e,i,j);
    return max(p1,p2);
}
void in_numbers()
{
    for(ll j=1; j<=n; j++)
    {
        sc(seg_main[j]);
    }
}
ll segmentation()
{
    build(1,1,n);
    ll pointer1=1;
    ll pointer2=pointer1-1+d;
    ll maxi_dif=0;
    while(1)
    {
        ll mini=query_mini(1,1,n,pointer1,pointer2);
        ll maxii=query_maxi(1,1,n,pointer1,pointer2);
        ll dif=maxii-mini;
        if(dif>maxi_dif)
        {
            maxi_dif=dif;
        }
        if(pointer2==n)
        {
            break;
        }
        pointer1++;
        pointer2++;
    }
    return maxi_dif;
}
int main()
{
    sc(tes);
    for(ll i=1; i<=tes; i++)
    {
        sc(n);
        sc(d);
        in_numbers();
        ll ans=segmentation();
        printf("Case %lld: %lld\n",i,ans);
    }
    return 0;
}
