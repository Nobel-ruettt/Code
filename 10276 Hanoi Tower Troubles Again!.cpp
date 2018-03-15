#include <bits/stdc++.h>
using namespace std;
vector<int>rod[60];
int n;
int check(int num)
{
    int i=1;
    while(num>0)
    {
        num-=i;
        i+=2;
    }
    if(num==0)
    {
        return 1;
    }
    return 0;
}
int solve()
{
    int count1=1;
    int falsee;
    while(1)
    {
        falsee=0;
        for(int i=0;i<n;i++)
        {
            if(rod[i].size() !=0 && check(rod[i][(rod[i].size())-1]+count1))
            {
                rod[i].push_back(count1);
                count1++;
                falsee=1;
                break;
            }
        }
        if(falsee==0)
        {
            for(int i=0;i<n;i++)
            {
                if(rod[i].size()==0)
                {
                    rod[i].push_back(count1);
                    count1++;
                    falsee=1;
                    break;
                }
            }
        }
        if(falsee==0)
        {
            break;
        }
    }
    return count1-1;
}
int main()
{
    int tes;
    scanf("%d",&tes);
    for(int i=1;i<=tes;i++)
    {
        scanf("%d",&n);
        if(n==1)
        {
            printf("1\n");
            continue;
        }
        for(int i=0;i<n;i++)
        {
            rod[i].clear();
        }
        printf("%d\n",solve());
    }
    return 0;
}
