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
string s;
ll tes;
ll ans[30];
bool vis[30];
bool vis2[30];
vector<ll>nodes;
vector<ll>st;
int main()
{
    scl(tes);
    FOR(cas,tes)
    {
        LOOP(i,30)
        {
            vis[i]=0;
            vis2[i]=0;
            ans[i]=0;
        }
        nodes.clear();
        st.clear();
        cin>>s;
        LOOP(i,s.size())
        {
            if(vis[s[i]-'A']==0)
            {
                vis[s[i]-'A']=1;
                nodes.pb(s[i]-'A');
            }
        }
        sorted(nodes);
        LOOP(i,nodes.size())
        {
//            cout<<nodes[i]<<" ";
            ans[nodes[i]]=2;
//            cout<<nodes[i]<<" "<<ans[nodes[i]]<<endl;
        }
        st.pb(s[0]-'A');
//        cout<<endl<<endl;
        for(ll i=1;i<s.size();i++)
        {
            ll now_char=s[i]-'A';
            ll now_front=st[st.size()-1];
//            cout<<now_char<<" "<<now_front<<endl;
            if(now_front!=now_char)
            {
                ans[now_front]++;
                st.pb(now_char);
            }
            else
            {
                st.pop_back();
            }
        }
        printf("Case %lld\n",cas);
        LOOP(i,nodes.size())
        {
            printf("%c = ",nodes[i]+'A');
            if(nodes[i]==s[0]-'A')
            {
                ans[nodes[i]]--;
            }
            cout<<ans[nodes[i]]-1<<endl;
        }
    }
    return 0;
}
