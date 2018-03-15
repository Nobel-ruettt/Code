#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll ab(ll x)
{
	if(x<0) return -x;
	return x;
}
ll gcd(ll x,ll y)
{
	if(y==0) return x;
	return gcd(y,x%y);
}
int main()
{
	int t,j;
	ll a[4][2],area,b,ans;
	cin>>t;
	int val=0;
	while(t--)
	{
      val++;
	  area=0;
	  b=4;
	  for(int i=0;i<4;i++)
	    cin>>a[i][0]>>a[i][1];
	  for(int i=0;i<4;i++)
	  {
	     j=(i+1)%4;
	     area+=((a[i][0]*a[j][1])-(a[j][0]*a[i][1]));
	     b+=gcd((ab(a[i][0]-a[j][0])),(ab(a[i][1]-a[j][1])))-1;
	     //cout<<area<<" "<<b<<endl;
	  }
	  area=ab(area);
	  area=area/2;
	  area++;
	  ans=b;
	  b=b/2;
	  area=area-b;
	  cout<<"Case "<<val<<": "<<ans+area<<"\n";
	}
	return 0;
}
