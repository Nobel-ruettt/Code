#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll tes,n,w,x,y;
priority_queue<ll,vector<ll>,greater<ll> >y_min;
map<ll,ll>visited;
map<ll,ll>visited2;
void cle()
{
    visited.clear();
    visited2.clear();
    while(!y_min.empty())
    {
        y_min.pop();
    }
}
void in_cor()
{
    for(ll i=1;i<=n;i++)
    {
        scanf("%lld%lld",&x,&y);
        if(visited[y]==0)
        {
            visited[y]=1;
            y_min.push(y);
        }
    }
//    while(!y_min.empty())
//    {
//        cout<<y_min.top()<<endl;
//        y_min.pop();
//    }
}
ll solve()
{
    ll sum=0;
    ll source;
    while(!y_min.empty())
    {
        source=y_min.top();
        y_min.pop();
        if(visited2[source]==0)
        {
            sum++;
            for(ll i=0;i<=w;i++)
            {
                visited2[source+i]=1;
            }
        }
    }
    return sum;
}
int main()
{
    scanf("%lld",&tes);
    for(ll i=1;i<=tes;i++)
    {
        scanf("%lld%lld",&n,&w);
        cle();
        in_cor();
        ll ans=solve();
        printf("Case %lld: %lld\n",i,ans);
    }
    return 0;
}
