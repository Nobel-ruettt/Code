#include <bits/stdc++.h>
using namespace std;
#define ll long long
string a,b;
string dp[110][110];
ll visited[110][110];
string solve(ll i,ll j)
{
	if(a[i]=='\0' or b[j]=='\0')
    {
        return "";
    }
	if(visited[i][j]!=-1)
    {
        return dp[i][j];
    }
	string ans="";
	if(a[i]==b[j])
    {
        ans.push_back(a[i]);
        ans+=solve(i+1,j+1);
    }
	else
	{
		string val1=solve(i+1,j);
		string val2=solve(i,j+1);
		if(val1.size()>val2.size())
        {
            ans=val1;
        }
        else if(val2.size()>val1.size())
        {
            ans=val2;
        }
        else if(val1.size()==val2.size())
        {
            ll check=0;
            for(ll i=0;i<val1.size();i++)
            {
                if(val1[i]<val2[i])
                {
                    check=1;
                    ans=val1;
                    break;
                }
                else if(val1[i]>val2[i])
                {
                    check=1;
                    ans=val2;
                    break;
                }
            }
            if(check==0)
            {
                ans=val1;
            }
        }
	}
	visited[i][j]=1;
	dp[i][j]=ans;
	return dp[i][j];
}
int main()
{
    ll tes;
    scanf("%lld",&tes);
    for(ll cas=1;cas<=tes;cas++)
    {
        cin>>a>>b;
        memset(visited,-1,sizeof visited);
        string ans=solve(0,0);
        if(ans=="")
        {
            printf("Case %lld: :(\n",cas);
        }
        else
        {
            printf("Case %lld: ",cas);
            cout<<ans<<endl;
        }
    }
    return 0;
}
