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
ll k,n,m;
char creator[110][30];
char gang_name[110][30];
char matrix[60][60];
vector<ll>character_ase[110];
ll visited[110][2505];
vector<ll>creators[110];
vector<ll>gang_names[110];
int main()
{
    scl(k);
    FOR(i,k)
    {
        scanf(" %s %s",creator[i],gang_name[i]);
        for(ll j=0; j<strlen(creator[i]); j++)
        {
            if(creator[i][j]>='a' && creator[i][j]<='z')
            {
                creators[i].pb(creator[i][j]-'a'+10);
            }
            else if(creator[i][j]>='0' && creator[i][j]<='9')
            {
                creators[i].pb(creator[i][j]-'0');
            }
        }
        for(ll j=0; j<strlen(gang_name[i]); j++)
        {
            if(gang_name[i][j]>='a' && gang_name[i][j]<='z')
            {
                gang_names[i].pb(gang_name[i][j]-'a'+10);
            }
            else if(gang_name[i][j]>='0' && gang_name[i][j]<='9')
            {
                gang_names[i].pb(gang_name[i][j]-'0');
            }
        }
        sorted(creators[i]);
        sorted(gang_names[i]);
//        LOOP(j,creators[i].size())
//        {
//            cout<<creators[i][j]<<" ";
//        }
//        cout<<endl;
//        LOOP(j,gang_names[i].size())
//        {
//            cout<<gang_names[i][j]<<" ";
//        }
//        cout<<endl;
    }
    ll maxi=-1;
    ll maxi_ind=-1;
    FOR(i,k)
    {
        scl(n);
        scl(m);
        FOR(j,n)
        {
            scanf(" %s",matrix[j]);
            for(ll kk=0; kk<m; kk++)
            {
                if(matrix[j][kk]>='a' && matrix[j][kk]<='z')
                {
                    character_ase[i].pb(matrix[j][kk]-'a'+10);
                }
                else if(matrix[j][kk]>='0' && matrix[j][kk]<='9')
                {
                    character_ase[i].pb(matrix[j][kk]-'0');
                }
            }
        }
        sorted(character_ase[i]);
//        LOOP(j,character_ase[i].size())
//        {
//            cout<<character_ase[i][j]<<" ";
//        }
//        cout<<endl;
        ll total_cnt=0;
        while(1)
        {
            ll cnt=0;
            bool f=0;
            LOOP(j,character_ase[i].size())
            {
                if(visited[i][j]==1)continue;
                if(visited[i][j]==0)
                {
                    if(character_ase[i][j]==creators[i][cnt])
                    {
                        visited[i][j]=1;
                        cnt++;
                        if(cnt==creators[i].size())
                        {
                            f=1;
                            break;
                        }
                    }
                }
            }
            if(f==0)
            {
               break;
            }
            cnt=0;
            f=0;
            LOOP(j,character_ase[i].size())
            {
                if(visited[i][j]==1)continue;
                if(visited[i][j]==0)
                {
                    if(character_ase[i][j]==gang_names[i][cnt])
                    {
                        visited[i][j]=1;
                        cnt++;
                        if(cnt==gang_names[i].size())
                        {
                            f=1;
                            break;
                        }
                    }
                }
            }
            if(f==0)
            {
                break;
            }
            total_cnt++;
        }
        if(total_cnt>maxi)
        {
            maxi=total_cnt;
            maxi_ind=i;
        }
    }
    printf("%s %s\n",creator[maxi_ind],gang_name[maxi_ind]);
    return 0;
}

