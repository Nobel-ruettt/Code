#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define eps 0.000000001
ll n,count1;
char type;
struct point
{
    ll x,y;
};
map<ll,map<ll,ll> >ase;
void cle()
{
    ase.clear();
    count1=0;
}
ll insideCircle(point p, point c,ll r)   // all integer version
{
    ll dx = p.x - c.x, dy = p.y - c.y;
    ll Euc = dx * dx + dy * dy, rSq = r * r;             // all integer
    return Euc < rSq ? 0 : Euc == rSq ? 1 : 2;
}
double area(ll x1,ll y1,ll x2,ll y2,ll x3,ll y3)
{
   return fabs((double)(x1*(y2-y3) + x2*(y3-y1)+ x3*(y1-y2))/2.0);
}

/* A function to check whether point P(x, y) lies inside the triangle formed
   by A(x1, y1), B(x2, y2) and C(x3, y3) */
bool isInside(ll x1,ll y1,ll x2,ll y2,ll x3,ll y3,ll x,ll y)
{
   /* Calculate area of triangle ABC */
   double A = area (x1, y1, x2, y2, x3, y3);

   /* Calculate area of triangle PBC */
   double A1 = area (x, y, x2, y2, x3, y3);

   /* Calculate area of triangle PAC */
   double A2 = area (x1, y1, x, y, x3, y3);

   /* Calculate area of triangle PAB */
   double A3 = area (x1, y1, x2, y2, x, y);

   /* Check if sum of A1, A2 and A3 is same as A */
   if(fabs(A - A1 - A2 - A3)<eps)
   {
       return 1;
   }
   return 0;
}
int main()
{
    ll tes;
    scanf("%lld",&tes);
    for(ll cas=1; cas<=tes; cas++)
    {
        cle();
        scanf("%lld",&n);
        for(ll ii=1; ii<=n; ii++)
        {
            scanf(" %c",&type);
            if(type=='C')
            {
                ll x,y,radius;
                scanf("%lld%lld%lld",&x,&y,&radius);
                point v1,v2,v3,v4,circle;
                circle.x=x;
                circle.y=y;
                v1.x=x-radius;
                v1.y=y-radius;
                v2.x=x-radius;
                v2.y=y+radius;
                v3.x=x+radius;
                v3.y=y-radius;
                v4.x=x+radius;
                v4.y=y+radius;
                for(ll i=v1.x; i<=v3.x; i++)
                {
                    for(ll j=v1.y; j<=v2.y; j++)
                    {
                        point now_point;
                        now_point.x=i;
                        now_point.y=j;
                        ll ans=insideCircle(now_point,circle,radius);
                        if(ans==0 || ans==1)
                        {
                            if(ase[i][j]==0)
                            {
                                ase[i][j]=1;
                                count1++;
                            }
                        }
                    }
                }
            }
            if(type=='S')
            {
                ll x,y,length;
                scanf("%lld%lld%lld",&x,&y,&length);
                for(ll i=x;i<=x+length;i++)
                {
                    for(ll j=y;j<=y+length;j++)
                    {
                        if(ase[i][j]==0)
                        {
                            ase[i][j]=1;
                            count1++;
                        }
                    }
                }
            }
            if(type=='T')
            {
                ll x1,y1,x2,y2,x3,y3;
                scanf("%lld%lld%lld%lld%lld%lld",&x1,&y1,&x2,&y2,&x3,&y3);
                ll min_x=min(x1,min(x2,x3));
                ll maxi_x=max(x1,max(x2,x3));
                ll min_y=min(y1,min(y2,y3));
                ll maxi_y=max(y1,max(y2,y3));
                for(ll i=min_x;i<=maxi_x;i++)
                {
                    for(ll j=min_y;j<=maxi_y;j++)
                    {
                        if(isInside(x1,y1,x2,y2,x3,y3,i,j))
                        {
                            if(ase[i][j]==0)
                            {
                                ase[i][j]=1;
                                count1++;
                            }
                        }
                    }
                }
            }
        }
        cout<<count1<<endl;
    }
    return 0;
}
