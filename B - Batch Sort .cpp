#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pi pair<ll,ll>
ll arr[100][100];
map<pair<ll,ll>,ll>ase;
pi ans;
int main()
{
    ll n,m;
    scanf("%lld%lld",&n,&m);
    for(ll i=1;i<=n;i++)
    {
        for(ll j=1;j<=m;j++)
        {
            scanf("%lld",&arr[i][j]);
        }
    }
    bool flag=0;
    for(ll i=1;i<=n;i++)
    {
        ll count1=0;
        for(ll j=1;j<=m;j++)
        {
            if(arr[i][j]!=j)
            {
                count1++;
            }
        }
        if(count1>2)
        {
            flag=1;
        }
    }
    if(flag==0)
    {
        cout<<"YES"<<endl;
        return 0;
    }
    ll maxi=0;

    for(ll i=1;i<=n;i++)
    {
        for(ll j=1;j<=m;j++)
        {
            if(arr[i][j]!=j)
            {
                ll minimum=min(arr[i][j],j);
                ll maximum=max(arr[i][j],j);
                ase[make_pair(minimum,maximum)]++;
                if(ase[make_pair(minimum,maximum)]>maxi)
                {
                    ans=make_pair(minimum,maximum);
                    maxi=ase[make_pair(minimum,maximum)];
                }
            }
        }
    }
    flag=0;
    for(ll i=1;i<=n;i++)
    {
        swap(arr[i][ans.first],arr[i][ans.second]);
        ll count1=0;
        for(ll j=1;j<=m;j++)
        {
            if(arr[i][j]!=j)
            {
                count1++;
            }
        }
        if(count1>2)
        {
            flag=1;
        }
    }
    if(flag==0)
    {
        cout<<"YES"<<endl;
        return 0;
    }
    else
    {
        cout<<"NO"<<endl;
        return 0;
    }
    return 0;
}
