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
#define MAXN                 200005
#define pii                  3.1415926536
#define mod                  1000000007
#define eps                  0.0000000001
#define inf                  900000000000000000
ll Set(ll n,ll pos)
{
    return n=n|(1<<pos);
}
ll reset(ll n,ll pos)
{
    return n=n&~(1<<pos);
}
bool check(ll n,ll pos)
{
    return (bool)(n&(1<<pos));
}
/***template***/
struct tree
{
    ll l,r,sum,un,inv;
} seg[4*2*MAXN];
ll n,par,timerr;
vector<ll>graph[MAXN];
ll light[MAXN],s[MAXN],f[MAXN];
void build(ll n,ll b,ll e)
{
    if(b==e)
    {
        seg[n].l=b;
        seg[n].r=e;
        seg[n].sum=0;
        seg[n].un=0;
        seg[n].inv=0;
        return ;
    }
    ll mid=(b+e)/2;
    build(n*2,b,mid);
    build(n*2+1,mid+1,e);
    seg[n].l=b;
    seg[n].r=e;
    seg[n].sum=0;
    seg[n].un=0;
    seg[n].inv=0;
}
void point_update(ll n,ll pos,ll val)
{
    if(seg[n].l>=pos && seg[n].r<=pos)
    {
        if(val==-1)
        {
            seg[n].un=1;
            seg[n].sum=0;
        }
        else if(val==0)
        {
            seg[n].sum=0;
        }
        else if(val==1)
        {
            seg[n].sum=1;
        }
        return ;
    }
    if(seg[n].l>pos || seg[n].r<pos)
    {
        return ;
    }
    point_update(n*2,pos,val);
    point_update(n*2+1,pos,val);
    seg[n].sum=seg[n*2].sum+seg[n*2+1].sum;
    seg[n].un=seg[n*2].un+seg[n*2+1].un;
}
void dfs(ll parr,ll source)
{
    s[source]=timerr;
    timerr++;
    LOOP(i,graph[source].size())
    {
        ll adj=graph[source][i];
        if(adj!=parr)
        {
            dfs(source,adj);
        }
    }
    f[source]=timerr;
    point_update(1,f[source],-1);
    point_update(1,s[source],light[source]);
    timerr++;
}
void check_seg(ll n)
{
    FOR(i,n)
    {
        cout<<seg[i].inv<<" "<<seg[i].un<<" "<<seg[i].sum<<endl;
    }
}
void push_down(ll n)
{
    if(seg[n].inv%2==1)
    {
        seg[n].sum=((seg[n].r-seg[n].l+1)-seg[n].un)-seg[n].sum;
    }
    seg[n*2].inv+=seg[n].inv;
    seg[n*2+1].inv+=seg[n].inv;
    seg[n].inv=0;
}
void updown(ll n)
{
    seg[n].sum=seg[n*2].sum+seg[n*2+1].sum;
}
void update(ll n,ll i,ll j)
{
    if(seg[n].l>=i && seg[n].r<=j)
    {
        seg[n].inv++;
        if(seg[n].l!=seg[n].r)
        {
            push_down(n);
        }
        else
        {
            if(seg[n].inv%2==1)
            {
                seg[n].sum=((seg[n].r-seg[n].l+1)-seg[n].un)-seg[n].sum;
            }
            seg[n].inv=0;
        }
        return ;
    }
    if(seg[n].l>j || seg[n].r<i)
    {
        if(seg[n].l!=seg[n].r)
        {
            push_down(n);
        }
        else
        {
            if(seg[n].inv%2==1)
            {
                seg[n].sum=((seg[n].r-seg[n].l+1)-seg[n].un)-seg[n].sum;
            }
            seg[n].inv=0;
        }
        return ;
    }
    push_down(n);
    update(n*2,i,j);
    update(n*2+1,i,j);
    updown(n);
}
ll query(ll n,ll i,ll j)
{
    if(seg[n].l>=i && seg[n].r<=j)
    {
        if(seg[n].l!=seg[n].r)
        {
            push_down(n);
        }
        else
        {
            if(seg[n].inv%2==1)
            {
                seg[n].sum=((seg[n].r-seg[n].l+1)-seg[n].un)-seg[n].sum;
            }
            seg[n].inv=0;
        }
        return seg[n].sum;
    }
    if(seg[n].l>j || seg[n].r<i)
    {
        if(seg[n].l!=seg[n].r)
        {
            push_down(n);
        }
        else
        {
            if(seg[n].inv%2==1)
            {
                seg[n].sum=((seg[n].r-seg[n].l+1)-seg[n].un)-seg[n].sum;
            }
            seg[n].inv=0;
        }
        return 0;
    }
    push_down(n);
    ll ans=query(n*2,i,j)+query(n*2+1,i,j);
    updown(n);
    return ans;
}
int main()
{
    scl(n);
    timerr=1;
    for(ll i=2; i<=n; i++)
    {
        scl(par);
        graph[i].pb(par);
        graph[par].pb(i);
    }
    FOR(i,n)
    {
        scl(light[i]);
    }
    build(1,1,2*n);
    dfs(-1,1);
    ll q;
    scl(q);
    FOR(i,q)
    {
        string com;
        ll val;
        cin>>com>>val;
        if(com=="get")
        {
            cout<<query(1,s[val],f[val])<<endl;
        }
        else
        {
            update(1,s[val],f[val]);
        }
    }
    return 0;
}
