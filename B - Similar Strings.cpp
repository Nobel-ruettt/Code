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
#define ll                   long long
#define LL                   long long
#define dd                   double
#define scl(n)               scanf("%lld",&n)
#define sl(n)                scanf("%lld",&n)
#define scd(n)               scanf("%lf",&n)
#define pi                   pair<ll,ll>
#define pll                  pair<ll,ll>
#define pb                   push_back
#define mp                   make_pair
#define uu                   first
#define vv                   second
#define fr                   first
#define sc                   second
#define FOR(i,n)             for(ll i=1;i<=n;i++)
#define LOOP(i,n)            for(ll i=0;i<n;i++)
#define FOOR(i,a,b)          for(ll i=a;i<=b;i++)
#define LOP(i,a,b)           for(ll i=a;i<b;i++)
#define sorted(s)            sort(s.begin(),s.end())
#define sortedd(s)           sort(s.begin(),s.end(),cmp)
#define reversed(s)          reverse(s.begin(),s.end())
#define contains(a,b)        (find((a).begin(), (a).end(), (b)) != (a).end())
#define MAXN                 100005
#define pii                  3.1415926536
#define mod                  1000000007
#define eps                  0.0000000001
#define inf                  9000000000000000
#define INF                  (1LL<<62)
#define mstt(a,b)            memset((a),(b),sizeof (a))
#define sz(x)                (ll)x.size()
#define maxn                 1000005
ll Set(ll n,ll pos)
{
    return n=n|(1LL<<pos);
}
ll reset(ll n,ll pos)
{
    return n=n&~(1LL<<pos);
}
bool check(ll n,ll pos)
{
    return (bool)(n&(1LL<<pos));
}
ll mul(ll a,ll b)
{
    ll c;
    c = (a%mod * b%mod)%mod;
    return c;
}
ll add(ll a,ll b)
{
    ll c;
    c = (a%mod + b%mod)%mod;
    return c;
}
ll sub(ll a,ll b)
{
    ll c;
    c = ((a%mod - b%mod)%mod + mod)%mod;
    return c;
}
ll power(ll x,ll y,ll p)
{
    ll res = 1;
    x = x % p;
    while (y > 0)
    {
        if (y & 1)
            res = (res*x) % p;
        y = y>>1;
        x = (x*x) % p;
    }
    return res;
}
ll s2, s1, t2, t1;
ll egcd(ll a, ll b)
{
    ll temp;
    if (a%b == 0)
    {
        return s1;
    }
    temp = s2 - (a/b)*s1;
    s2 = s1;
    s1 = temp;
    temp = t2 - (a/b)*t1;
    t2 = t1;
    t1 = temp;
    return egcd(b, a%b);
}
/***template***/
ll nextt[27][maxn];
ll created[maxn];
ll endmark[maxn];
vector<ll>node[maxn];
ll sz;
ll n,ans;
ll len;
char s[2000005];
void insert()
{
    ll v=0;
    for(ll i=0; i<len; i++)
    {
        ll id=s[i]-'a';
        if(created[nextt[id][v]]==0)
        {
            nextt[id][v]=++sz;
            created[nextt[id][v]]=1;
            node[v].pb(id);
        }
        v=nextt[id][v];
    }
    endmark[v]++;
}
ll search(ll pos,ll v,ll al[26],ll mask)
{
    ll now_id=s[pos]-'a';
    if(pos>=len)
    {
        return endmark[v];
    }
    ll ans1=0;
    if(al[now_id]==-1)
    {
        for(ll i=0; i<node[v].size(); i++)
        {
            ll ii=node[v][i];
            if(check(mask,ii)==0)
            {
                ll al2[26];
                for(ll j=0;j<26;j++)
                {
                    al2[j]=al[j];
                }
                 now_id=s[pos]-'a';
                 al2[now_id]=ii;
                ans1+=search(pos+1,nextt[ii][v],al2,Set(mask,ii));
            }
        }
    }
    else if(al[now_id]!=-1)
    {
        if(created[nextt[al[now_id]][v]]==1)
        {
            ans1+=search(pos+1,nextt[al[now_id]][v],al,mask);
        }
    }
    return ans1;
}
int main()
{
    scl(n);
    scanf(" %s",s);
    len=strlen(s);
    insert();
    FOR(i,n-1)
    {
        scanf(" %s",s);
        len=strlen(s);
        ll al[26];
        for(ll j=0; j<=25; j++)
        {
            al[j]=-1;
        }
        ll ans_now=search(0,0,al,0);
        ans+=ans_now;
        insert();
    }
    cout<<ans<<endl;
    return 0;
}


