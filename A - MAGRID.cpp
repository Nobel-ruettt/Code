#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m;
ll grid[505][505];
ll visit[505][505];
struct node
{
    ll x,y,value;
    node(){};
    node(ll a,ll b,ll c)
    {
        x=a;
        y=b;
        value=c;
    }
    bool operator<(const node &p)const
    {
        if(p.value<value)
        {
            return 1;
        }
        return 0;
    }
};
priority_queue<node>q;
int main()
{
    ll tes;
    scanf("%lld",&tes);
    for(ll cas=1;cas<=tes;cas++)
    {
        scanf("%lld%lld",&n,&m);
        for(ll i=1;i<=n;i++)
        {
            for(ll j=1;j<=m;j++)
            {
                scanf("%lld",&grid[i][j]);
            }
        }
        for(ll i=1;i<=n;i++)
        {
            for(ll j=1;j<=m;j++)
            {
                visit[i][j]=LLONG_MAX;
            }
        }
        visit[n][m]=1;
        q.push(node(n,m,1));
        while(!q.empty())
        {
            node s=q.top();
            q.pop();
            if(s.x-1>=1)
            {
                ll update_value=s.value+((-1)*grid[s.x][s.y]);
                if(update_value>grid[s.x-1][s.y])
                {
                    if(visit[s.x-1][s.y]>update_value)
                    {
                        visit[s.x-1][s.y]=update_value;
                        q.push(node(s.x-1,s.y,update_value));
                    }
                }
                else if(update_value<=grid[s.x-1][s.y])
                {
                    update_value=grid[s.x-1][s.y]+1;
                    if(visit[s.x-1][s.y]>update_value)
                    {
                        visit[s.x-1][s.y]=update_value;
                        q.push(node(s.x-1,s.y,update_value));
                    }
                }
            }
            if(s.y-1>=1)
            {
                ll update_value=s.value+((-1)*grid[s.x][s.y]);
                if(update_value>grid[s.x][s.y-1])
                {
                    if(visit[s.x][s.y-1]>update_value)
                    {
                        visit[s.x][s.y-1]=update_value;
                        q.push(node(s.x,s.y-1,update_value));
                    }
                }
                else if(update_value<=grid[s.x][s.y-1])
                {
                    update_value=grid[s.x][s.y-1]+1;
                    if(visit[s.x][s.y-1]>update_value)
                    {
                        visit[s.x][s.y-1]=update_value;
                        q.push(node(s.x,s.y-1,update_value));
                    }
                }
            }
        }
        cout<<visit[1][1]<<endl;
    }
    return 0;
}
