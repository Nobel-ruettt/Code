#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <string>
#include <map>
#include <stack>
#include <vector>
#include <set>
#include <queue>
using namespace std;
/***template***/
#define ll                   int
#define dd                   double
#define scl(n)               scanf("%d",&n)
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
ll n,q,timerr,k,x;
ll colours[MAXN];
ll starting[MAXN];
ll finish[MAXN];
bool seg[2*4*MAXN+10][101];
vector<ll>graph[MAXN];
stack<pi >st;
void cle()
{
    FOR(i,n)
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
    FOR(i,n)
    {
        scl(colours[i]);
    }
}
void in_edges()
{
    ll u;
    FOOR(i,2,n)
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
//void build(ll n,ll b,ll e)
//{
//    if(b==e)
//    {
//        seg[n].l=b;
//        seg[n].r=e;
//        FOR(i,100)
//        {
//            seg[n].col[i]=0;
//        }
//        return ;
//    }
//    ll mid=(b+e)/2;
//    build(n*2,b,mid);
//    build(n*2+1,mid+1,e);
//    seg[n].l=b;
//    seg[n].r=e;
//    FOR(i,100)
//    {
//        seg[n].col[i]=0;
//    }
//}
void update1(ll coll,ll node,ll l,ll r,ll pos)
{
    if(l>=pos && r<=pos)
    {
        seg[node][coll]^=1;
        return ;
    }
    if(l>pos || r<pos)
    {
        return ;
    }
    ll mid=(l+r)/2;
    update1(coll,node*2,l,mid,pos);
    update1(coll,node*2+1,mid+1,r,pos);
    seg[node][coll]=seg[node*2][coll]^seg[node*2+1][coll];
}
bool query(ll coll,ll node,ll l,ll r,ll i,ll j)
{
    if(l>=i && r<=j)
    {
        return seg[node][coll];
    }
    if(l>j || r<i)
    {
        return 0;
    }
    ll mid=(l+r)/2;
    return query(coll,node*2,l,mid,i,j)^query(coll,node*2+1,mid+1,r,i,j);
}
int main()
{
    while(scanf("%d %d",&n,&q)==2)
    {
        cle();
        in_colours();
        in_edges();
        dfs();
        memset(seg,0,sizeof seg);
        FOR(i,n)
        {
            update1(colours[i],1,1,2*n,starting[i]);
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
                     bool ans=query(i,1,1,2*n,starting[x],finish[x]);
                     if(ans)
                     {
                         sum++;
                     }
                }
                printf("%d\n",sum);
            }
            else
            {
                update1(colours[x],1,1,2*n,starting[x]);
                colours[x]=k;
                update1(colours[x],1,1,2*n,starting[x]);
            }
        }
    }
    return 0;
}
/*
9 100
1 2 2 3 3 4 5 3 3
1 1 2 2 3 3 5 5
*/
