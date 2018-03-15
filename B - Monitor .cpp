#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define inf 100000000000
ll grid[600][600];
ll aux[600][600];
ll n,m,k,q,x,y,s;
bool can(ll num)
{
    for(ll i=1;i<=n;i++)
    {
        for(ll j=1;j<=m;j++)
        {
            if(grid[i][j]<=num)
            {
                aux[i][j]=1;
            }
            else
            {
                aux[i][j]=0;
            }
        }
    }
    for(ll i=1;i<=n;i++)
    {
        for(ll j=1;j<=m;j++)
        {
            aux[i][j]=(aux[i-1][j]+aux[i][j-1]+aux[i][j]-aux[i-1][j-1]);
        }
    }
//    for(ll i=1;i<=n;i++)
//    {
//        for(ll j=1;j<=m;j++)
//        {
//            cout<<aux[i][j]<<" ";
//        }
//        cout<<endl;
//    }
    for(ll i=k;i<=n;i++)
    {
        for(ll j=k;j<=m;j++)
        {
            ll tot=aux[i][j]-aux[i-k][j]-aux[i][j-k]+aux[i-k][j-k];
            if(tot==(k*k))
            {
                return 1;
            }
        }
    }
    return 0;
}
int main()
{
    scanf("%lld%lld%lld%lld",&n,&m,&k,&q);
    for(ll i=1;i<=n;i++)
    {
        for(ll j=1;j<=m;j++)
        {
            grid[i][j]=inf;
        }
    }
    for(ll i=1;i<=q;i++)
    {
        scanf("%lld%lld%lld",&x,&y,&s);
        grid[x][y]=s;
    }
    ll low=0;
    ll high=inf;
    ll mid;
    ll ans=-1;
    while(low<=high)
    {
        mid=(low+high)/2;
        if(can(mid))
        {
            ans=mid;
            high=mid-1;
        }
        else
        {
            low=mid+1;
        }
    }
    if(ans>=inf)
    {
        cout<<"-1"<<endl;
    }
    else
    {
        cout<<ans<<endl;
    }
    return 0;
}
