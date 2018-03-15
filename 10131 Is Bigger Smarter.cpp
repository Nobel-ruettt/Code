#include <bits/stdc++.h>
using namespace std;
#define ll long long
using namespace std;
struct elephant
{
    int w, s, id;
};
bool operator <(elephant a, elephant b)
{
    return a.w < b.w || a.w == b.w && a.s < b.s;
}
ll dp[1005];
ll dir[1005];
vector<elephant>el;
ll longest(ll source)
{
    if(dp[source]!=-1)
    {
        return dp[source];
    }
    ll maxi=0;
    for(ll i=source+1;i<el.size();i++)
    {
        if(el[i].w>el[source].w&&el[i].s<el[source].s)
        {
            if(longest(i)>maxi)
            {
                maxi=longest(i);
                dir[source]=i;
            }
        }
    }
    dp[source]=1+maxi;
    return dp[source];
}
int main()
{
    elephant e;
    ll n=1;
    while (cin >> e.w >>e.s)
    {
        e.id=n;
        el.push_back(e);
        n++;
    }
    sort(el.begin(),el.end());
    memset(dp,-1,sizeof(dp));
    memset(dir,-1,sizeof(dir));
    ll maximum=0;
    ll start;
    for(ll i=0;i<el.size();i++)
    {
        if(longest(i)>maximum)
        {
            maximum=longest(i);
            start=i;
        }
    }
    cout<<maximum<<endl;
    while(dir[start]!=-1)
	{
		printf("%lld\n",el[start].id);
		start=dir[start];
	}
    return 0;
}
