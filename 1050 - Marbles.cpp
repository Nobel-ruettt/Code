#include <bits/stdc++.h>
using namespace std;
#define ll int
ll tes,red,blue;
double dp[510][510][2];
void cle()
{
    for(ll i=0;i<=509;i++)
    {
        for(ll j=0;j<=509;j++)
        {
            dp[i][j][0]=-1.000;
            dp[i][j][1]=-1.000;
        }
    }
}
double solve(ll r,ll b,ll chance)
{
    if(dp[r][b][chance]> -0.5)
    {
        return dp[r][b][chance];
    }
    if(chance==1)
    {
        if(r+b==1)
        {
            if(r==0&&b==1)
            {
                return dp[r][b][chance]=1.0000000;
            }
            else if(r==1&&b==0)
            {
                return dp[r][b][chance]=0.0000000;
            }
        }
        else if(r+b>1)
        {
            if(r>0 && b>0)
            {
                double sum=0.00000;
                sum+=(((double)r/(double)(r+b))*(solve(r-1,b,0)));
                sum+=(((double)b/(double)(r+b))*(solve(r,b-1,0)));
                return dp[r][b][chance]=sum;
            }
            else if(r>0 && b==0)
            {
                double sum=0.00000;
                sum+=(((double)r/(double)(r+b))*(solve(r-1,b,0)));
                return dp[r][b][chance]=sum;
            }
            else if(r==0 && b>0)
            {
                double sum=0.00000;
                sum+=(((double)b/(double)(r+b))*(solve(r,b-1,0)));
                return dp[r][b][chance]=sum;
            }
        }
    }
    else if(chance==0)
    {
        if(r+b==1)
        {
            if(r>0 && b==0)
            {
                return dp[r][b][chance]=1.0000;
            }
            else if(r==0 && b>0)
            {
                return dp[r][b][chance]=0.000000;
            }
        }
        else if(r+b>1)
        {
            if(r>0 && b>0)
            {
                return dp[r][b][chance]=solve(r,b-1,1);
            }
            else if(r>0 && b==0)
            {
                return dp[r][b][chance]=0.0000;
            }
            else if(r==0 && b>0)
            {
                return dp[r][b][chance]=solve(r,b-1,1);
            }
        }
    }
}
int main()
{
    scanf("%d",&tes);
    cle();
    for(ll cas=1;cas<=tes;cas++)
    {
          scanf("%d%d",&red,&blue);
          if(red==0 && blue==0)
          {
              printf("Case %d: 1.000000\n",cas);
              continue;
          }
          double ans=solve(red,blue,1);
          printf("Case %d: %0.6lf\n",cas,ans);
    }
    return 0;
}
