#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <bitset>
typedef struct nod
{
    int a,b,color;
} node;
node edge[200010];
using namespace std;
bool op(node a,node b)
{
    return a.color<b.color;
}
int n,m;
int father[100010];
int getfather(int x)
{
    if (father[x]!=x) father[x]=getfather(father[x]);
    return father[x];
}
void link(int x,int y)
{
    father[getfather(x)]=getfather(y);
}
int  kruskal1 ()
{
    for (int i=1;i<=n;i++) father[i]=i;
    int num = 0 , all = 0 ,to=0;
    for (int i=1;i<=m;i++)
    if (getfather(edge[i].a)!=getfather(edge[i].b))
    {
        link(edge[i].a,edge[i].b);
        if (edge[i].color) num++;
        to++;
    }
    if (to!=n-1) return -1;
    else  return num;
}
int  kruskal2 ()
{
    for (int i=1;i<=n;i++) father[i]=i;
    int num = 0 , all = 0 ,tot=0;
    for (int i=m;i>=1;i--)
    if (getfather(edge[i].a)!=getfather(edge[i].b))
    {
        link(edge[i].a,edge[i].b);
        if (edge[i].color) num++;
        tot++;
    }
    if (tot!=n-1) return -1;
    else  return num;
}
int main()
{
    int all = 0 ;
    bitset<100010>fbn;
    fbn.reset();
    int a=1,b=1,c;
    fbn[1]=1;
    while (1)
    {
        c=a+b;
        if (c>=100010) break;
        fbn[c]=1;
        a=b;
        b=c;
    }
    int t;
    scanf("%d",&t);
    for (int tt=1;tt<=t;tt++)
    {
        scanf("%d%d",&n,&m);
        for (int i=1;i<=m;i++) scanf("%d%d%d",&edge[i].a,&edge[i].b,&edge[i].color);
        printf("Case #%d: ",tt);
        sort(&edge[1],&edge[m+1],op);
        int b1=kruskal1();
        if (b1<0)
        {
            printf("No\n");
            continue;
        }
        int b2=kruskal2();
        bool done=false;
        for (int i=b1;i<=b2;i++)
        if (fbn[i])
        {
            done=true;
            break;
        }
        if (done) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
