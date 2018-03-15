#include <cstdio>
#include <cstring>
#include <vector>
#include<iostream>
#include <algorithm>
using namespace std;
const int  N = 1e2 + 10, M = 1e4 , mod = 1e9 + 7, inf = 2e9;
int T,n,x;
double dp[M+20],f,p;
int main()
{
    int cas = 1;
    scanf("%d",&T);
    while(T--)
    {
        for(int i=0; i<=M; i++) dp[i] = -1;
        dp[0] = 0;
        scanf("%lf%d",&p,&n);
        for(int i=1; i<=n; i++)
        {
            scanf("%d%lf",&x,&f);
            for(int j=M; j>=x; j--)
            {
                if(dp[j-x]==-1) continue;
                ///cout<<j<<endl;
                if(dp[j]==-1) dp[j] = dp[j-x] + (1.0-dp[j-x])*f;
                else dp[j] = min(dp[j],dp[j-x] + (1.0-dp[j-x])*f);
            }
        }
        int ans = 0;///cout<<dp[M]<<endl;
        for(int i=0; i<=M; i++)
        {
            if(dp[i]!=-1&&dp[i] <= p) ans = i;
        }
        printf("Case %d: %d\n",cas++,ans);
    }
    return 0;
}
