#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxi 100005;
ll array[maxi];
struct node
{
    ll sum;
    ll lef_pen;
    ll right_pen;
};
node seg[maxi*3];
void build(ll node,ll begin,ll end)
{
    if(begin==end)
    {
        seg[node].sum=array[begin];
        seg[node].lef_pen=0;
        seg[node].right_pen=0;
        return ;
    }
    ll mid=(begin+end)/2;
    ll left=node*2;
    ll right=node*2+1;
    build(left,begin,mid);
    build(right,mid+1,end);
    seg[node].sum=seg[left].sum+seg[right].sum;
    seg[node].lef_pen=0;
    seg[node].right_pen=0;
}
void update(ll node,ll begin,ll end,ll i,ll j,ll value,ll pen=0)
{
    if(i>end || j<begin)
    {
        if(pen!=0)
        {
             seg[node]=(end-begin+1)*pen;
             seg[node].lef_pen=pen;
             seg[node].right_pen=pen;
        }
        return;
    }
    else if(begin>=i && end<=j)
    {
        seg[node].sum=(begin-end+1)*value;
        seg[node].lef_pen=value;
        seg[node].right_pen=value;
        return ;
    }
    ll left=node*2;
    ll right=node*2+1;
    update(left,begin,mid,i,j,value,seg[node].lef_pen);
    update(right,mid+1,end,i,j,value,seg[node].right_pen);
}
