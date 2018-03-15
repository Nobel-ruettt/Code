#include <bits/stdc++.h>
using namespace std;
/***template***/
#define ll                   long long
#define dd                   double
#define scl(n)               scanf("%lld",&n)
#define sci(n)               scanf("%d",&n)
#define scd(n)               scanf("%lf",&n)
#define pi                   pair<ll,ll>
#define pb                   push_back
#define mp                   make_pair
#define uu                   first
#define vv                   second
#define FOR(i,n)             for(ll i=1;i<=n;i++)
#define LOOP(i,n)            for(ll i=0;i<n;i++)
#define FOOR(i,a,b)          for(ll i=a;i<=b;i++)
#define sorted(s)            sort(s.begin(),s.end())
#define reversed(s)          reverse(s.begin(),s.end())
#define contains(a,b)        (find((a).begin(), (a).end(), (b)) != (a).end())
#define MAXN                 10004
#define pii                  3.1415926536
#define mod                  1000000007
#define eps                  0.000000000001
#define inf                  10000000000000000
/***template***/
struct node
{
    ll now_r,now_c;
    dd dist;
    node() {}
    node(dd a,ll b,ll c)
    {
        dist=a;
        now_r=b;
        now_c=c;
    }
    bool operator<(const node &p)const
    {
        return dist>p.dist;
    }
};
ll tes,r,c,q,s_r,s_c,d_r,d_c;
dd dis[200][200];
dd hardness[200][200];
priority_queue<node>qq;
void djixtra()
{
    FOR(i,r)
    {
        FOR(j,c)
        {
            dis[i][j]=(dd)inf;
        }
    }
    dis[s_r][s_c]=0.0000;
    qq.push(node(dis[s_r][s_c],s_r,s_c));
    while(!qq.empty())
    {
        node s=qq.top();
        qq.pop();
        ll ss_r=s.now_r;
        ll ss_c=s.now_c;
        if(ss_r==d_r && ss_c==d_c)
        {
            return ;
        }
        dd distanc=s.dist;
        if(ss_r+1<=r)
        {
            dd cost;
            dd h_1=hardness[ss_r][ss_c];
            dd h_2=hardness[ss_r+1][ss_c];
            if(h_1>h_2)
            {
                cost= 0.5 + 0.5 * sqrt(1 + ((h_1-h_2)*(h_1-h_2)));

            }
            else
            {
                cost= -0.5 + 1.5 * sqrt(1 + ((h_1-h_2)*(h_1-h_2)));
            }
            if(dis[ss_r+1][ss_c]>dis[ss_r][ss_c]+cost)
            {
                dis[ss_r+1][ss_c]=dis[ss_r][ss_c]+cost;
                qq.push(node(dis[ss_r+1][ss_c],ss_r+1,ss_c));
            }
        }
        if(ss_r-1>=1)
        {
            dd h_1=hardness[ss_r][ss_c];
            dd h_2=hardness[ss_r-1][ss_c];
            dd cost;
            if(h_1>h_2)
            {
                cost= 0.5 + 0.5 * sqrt(1 + ((h_1-h_2)*(h_1-h_2)));

            }
            else
            {
                cost= -0.5 + 1.5 * sqrt(1 + ((h_1-h_2)*(h_1-h_2)));
            }
            if(dis[ss_r-1][ss_c]>dis[ss_r][ss_c]+cost)
            {
                dis[ss_r-1][ss_c]=dis[ss_r][ss_c]+cost;
                qq.push(node(dis[ss_r-1][ss_c],ss_r-1,ss_c));
            }
        }
        if(ss_c+1<=c)
        {
            dd h_1=hardness[ss_r][ss_c];
            dd h_2=hardness[ss_r][ss_c+1];
            dd cost;
            if(h_1>h_2)
            {
                cost= 0.5 + 0.5 * sqrt(1 + ((h_1-h_2)*(h_1-h_2)));

            }
            else
            {
                cost= -0.5 + 1.5 * sqrt(1 + ((h_1-h_2)*(h_1-h_2)));
            }
            if(dis[ss_r][ss_c+1]>dis[ss_r][ss_c]+cost)
            {
                dis[ss_r][ss_c+1]=dis[ss_r][ss_c]+cost;
                qq.push(node(dis[ss_r][ss_c+1],ss_r,ss_c+1));
            }
        }
        if(ss_c-1>=1)
        {
            dd h_1=hardness[ss_r][ss_c];
            dd h_2=hardness[ss_r][ss_c-1];
            dd cost;
            if(h_1>h_2)
            {
                cost= 0.5 + 0.5 * sqrt(1 + ((h_1-h_2)*(h_1-h_2)));

            }
            else
            {
                cost= -0.5 + 1.5 * sqrt(1 + ((h_1-h_2)*(h_1-h_2)));
            }
            if(dis[ss_r][ss_c-1]>dis[ss_r][ss_c]+cost)
            {
                dis[ss_r][ss_c-1]=dis[ss_r][ss_c]+cost;
                qq.push(node(dis[ss_r][ss_c-1],ss_r,ss_c-1));
            }
        }
    }
}
int main()
{
    scl(tes);
    FOR(cas,tes)
    {
        printf("Case %lld:\n",cas);
        FOR(i,100)
        {
            FOR(j,100)
            {
                hardness[i][j]=0.00;
            }
        }
        scl(r);
        scl(c);
        FOR(i,r)
        {
            FOR(j,c)
            {
                scd(hardness[i][j]);
            }
        }
        scl(q);
        FOR(i,q)
        {
            scl(s_r);
            scl(s_c);
            scl(d_r);
            scl(d_c);
            djixtra();
            printf("%0.6lf\n",dis[d_r][d_c]);
        }
    }
    return 0;
}
