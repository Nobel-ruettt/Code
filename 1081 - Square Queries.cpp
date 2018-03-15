#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxi 510
ll a[maxi][maxi];
ll seg[maxi*4][maxi*4];
ll n,q,i,j,s;
void in_grid()
{
    for(ll i=1; i<=n; i++)
    {
        for(ll j=1; j<=n; j++)
        {
            scanf("%lld",&a[i][j]);
        }
    }
}
void build_y (ll vx, ll lx, ll rx, ll vy, ll ly, ll ry) {
	if (ly == ry)
		if (lx == rx)
 seg[vx][vy] = a[lx][ly];
		else
 seg[vx][vy] = max(seg[vx*2][vy] , seg[vx*2+1][vy]);
	else {
		ll my = (ly + ry) / 2;
 build_y (vx, lx, rx, vy*2, ly, my);
 build_y (vx, lx, rx, vy*2+1, my+1, ry);
 seg[vx][vy] = max(seg[vx][vy*2] , seg[vx][vy*2+1]);
	}
}

void build_x (ll vx, ll lx, ll rx) {
	if (lx != rx) {
		ll mx = (lx + rx) / 2;
 build_x (vx*2, lx, mx);
 build_x (vx*2+1, mx+1, rx);
	}
 build_y (vx, lx, rx, 1, 1, n);
}
ll sum_y (ll vx, ll vy, ll tly, ll try_, ll ly, ll ry) {
	if (ly > ry)
		return 0;
	if (ly == tly && try_ == ry)
		return seg[vx][vy];
	ll tmy = (tly + try_) / 2;
	return max(sum_y (vx, vy*2, tly, tmy, ly, min(ry,tmy))
		,sum_y (vx, vy*2+1, tmy+1, try_, max(ly,tmy+1), ry));
}

ll sum_x (ll vx, ll tlx, ll trx, ll lx, ll rx, ll ly, ll ry) {
	if (lx > rx)
		return 0;
	if (lx == tlx && trx == rx)
		return sum_y (vx, 1, 1, n, ly, ry);
	ll tmx = (tlx + trx) / 2;
	return max(sum_x (vx*2, tlx, tmx, lx, min(rx,tmx), ly, ry)
		, sum_x (vx*2+1, tmx+1, trx, max(lx,tmx+1), rx, ly, ry));
}
int  main()
{
    ll tes;
    scanf("%lld",&tes);
    for(ll cas=1; cas<=tes; cas++)
    {
        printf("Case %lld:\n",cas);
        scanf("%lld%lld",&n,&q);
        in_grid();
        build_x(1,1,n);
        for(ll k=1;k<=q;k++)
        {
            scanf("%lld%lld%lld",&i,&j,&s);
            printf("%lld\n",sum_x(1,1,n,i,i+s-1,j,j+s-1));
        }
    }
    return 0;
}
