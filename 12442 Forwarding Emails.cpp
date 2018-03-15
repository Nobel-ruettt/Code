#include <stdio.h>
#include <iostream>
#include <map>
#include <deque>
#include <vector>
using namespace std;
#define ll long long
ll node[50005][1];
ll array[50005];
ll marked[50005];
deque<ll>lisi;
map<ll , ll >sour;
void bfs(ll source,ll sizee)
{
    ll so,count=0;
    array[source]=1;
    for(int i=1;i<=sizee;i++)
    {
        marked[i]=0;
    }
    marked[source]=1;
    lisi.push_front(source);
    while(!lisi.empty())
    {
        so=lisi.front();
        lisi.pop_front();
        count++;
        if(marked[node[so][0]]==0)
        {
            array[node[so][0]]=1;
            marked[node[so][0]]=1;
            lisi.push_back(node[so][0]);
        }
    }
    sour[source]=count;
    lisi.clear();
}
int main()
{
    ll tes,mar,mar1,mar2;
    scanf("%lld",&tes);
    for(int i=1;i<=tes;i++)
    {
        scanf("%lld",&mar);
        for(int j=0;j<mar;j++)
        {
            scanf("%lld %lld",&mar1,&mar2);
            node[mar1][0]=mar2;
        }
        for(int j=1;j<=mar;j++)
        {
             array[j]=-1;
        }
        ll falsee;
        while(1)
        {
            falsee=0;
            for(int j=1;j<=mar;j++)
            {
                if(array[j]==-1)
                {
                     bfs(j,mar);
                     falsee=1;
                }
            }
            if(falsee==0)
            {
                break;
            }
        }
        ll maxi=0,nodes;
        map<ll ,ll> :: iterator it;
        for(it=sour.begin();it!=sour.end();it++)
        {
            if(it->second>maxi)
            {
                maxi=it->second;
                nodes=it->first;
            }
        }
        printf("Case %d: %lld\n",i,nodes);
        sour.clear();
        lisi.clear();
    }
    return 0;
}
