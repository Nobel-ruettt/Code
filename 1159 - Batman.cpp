#include <bits/stdc++.h>
#define ll long long
using namespace std;
string A,B,L;
ll dp[55][55][55];
ll visited[55][55][55];
ll calcLCS(ll i,ll j,ll k)
{
    if(i==A.size() or j==B.size() or k==L.size())
    {
        return 0;
    }
    if(visited[i][j][k])
    {
        return dp[i][j][k];
    }
    int ans=0;
    if(A[i]==B[j] && A[i]==L[k])
    {
        ans=1+calcLCS(i+1,j+1,k+1);
    }
    else
    {
        int val1=calcLCS(i+1,j,k);
        int val2=calcLCS(i,j+1,k);
        int val3=calcLCS(i,j,k+1);
        ans=max(val1,max(val2,val3));
    }
    visited[i][j][k]=1;
    dp[i][j][k]=ans;
    return dp[i][j][k];
}
int main()
{
    ll tes;
    cin>>tes;
    for(ll cas=1; cas<=tes; cas++)
    {
        memset(visited,0,sizeof visited);
        cin>>A>>B>>L;
        printf("Case %lld: %lld\n",cas,calcLCS(0,0,0));
    }
    return 0;

}
