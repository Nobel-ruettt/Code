#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int mapl[81][81],dist[81][81];
bool use[81];
int main()
{
    int t,n,m,tot;
    scanf("%d",&t);
    for (int tt=1;tt<=t;tt++)
    {
        printf("Case #%d:\n",tt);
        scanf("%d%d",&n,&m);
        int all = 0 ;
        bool bq=false;
        memset(mapl,0,sizeof(mapl));
        memset(dist,-1,sizeof(dist));
        tot=0;
        for (int i=1;i<n;i++)
        {
            tot += i;
            mapl[i][i+1]=i;
            dist[i][i+1]=i;
        }


        for (int i=n;i<n+3;i++)
        if ((tot+i)%3==0)
        {
            mapl[n][1]=i;
            dist[n][1]=i;
            break;
        }

        memset(use,0,sizeof(use));
        use[mapl[n][1]]=true;

        for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
        if (i!=j)
        for (int k=1;k<=n;k++)
        if (i!=k&&j!=k)
        if (dist[j][i]>0&&dist[i][k]>0)
        if (dist[j][k]==-1) dist[j][k]=dist[j][i]+dist[i][k];

//        for(int i=1;i<=n;i++)
//        {
//            cout<<"Node : "<<i<<endl;
//            for(int j=1;j<=n;j++)
//            {
//
//                    cout<<j<<" : "<<dist[i][j]<<endl;
//            }
//        }

        for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
        if (dist[i][j]>-1) dist[i][j]%=3;

        //for (int i=1;i<=n;i++)
        //for (int j=1;j<=n;j++) printf("%d %d %d\n",i,j,dist[i][j]);

        for (int i=n;i<=m;i++)
        {
            if (!use[i])
            {
                for (int j=1;j<=n;j++)
                for (int k=1;k<=n;k++)
                if (!use[i])
                if (mapl[j][k]==0&&mapl[k][j]==0&&dist[j][k]>-1&&dist[j][k]%3==i%3)
                {
                    mapl[j][k]=i;
                    use[i]=true;
                }
            }
            if (!use[i])
            {
                printf("-1\n");
                bq=true;
                break;
            }
        }

        if (!bq)
        for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
        if (mapl[i][j]>0) printf("%d %d %d\n",i,j,mapl[i][j]);
    }

    return 0;
}
