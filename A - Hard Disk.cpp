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
#define eps                  0.0000000001
/***template***/
string s,s1;
ll brand,month;
ll prize[210][210];
ll dp[210][210];
ll brand_used[210][210];
vector<string>brands;
vector<string>anss;
ll solve(ll now_month,ll prev_brand)
{
    if(now_month>month)
    {
        return 0;
    }
    if(dp[now_month][prev_brand]!=-1)
    {
        return dp[now_month][prev_brand];
    }
    if(prev_brand==0)
    {
        ll minimum=LLONG_MAX;
        ll bran_used;
        FOR(i,brand)
        {
            ll ans=prize[i][now_month]+solve(now_month+1,i);
            if(ans<minimum)
            {
                minimum=ans;
                bran_used=i;
            }
        }
        dp[now_month][prev_brand]=minimum;
        brand_used[now_month][prev_brand]=bran_used;
        return dp[now_month][prev_brand];
    }
    else
    {
        ll minimum=LLONG_MAX;
        ll bran_used;
        ll ans=solve(now_month+1,prev_brand);
        if(ans<minimum)
        {
            minimum=ans;
            bran_used=prev_brand;
        }
        FOR(i,brand)
        {
            if(i==prev_brand)
            {
                continue;
            }
            ll ans=((prize[i][now_month])-(prize[prev_brand][now_month]-100))+solve(now_month+1,i);
            if(ans<minimum)
            {
                minimum=ans;
                bran_used=i;
            }
        }
        dp[now_month][prev_brand]=minimum;
        brand_used[now_month][prev_brand]=bran_used;
        return dp[now_month][prev_brand];
    }
}
void solve2(ll now_month,ll prev_brand)
{
    if(now_month>month)
    {
        return;
    }
    anss.pb(brands[brand_used[now_month][prev_brand]-1]);
    solve2(now_month+1,brand_used[now_month][prev_brand]);
}
int main()
{
    while(1)
    {
        cin>>s;
        if(s=="TheEnd")
        {
            cout<<s;
            break;
        }
        scl(brand);
        scl(month);
        brands.clear();
        anss.clear();
        FOR(i,brand)
        {
            cin>>s1;
            brands.pb(s1);
            FOR(j,month)
            {
                scl(prize[i][j]);
            }
        } Walking Path
        memset(dp,-1,sizeof dp);
        ll ans=solve(1,0);
        cout<<s<<endl;
        printf("Tk %lld\n",ans);
        solve2(1,0);
        ll count1=1;
        for(ll i=1;i<anss.size();i++)
        {
            if(anss[i]==anss[i-1])
            {
                count1++;
            }
            else
            {
                cout<<anss[i-1];
                printf(" for %lld month(s)\n",count1);
                count1=1;
            }
        }
        cout<<anss[anss.size()-1];
        printf(" for %lld month(s)\n",count1);
        printf("\n");
    }
    return 0;
}
