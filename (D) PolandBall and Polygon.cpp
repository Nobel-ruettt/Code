#include <bits/stdc++.h>
#define si(n) scanf("%d",&n);
#define pi(n) printf("%d\n",n);
#define pl(n) printf("%lld\n",n);
#define sl(n) scanf("%lld",&n);
#define sd(n) scanf("%lf",&n);
#define pd(n) printf("%lf\n",n);
#define ss(s) scanf("%s",s);
#define ps(s) printf("%s\n",s);
#define pb push_back
#define ll long long int
#define maxn 1000005
#define sqrtn 317
#define maxm 1000005
#define minv(a,b,c) min(a,min(b,c))
#define pii pair<int,int>
#define pll pair<ll,ll>
#define eps 1e-9
#define mod 1000000007
#define psi pair < string,ll>
#define mp make_pair
#define BLOCK 450
using namespace std;

int arr[maxn];
ll tree[4*maxn];

void update_tree(int index, int l,int r, int x)
{

    if(l==r&&l==x)
    {
 		tree[index]++;
        return ;
    }
    int mid=(l+r)/2;
    if(x <= mid)
    {
        update_tree(2*index,l,mid,x);
    }
    else
    {
        update_tree(1+2*index,mid+1,r,x);
    }
    tree[index]=tree[2*index]+tree[1+2*index];
}
ll query(int index,int l,int r,int ql,int qr)
{
	//rintf("query %d %d %d %d\n",l,r,ql,qr);
	if(ql>qr)
		return 0;
 	if(l>=ql && r<=qr)
 		return tree[index];
 	int mid=(l+r)/2;
	if(qr<=mid)
	{
	     return query(2*index,l,mid,ql,qr);
	}
	if(ql>mid)
	{
	     return query((2*index)+1,mid+1,r,ql,qr);
	}
	else
	{
	    ll lef=query(2*index,l,mid,ql,qr);
	    ll rig=query(2*index+1,mid+1,r,ql,qr);
		return lef+rig;
	}
}

int main()
{
	int n,k;
	si(n);si(k);
	k=min(k,n-k);
	int node=1;
	ll ans=1;

	for(int i=1;i<=n;i++)
	{

		//printf("%d ",node);
		if(node+k>n)
		{
			ans+=query(1,1,n,node+1,n);
			ans+=query(1,1,n,1,node+k-n-1);
			update_tree(1,1,n,node);
			node=node+k-n;
			update_tree(1,1,n,node);
		}
		else
		{
			//printf("inside else %d %d ",node+1,node+k-1);
			ans+=query(1,1,n,node+1,node+k-1);
			//printf("%lld\n",query(1,1,n,node+1,node+k-1));
			update_tree(1,1,n,node);
			node=node+k;
			update_tree(1,1,n,node);
		}
		ans++;
		printf("%lld ",ans);
	}
}
