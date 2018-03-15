#include <bits/stdc++.h>
using namespace std;
#define ll int
#define maxi 100010
struct node
{
    ll zeros;
    ll ones;
    ll twos;
    ll pending;
} seg[3*maxi];
void build(ll n,ll b,ll e)
{
    if(b==e)
    {
        seg[n].zeros=1;
        seg[n].ones=0;
        seg[n].twos=0;
        seg[n].pending=0;
        return;
    }
    ll mid=(b+e)/2;
    build(n*2,b,mid);
    build(n*2+1,mid+1,e);
    seg[n].zeros=seg[n*2].zeros+seg[n*2+1].zeros;
    seg[n].ones=seg[n*2].ones+seg[n*2+1].ones;
    seg[n].twos=seg[n*2].twos+seg[n*2+1].twos;
    seg[n].pending=0;
}
ll up,count1,tmp_0,tmp_1,tmp_2;
void update(ll n,ll b,ll e,ll i,ll j,ll value,ll carry=0)
{
    if(b>=i&&e<=j)
    {
        up=(carry+value)%3;
        count1=0;
        while(count1<up)
        {
            tmp_0=seg[n].zeros;
            tmp_1=seg[n].ones;
            tmp_2=seg[n].twos;
            seg[n].twos=tmp_1;
            seg[n].ones=tmp_0;
            seg[n].zeros=tmp_2;
            count1++;
        }
        seg[n].pending+=up;
        //cout<<"node "<<n<<" begin "<<b<<" end "<<e<<" zeros "<<seg[n].zeros<<" ones "<<seg[n].ones<<" twos "<<seg[n].twos<<" pending "<<seg[n].pending<<endl;
        return ;
    }
    if(b>j||e<i)
    {
        up=carry%3;
        count1=0;
        while(count1<up)
        {
            tmp_0=seg[n].zeros;
            tmp_1=seg[n].ones;
            tmp_2=seg[n].twos;
            seg[n].twos=tmp_1;
            seg[n].ones=tmp_0;
            seg[n].zeros=tmp_2;
            count1++;
        }
        seg[n].pending+=up;
        //cout<<"node "<<n<<" begin "<<b<<" end "<<e<<" zeros "<<seg[n].zeros<<" ones "<<seg[n].ones<<" twos "<<seg[n].twos<<" pending "<<seg[n].pending<<endl;
        return ;
    }
    ll mid=(b+e)/2;
    update(n*2,b,mid,i,j,value,carry+seg[n].pending);
    update(n*2+1,mid+1,e,i,j,value,carry+seg[n].pending);
    seg[n].pending=0;
    seg[n].zeros=seg[n*2].zeros+seg[n*2+1].zeros;
    seg[n].ones=seg[n*2].ones+seg[n*2+1].ones;
    seg[n].twos=seg[n*2].twos+seg[n*2+1].twos;
    //cout<<"node "<<n<<" begin "<<b<<" end "<<e<<" zeros "<<seg[n].zeros<<" ones "<<seg[n].ones<<" twos "<<seg[n].twos<<" pending "<<seg[n].pending<<endl;

}
ll query(ll n,ll b,ll e,ll i,ll j,ll carry=0)
{
    if(b>=i&&e<=j)
    {
        up=(carry)%3;
        count1=0;
        while(count1<up)
        {
            tmp_0=seg[n].zeros;
            tmp_1=seg[n].ones;
            tmp_2=seg[n].twos;
            seg[n].twos=tmp_1;
            seg[n].ones=tmp_0;
            seg[n].zeros=tmp_2;
            count1++;
        }
        seg[n].pending+=up;
        //cout<<"node "<<n<<" begin "<<b<<" end "<<e<<" zeros "<<seg[n].zeros<<" ones "<<seg[n].ones<<" twos "<<seg[n].twos<<" pending "<<seg[n].pending<<endl;
        return seg[n].zeros;
    }
    if(b>j||e<i)
    {
        up=carry%3;
        count1=0;
        while(count1<up)
        {
            tmp_0=seg[n].zeros;
            tmp_1=seg[n].ones;
            tmp_2=seg[n].twos;
            seg[n].twos=tmp_1;
            seg[n].ones=tmp_0;
            seg[n].zeros=tmp_2;
            count1++;
        }
        seg[n].pending+=up;
        //cout<<"node "<<n<<" begin "<<b<<" end "<<e<<" zeros "<<seg[n].zeros<<" ones "<<seg[n].ones<<" twos "<<seg[n].twos<<" pending "<<seg[n].pending<<endl;
        return 0;
    }
    ll mid=(b+e)/2;
    ll p1=query(n*2,b,mid,i,j,carry+seg[n].pending);
    ll p2=query(n*2+1,mid+1,e,i,j,carry+seg[n].pending);
    seg[n].pending=0;
    seg[n].zeros=seg[n*2].zeros+seg[n*2+1].zeros;
    seg[n].ones=seg[n*2].ones+seg[n*2+1].ones;
    seg[n].twos=seg[n*2].twos+seg[n*2+1].twos;
    return p1+p2;
    //cout<<"node "<<n<<" begin "<<b<<" end "<<e<<" zeros "<<seg[n].zeros<<" ones "<<seg[n].ones<<" twos "<<seg[n].twos<<" pending "<<seg[n].pending<<endl;

}
int main()
{
    ll tes,n,q,type,left,right;
    scanf("%d",&tes);
    for(ll i=1; i<=tes; i++)
    {
        scanf("%d%d",&n,&q);
        printf("Case %d:\n",i);
        build(1,1,n);
        for(ll j=1; j<=q; j++)
        {
            scanf("%d%d%d",&type,&left,&right);
            if(type==0)
            {
                update(1,1,n,left+1,right+1,1);
            }
            else if(type==1)
            {
                printf("%d\n",query(1,1,n,left+1,right+1));
            }
        }
    }
    return 0;
}
