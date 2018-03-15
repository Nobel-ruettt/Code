#include <bits/stdc++.h>
using namespace std;
#define mat_size 2
long long mod, col_num = mat_size, row_num = mat_size;
long long mat[mat_size][mat_size], temp[mat_size][mat_size], res[mat_size][mat_size];
void matpower(long long pwr)
{
    long long i, j, k, s;
    if (pwr == 0)
    {
        for (i = 0; i < row_num; i++)
        {
            for (j = 0; j < col_num; j++)
            {
                if (i != j)
                {
                    res[i][j] = 0;
                }
                else
                {
                    res[i][j] = 1;
                }
            }
        }
        return ;
    }
    matpower(pwr/2);
    for (i = 0; i < col_num; i++)
    {
        for (j = 0; j < row_num; j++)
        {
            temp[i][j] = res[i][j];
        }
    }
    for (i = 0; i < col_num; i++)
    {
        for (j = 0; j < row_num; j++)
        {
            s = 0;
            for (k = 0; k < row_num; k++)
            {
                s = (s + (temp[i][k]*temp[k][j])%mod)%mod;
            }
            res[i][j] = s;
        }
    }
    if (pwr%2 == 0)
    {
    }
    else
    {
        for (i = 0; i < row_num; i++)
        {
            for (j = 0; j < row_num; j++)
            {
                temp[i][j] = res[i][j];
            }
        }
        for (i = 0; i < row_num; i++)
        {
            for (j = 0; j < col_num; j++)
            {
                s = 0;
                for (k = 0; k < col_num; k++)
                    s = (s + (mat[i][k]*(temp[k][j]))%mod)%mod;
                res[i][j] = s;
            }
        }
    }
}
long long tes,n,x,m,y,k,first_sting_length,last_sting_length,first_index,last_index,dif,upor,niche;
void take_A()
{
    mat[0][0] = 1;
    mat[0][1] = 1;
    mat[1][0] = 1;
    mat[1][1] = 0;
}
int main ()
{
    mod=1000000007;
    take_A();
    /*matpower(3);
    for(long long i=0;i<row_num;i++)
    {
        for(long long j=0;j<col_num;j++)
        {
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }*/
    scanf("%lld",&tes);
    for(int i=1; i<=tes; i++)
    {
        scanf("%lld%lld%lld%lld%lld",&n,&x,&m,&y,&k);
        if(n>m)
        {
            if(x<y)
            {
                printf("Case %d: Impossible\n",i);
                continue;
            }
            if(m+1==n)
            {
                first_sting_length=y;
                first_index=m;
                last_sting_length=x;
                last_index=n;
            }
            else
            {
                first_sting_length=y;
                first_index=m;
                dif=n-m-1;
                matpower(dif);
                upor=x-(y*res[0][1]);
                niche=res[0][0];
                if(upor%niche!=0)
                {
                    printf("Case %d: Impossible\n");
                    continue;
                }
                last_index=m+1;
                last_sting_length=upor/niche;
            }
        }
        else if(m>n)
        {
            if(x>y)
            {
                printf("Case %d: Impossible\n",i);
                continue;
            }
            if(n+1==m)
            {
                first_sting_length=x;
                first_index=n;
                last_sting_length=y;
                last_index=m;
                ///cout<<first_index<<" "<<first_sting_length<<" "<<last_index<<" "<<last_sting_length<<endl;
            }
            else
            {
                first_sting_length=x;
                first_index=n;
                dif=m-n-1;
                matpower(dif);
                upor=y-(x*res[0][1]);
                niche=res[0][0];
                if(upor%niche!=0)
                {
                    printf("Case %d: Impossible\n");
                    continue;
                }
                last_index=n+1;
                last_sting_length=upor/niche;
                ///cout<<first_index<<" "<<first_sting_length<<" "<<last_index<<" "<<last_sting_length<<endl;
            }
        }

    }
    return 0;
}
