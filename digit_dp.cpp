#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
int aa,bb,la,lb;
int dp[20][2][2];
char a[20],b[20];
int go(int pos,int sf,int gf)
{
	if(pos==lb)
	{
		return 1;//do something;
	}

	if(dp[pos][sf][gf]!=-1)
	return dp[pos][sf][gf];
	int st,ed,ret,i;

	if(sf)   // upperlimit theke choto ase kina cheak kortesi,jodi choto thake tahole end hobe 9 otherwise b[pos]
	ed = 9;
	else
	ed = b[pos]-'0';

	if(gf)
	st = 0;
	else
	st = a[pos]-'0'; //lower limit theke boro ase kina chek kortesi,jodi boro hoi tahole start hobe 0 otherwise a[pos]

	ret = 0;
	for(i=st;i<=ed;i++)
	ret+=go(pos+1,sf or (i<ed),gf or (i>st));

	return dp[pos][sf][gf] = ret;

}

int main()
{
	memset(dp,-1,sizeof dp);
	int i;
	 scanf("%d %d",&aa,&bb);
	 sprintf(a,"%d",aa);
	 sprintf(b,"%d",bb);
        la=strlen(a);
		lb=strlen(b);
	 reverse(a,a+la);
	 for(i=la;i<lb;i++)
	 a[i]='0';
	 reverse(a,a+lb);
	 int ans = go(0,0,0);
	 cout<<ans<<endl;
}
