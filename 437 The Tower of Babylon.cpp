#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxi 100
struct box
{
    ll length;
    ll height;
    ll weidth;
    ll area;
    bool operator<(const box &p)const
    {

        return p.area>=area;
    }
};
vector<box>boxes;
ll n,u,v,w;
ll dp[300];
ll longest(ll source)
{
    if(dp[source]!=-1) return dp[source];
    ll maxii=0;
    for(ll i=source+1; i<boxes.size(); i++) //১ম শর্ত,v>u
    {
        if(boxes[i].length>boxes[source].length&&boxes[i].weidth>boxes[source].weidth) //২য় শর্ত, value[v]>value[u]
        {
            if(longest(i)>maxii) //সর্বোচ্চ মানটা নিবো
            {
                maxii=longest(i);
            }
        }
    }
    dp[source]=boxes[source].height+maxii; //১ যোগ হবে কারণ u নম্বর নোডটাও পাথের মধ্যে আছে
    return dp[source];
}
int main()
{
    ll k=1;
    while(1)
    {
        scanf("%lld",&n);
        if(n==0)
        {
            break;
        }
        for(ll i=1; i<=n; i++)
        {
            scanf("%lld%lld%lld",&u,&v,&w);
            box s;
            s.length=u;
            s.weidth=v;
            s.height=w;
            s.area=u*v;
            boxes.push_back(s);
            s.length=v;
            s.weidth=u;
            s.height=w;
            s.area=u*v;
            boxes.push_back(s);
            s.length=u;
            s.weidth=w;
            s.height=v;
            s.area=u*w;
            boxes.push_back(s);
            s.length=w;
            s.weidth=u;
            s.height=v;
            s.area=u*w;
            boxes.push_back(s);
            s.length=v;
            s.weidth=w;
            s.height=u;
            s.area=v*w;
            boxes.push_back(s);
            s.length=w;
            s.weidth=v;
            s.height=u;
            s.area=v*w;
            boxes.push_back(s);
        }
        sort(boxes.begin(),boxes.end());
        ll maximum=0;
        memset(dp,-1,sizeof(dp));
        for(ll i=0; i<boxes.size(); i++)
        {
            if(longest(i)>maximum)
            {
                maximum=longest(i);
            }
        }
        printf("Case %lld: maximum height = %lld\n",k,maximum);
        k++;
    }
    return 0;
}
