#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll tes,edges,count1;
map<string,ll>nodes;
vector<ll>graph[20005];
ll indegree[20005];
void cle()
{
    nodes.clear();
    for(ll i=1;i<20005;i++)
    {
        graph[i].clear();
        indegree[i]=0;
    }
}
void in_edges()
{
    string s1,s2;
    count1=1;
    for(ll i=1;i<=edges;i++)
    {
        cin>>s1>>s2;
        if(nodes[s1]==0)
        {
            nodes[s1]=count1;
            count1++;
        }
        if(nodes[s2]==0)
        {
            nodes[s2]=count1;
            count1++;
        }
        indegree[nodes[s2]]++;
        graph[nodes[s1]].push_back(nodes[s2]);
    }
}
void solve()
{
    for(ll i=1;i<count1;i++)
    {
        if(indegree[i]==0)
        {
            indegree[i]=-1;
            for(ll j=0;j<graph[i].size();j++)
            {
                indegree[graph[i][j]]--;
            }
            solve();
        }
    }
}
int main()
{
    scanf("%lld",&tes);
    for(ll i=1;i<=tes;i++)
    {
        scanf("%lld",&edges);
        cle();
        in_edges();
        solve();
        ll falsee=0;
        for(ll j=1;j<count1;j++)
        {
            if(indegree[j]!=-1)
            {
                printf("Case %lld: No\n",i);
                falsee=1;
                break;
            }
        }
        if(falsee==1)
        {
            continue;
        }
        printf("Case %lld: Yes\n",i);
    }
    return 0;
}
