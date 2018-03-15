#include<bits/stdc++.h>
#define ll long long
using namespace std;
void seive();
void factorful();
bool marked[1000001];
vector<int>prime;
void done();
int factor_count[11][1000005];
int factor_count2[11][1000005];
int factor[1000005];
int main()
{
    seive();
    factorful();
    done();
    int a,b,n,test,res;
    scanf("%d",&test);
    while(test--)
    {
        scanf("%d%d%d",&a,&b,&n);
        res=factor_count2[n][b]-factor_count2[n][a-1];
        if(n==0&&a==1)
        {
            res=1;
        }
        else if(n==0 && a>1)
        {
            res=0;
        }
        printf("%d\n",res);
    }



    prime.clear();


    return 0;
}
void seive()
{
    int n=1000000;
    for(int i=2;i<=n;i++)
    {
        if(marked[i]==false)
        {
            for(int j=i+i;j<=n;j+=i)
                marked[j]=true;
        }
    }
    for(int i=2;i<=n;i++)
    {
        if(marked[i]==false)
            prime.push_back(i);
    }
}
void factorful()
{
    for(ll i=0;i<prime.size();i++)
    {
        for(ll j=prime[i];j<=1000000;j+=prime[i])
            factor[j]++;
    }
}
void done()
{
    for(int i=1;i<11;i++)
    {
        for(int j=1;j<=1000000;j++)
        {
            if(factor[j]==i){
                factor_count[i][j]=1;
            }
        }
    }
    for(int i=1;i<11;i++)
    {
        for(int j=1;j<=1000000;j++)
        {
            factor_count2[i][j]=factor_count2[i][j-1]+factor_count[i][j];
        }
    }

}
