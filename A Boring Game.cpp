#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxi 100005
vector<ll>graph[maxi];
ll n,u,v;
void cle()
{
    for(ll i=1;i<=n;i++)
    {
        graph[i].clear();
    }
}
int main()
{
    ll tes;
    scanf("%lld",&tes);
    for(ll cas=1;cas<=tes;cas++)
    {
        scanf("%lld",&n);
        cle();
        for(ll i=1;i<=n-1;i++)
        {
           scanf("%lld%lld",&u,&v);
           graph[u].push_back(v);
           graph[v].push_back(u);
        }
        if(n==2)
        {
            printf("Case %lld: 0\n",cas);
            continue;
        }
        ll check=0;
        for(ll i=1;i<=n;i++)
        {
            if(graph[i].size()==n-1)
            {
                check=1;
                break;
            }
        }
        if(check==1)
        {
            printf("Case %lld: %lld\n",cas,n-1);
        }
        else
        {
            printf("Case %lld: %lld\n",cas,n);
        }
    }
    return 0;
}
