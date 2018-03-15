#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sc(n) scanf("%lld",&n)
ll count1[500];
ll visited[500];
ll n,m,uuu,vvv;
struct node
{
    ll u,v,slot;
    node(ll a,ll b,ll c)
    {
        u=a;
        v=b;
        slot=c;
    }
};
vector<node>quer;
int main()
{
    ll tes;
    sc(tes);
    for(ll cas=1; cas<=tes; cas++)
    {
        sc(n);
        sc(m);
        for(ll i=1; i<=m; i++)
        {
            sc(uuu);
            sc(vvv);
            quer.push_back(node(uuu,vvv,-1));
            count1[uuu]++;
            count1[vvv]++;
        }
        ll k=0;
        for(ll i=1; i<=n; i++)
        {
            if(count1[i]>k)
            {
                k=count1[i];
            }
        }
        for(ll i=1; i<=k+1; i++)
        {
            for(ll j=0; j<quer.size(); j++)
            {
                if(quer[j].slot!=-1)
                {
                    continue;
                }
                ll uu=quer[j].u;
                ll vv=quer[j].v;
                if(visited[uu]!=i && visited[vv]!=i)
                {
                    quer[j].slot=i;
                    visited[uu]=i;
                    visited[vv]=i;
                }
            }
            bool flag=0;
            for(ll j=0; j<quer.size(); j++)
            {
                if(quer[j].slot==-1)
                {
                    flag=1;
                    break;
                }
            }
            if(flag==0)
            {
                break;
            }
        }
        bool flag=0;
        for(ll i=0; i<quer.size(); i++)
        {
            if(quer[i].slot==-1)
            {
                flag=1;
            }
        }
        if(flag==1)
        {
            for(ll i=0; i<quer.size(); i++)
            {
                cout<<quer[i].u<<" "<<quer[i].v<<" "<<"0"<<endl;
            }
        }
        else
        {
            for(ll i=0; i<quer.size(); i++)
            {
                cout<<quer[i].u<<" "<<quer[i].v<<" "<<quer[i].slot<<endl;
            }
        }
        quer.clear();
        memset(count1,0,sizeof count1);
        memset(visited,0,sizeof visited);
    }
    return 0;
}
