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
#define maxn 205
#define MAXN 400005
#define mod 1000000009
#define INF 0x3f3f3f3f
#define pi acos(-1.0)
#define eps 1e-6
#define ll long long
using namespace std;

int n,m,k,ans,cnt,tot,flag;
int pp[maxn],num[maxn],dp[2][maxn][maxn];
struct Node
{
    int v,w,next;
} edge[maxn];

void addedge(int u,int v,int w)
{
    cnt++;
    edge[cnt].v=v;
    edge[cnt].w=w;
    edge[cnt].next=pp[u];
    pp[u]=cnt;
}
void dfs(int u,int pre)
{
    int i,j,t,v;
    for(j=0; j<=m+2; j++)
    {
        dp[0][u][j]=dp[1][u][j]=num[u];
    }
    for(i=pp[u]; i; i=edge[i].next)
    {
        v=edge[i].v;
        if(v!=pre)
        {
            dfs(v,u);
            for(j=m; j>=0; j--)
            {
                for(k=0; k<=j; k++)
                {
                    dp[0][u][j+1]=max(dp[0][u][j+1],dp[0][v][k]+dp[1][u][j-k]);
                    dp[0][u][j+2]=max(dp[0][u][j+2],dp[1][v][k]+dp[0][u][j-k]);
                    dp[1][u][j+2]=max(dp[1][u][j+2],dp[1][v][k]+dp[1][u][j-k]);
                }
            }
        }
    }
}
void solve()
{
    int i,j,t;
    dfs(1,0);
    ans=0;
    for(i=0; i<=m; i++)
    {
        ans=max(ans,dp[0][1][i]);
        ans=max(ans,dp[1][1][i]);
    }
}
int main()
{
    int i,j,t;
    while(~scanf("%d%d",&n,&m))
    {
        for(i=1; i<=n; i++)
        {
            scanf("%d",&num[i]);
        }
        int u,v;
        cnt=0;
        memset(pp,0,sizeof(pp));
        for(i=1; i<n; i++)
        {
            scanf("%d%d",&u,&v);
            addedge(u,v,1);
            addedge(v,u,1);
        }
        solve();
        for(ll i=0 ;i<=3;i++)
        {
            cout<<dp[0][5][i]<<endl;
            cout<<dp[1][5][i]<<endl;

        }
        printf("%d\n",ans);
    }
    return 0;
}
/*
5 4
2 5 5 6 7
1 2
1 3
2 4
2 5

9 3
1 3 2 3 3 5 6 3 7
1 2
1 3
2 4
2 5
4 6
4 7
5 8
5 9

*/
