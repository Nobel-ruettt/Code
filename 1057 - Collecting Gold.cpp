#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pi pair<ll,ll>
#define sc(n) scanf("%d",&n)
ll Set(ll N,ll pos){return N=N | (1<<pos);}
ll reset(ll N,ll pos){return N= N & ~(1<<pos);}
bool check(ll N,ll pos){return (bool)(N & (1<<pos));}
ll n,m;
string grid[22];
pi initial_pos;
pi pos_gold[20];
ll total_gold,maximum;
ll dp[20][1<<17];
void in_grid()
{
    total_gold=1;
    for(ll i=1; i<=n; i++)
    {
        cin>>grid[i];
        for(ll j=0; j<grid[i].size(); j++)
        {
            if(grid[i][j]=='x')
            {
                initial_pos.first=i;
                initial_pos.second=j+1;
            }
            if(grid[i][j]=='g')
            {
                pos_gold[total_gold].first=i;
                pos_gold[total_gold].second=j+1;
                total_gold++;
            }
        }
    }
    pos_gold[0]=initial_pos;
    maximum=1<<total_gold;
    maximum--;
//    cout<<maximum<<endl;
//    cout<<total_gold<<endl;
//    for(ll i=0;i<total_gold;i++)
//    {
//        cout<<pos_gold[i].first<<" "<<pos_gold[i].second<<endl;
//    }
}
ll solve(ll last,ll mask)
{
    if(mask==maximum)
    {
        ll f=labs(pos_gold[last].first-initial_pos.first);
        ll s=labs(pos_gold[last].second-initial_pos.second);
        return max(f,s);
    }
    if(dp[last][mask]!=-1)
    {
        return dp[last][mask];
    }
    ll maxi=LLONG_MAX;
    for(ll i=0;i<total_gold;i++)
    {
        if(check(mask,i)==0)
        {
           ll f=labs(pos_gold[last].first-pos_gold[i].first);
           ll s=labs(pos_gold[last].second-pos_gold[i].second);
           ll ans=max(f,s)+solve(i,Set(mask,i));
           if(ans<maxi)
           {
               maxi=ans;
           }
        }
    }
    return dp[last][mask]=maxi;

}
int main()
{
    ll tes;
    scanf("%lld",&tes);
    for(ll cas=1; cas<=tes; cas++)
    {
        scanf("%lld%lld",&n,&m);
        in_grid();
        memset(dp,-1,sizeof dp);
        ll ans=solve(0,1);
        printf("Case %lld: %lld\n",cas,ans);
    }
    return 0;
}
