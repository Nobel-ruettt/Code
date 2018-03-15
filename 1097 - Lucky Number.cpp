#include <bits/stdc++.h>
using namespace std;
#define ll int
#define sc(n) scanf("%d",&n)
#define maxi  1439431
ll seg[maxi*3+10];
vector<ll>ans;
void build(ll n,ll b,ll e)
{
    if(b==e)
    {
        if(b%2==1)
        {
            seg[n]=1;
        }
        else
        {
            seg[n]=0;
        }
        ///cout<<"node "<<n<<" b "<<b<<" e "<<e<<" value "<<seg[n]<<endl;
        return ;
    }
    ll mid=(b+e)/2;
    build(n*2,b,mid);
    build(n*2+1,mid+1,e);
    seg[n]=seg[n*2]+seg[n*2+1];
    ///cout<<"node "<<n<<" b "<<b<<" e "<<e<<" value "<<seg[n]<<endl;
}
ll query(ll node,ll b,ll e,ll value)
{
    if(b==e)
    {
        return b;
    }
    if(value<=seg[node*2])
    {
        return query(node*2,b,((long)((b+e)/2)),value);
    }
    else if(value>seg[node*2])
    {
        return query(node*2+1,((long)((b+e)/2))+1,e,value-seg[node*2]);
    }
}
void update(ll node,ll b,ll e,ll value)
{
    if(b==e)
    {
        ///cout<<"begin "<<b<<" end "<<e<<endl;
        seg[node]=0;
        return ;
    }
    if(value<=seg[node*2])
    {
        update(node*2,b,((long)((b+e)/2)),value);
    }
    else if(value>seg[node*2])
    {
        update(node*2+1,((long)((b+e)/2))+1,e,value-seg[node*2]);
    }
    seg[node]=seg[node*2]+seg[node*2+1];
}
void pre()
{
    build(1,1,maxi);
    ans.push_back(1);
    for(ll i=2;i<100003;i++)
    {
        ll num=query(1,1,maxi,i);
        ///cout<<"num "<<num<<endl;
        ans.push_back(num);
//        cout<<"ans vector";
//        for(ll j=0;j<ans.size();j++)
//        {
//            cout<<ans[j]<<endl;
//        }
        ///cout<<"main number "<<num<<endl;
        ll count1=0;
        ll up;
        for(ll j=num;j<maxi;j+=num)
        {
            up=j-count1;
            count1++;
            update(1,1,maxi,up);
        }
//        if(i==4)
//        {
//            break;
//        }
    }
}
int main()
{
   pre();
   ll tes,n;
   sc(tes);
   for(ll i=1;i<=tes;i++)
   {
       sc(n);
       printf("Case %d: %d\n",i,ans[n-1]);
   }
   return 0;
}
