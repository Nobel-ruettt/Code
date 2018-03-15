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
long long tes,a,b,n,m;
void set_mod()
{
    if(m==1)
    {
        mod=10;
    }
    else if(m==2)
    {
        mod=100;
    }
    else if(m==3)
    {
        mod=1000;
    }
    else if(m==4)
    {
        mod=10000;
    }
}
void set_matrix_A()
{
    mat[0][0]=1;
    mat[0][1]=1;
    mat[1][0]=1;
    mat[1][1]=0;
}
int main()
{
    cin>>tes;
    for(long long i=1; i<=tes; i++)
    {
        cin>>a>>b>>n>>m;
        set_mod();
        set_matrix_A();
        if(n<=2)
        {
            if(n==0)
            {
                printf("Case %lld: %lld\n",i,a);
            }
            else if(n==1)
            {
                printf("Case %lld: %lld\n",i,b);
            }
            else if(n==2)
            {
                printf("Case %lld: %lld\n",i,a+b);
            }
            continue;
        }
        matpower(n-1);
        long long result=0;
        result = (result + (res[0][0]*b)%mod)%mod;
        result=  (result + (res[0][1]*a)%mod)%mod;
        printf("Case %lld: %lld\n",i,result);
    }
    return 0;
}
