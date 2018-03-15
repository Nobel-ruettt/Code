#include <bits/stdc++.h>
using namespace std;
#define ll int
/*******for_bitwise********/
inline bool bitcheck(ll x,ll pos)
{
    return (x>>pos) & 1;
}
inline int biton(ll x,ll pos)
{
    return x | (1<<pos);
}
/************for_bitwise*********/
/************for_pre*****************/
vector<pair<ll,ll> >queens_safe_pos[100];
vector<pair<ll,ll> >q;
ll count1=0;
map<ll,bool>diagonal1;
map<ll,bool>diagonal2;
bool column[200];
bool rows[200];
/**********for_pre*******************/
string s[10];
vector<pair<ll,ll> >queens_actual_pos;
bool is_safe(ll i,ll j)
{
    if(diagonal1[i+j]==0)
    {
        if(diagonal2[i-j]==0)
        {
            if(column[j]==0)
            {
                if(rows[i]==0)
                {
                    return 1;
                }
            }
        }
    }
    return 0;
}
void block(ll i,ll j)
{
    diagonal1[i+j]=1;
    diagonal2[i-j]=1;
    column[j]=1;
    rows[i]=1;
}
void unblock(ll i,ll j)
{
    diagonal1[i+j]=0;
    diagonal2[i-j]=0;
    column[j]=0;
    rows[i]=0;
}
void solve(ll row)
{
    if(row==8)
    {
        queens_safe_pos[count1]=q;
        count1++;
        return ;
    }
    for(ll j=0; j<8; j++)
    {
        if(is_safe(row,j)==1)
        {
            q.push_back(make_pair(row,j));
            block(row,j);
            solve(row+1);
            unblock(row,j);
            q.pop_back();
        }
    }
}
ll now_safe;
ll dp[10][1<<8+2];
ll cost(ll a,ll b)
{
    ll dx = queens_actual_pos[a].first - queens_safe_pos[now_safe][b].first;
    ll dy = queens_actual_pos[a].second - queens_safe_pos[now_safe][b].second;
    if (dx == 0 && dy == 0) return 0;
    if (dx == 0 || dy == 0) return 1;
    if (fabs(dx) == fabs(dy)) return 1;
    return 2;
}
int solve1(int r,int mask)
{
    if(r==8) return 0;
    int &ret=dp[r][mask];
    if(ret != -1) return ret;
    ret = INT_MAX;
    int i;
    for(i=0;i<8;i++)
    {
        if(mask & 1<<i)
        {
            continue;
        }
        ret = min(ret,cost(i,r) + solve1(r+1,biton(mask,i)));
    }
    return ret;
}
int main()
{
    solve(0);
    ll tes;
    scanf("%d",&tes);
    for(ll cas=1; cas<=tes; cas++)
    {
        queens_actual_pos.clear();
        for(ll i=0; i<8; i++)
        {
            cin>>s[i];
            for(ll j=0; j<s[i].size(); j++)
            {
                if(s[i][j]=='q')
                {
                    queens_actual_pos.push_back(make_pair(i,j));
                }
            }
        }
        printf("Case %d: ",cas);
        ll minimum=INT_MAX;
        for(ll i=0; i<count1; i++)
        {
            now_safe=i;
            memset(dp,-1,sizeof dp);
            if(solve1(0,0)<minimum)
            {
                minimum=solve1(0,0);
            }
        }
        printf("%d\n",minimum);
    }
    return 0;
}
