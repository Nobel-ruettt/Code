#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll a[100005];
ll b[100005];
struct node
{
    ll baki,vora;
    node(ll a,ll b)
    {
        baki=a;
        vora=b;
    }
};
bool comp(node a,node b)
{
    if(a.baki>b.baki)
    {
        return 1;
    }
    else if(a.baki==b.baki)
    {
        if(a.vora>b.vora)
        {
            return 1;
        }
    }
    return 0;
}
vector<node>ss;
int main()
{
    ll n;
    scanf("%lld",&n);
    ll sum2=0;
    for(ll i=1;i<=n;i++)
    {
        scanf("%lld",&a[i]);
        sum2+=a[i];
    }
    for(ll i=1;i<=n;i++)
    {
        scanf("%lld",&b[i]);
    }
    sort(b+1,b+1+n);
    ll sum=b[n]+b[n-1];
    if(sum2<=sum)
    {
        cout<<"YES"<<endl;
    }
    else
    {
        cout<<"NO"<<endl;
    }
    return 0;
}
