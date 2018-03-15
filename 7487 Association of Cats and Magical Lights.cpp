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
#define MAXN                 300005
#define pii                  3.1415926536
#define mod                  1000000007
#define eps                  0.0000000001
#define inf                  900000000
/***template***/
ll nn,q,timerr,k,x;
ll colours[MAXN];
ll starting[MAXN];
ll finish[MAXN];
struct tree
{
    ll l,r,cnt;
};
tree seg[102][2*4*MAXN+10];
vector<ll>graph[MAXN];
stack<pi >st;
void cle()
{
    FOR(i,nn)
    {
        graph[i].clear();
    }
    timerr=0;
    while(!st.empty())
    {
        st.pop();
    }
}
void in_colours()
{
    FOR(i,nn)
    {
        scl(colours[i]);
    }
}
void in_edges()
{
    ll u;
    FOOR(i,2,nn)
    {
        scl(u);
        graph[u].pb(i);
    }
}
void dfs()
{
    st.push(pi(1,0));
    starting[1]= ++timerr;
    while(!st.empty())
    {
        pi u=st.top();
        st.pop();
        if(u.vv==graph[u.uu].size())
        {
            finish[u.uu]= ++timerr;
            continue;
        }
        st.push(pi(u.uu,u.vv+1));
        st.push(pi(graph[u.uu][u.vv],0));
        starting[graph[u.uu][u.vv]]=++timerr;
    }
}
void build(ll col,ll node,ll b,ll e)
{
    if(b==e)
    {
        seg[col][node].l=b;
        seg[col][node].r=e;
        seg[col][node].cnt=0;
        return ;
    }
    ll mid=(b+e)/2;
    build(col,node*2,b,mid);
    build(col,node*2+1,mid+1,e);
    seg[col][node].l=b;
    seg[col][node].r=e;
    seg[col][node].cnt=0;
}
void update(ll col,ll node,ll pos,ll val)
{
    if(seg[col][node].l>=pos && seg[col][node].r<=pos)
    {
        seg[col][node].cnt=val;
        return ;
    }
    if(seg[col][node].l>pos || seg[col][node].r<pos)
    {
        return ;
    }
    update(col,node*2,pos,val);
    update(col,node*2+1,pos,val);
    seg[col][node].cnt=seg[col][node*2].cnt+seg[col][node*2+1].cnt;
}
ll query(ll col,ll node,ll i,ll j)
{
    if(seg[col][node].l>=i && seg[col][node].r<=j)
    {
        return seg[col][node].cnt;
    }
    if(seg[col][node].l>j || seg[col][node].r<i)
    {
        return 0;
    }
    return query(col,node*2,i,j)+query(col,node*2+1,i,j);
}
int main()
{
    while(scanf("%lld %lld",&nn,&q)==2)
    {
        cle();
        in_colours();
        in_edges();
        dfs();
        FOR(i,100)
        {
            build(i,1,1,2*nn);
        }
        FOR(i,nn)
        {
            update(colours[i],1,starting[i],1);
        }
        FOR(i,q)
        {
            scl(k);
            scl(x);
            if(k==0)
            {
                ll sum=0;
                FOR(i,100)
                {
                     ll ans=query(i,1,starting[x],finish[x]);
                     if(ans==0)
                     {
                         continue;
                     }
                     sum+=(ans%2);
                }
                printf("%lld\n",sum);
            }
            else
            {
                update(colours[x],1,starting[x],0);
                colours[x]=k;
                update(colours[x],1,starting[x],1);
            }
        }
    }
    return 0;
}
