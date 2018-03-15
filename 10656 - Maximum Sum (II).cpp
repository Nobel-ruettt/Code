#include <bits/stdc++.h>
using namespace std;
int main()
{
    int num,nums,sum;
    vector<int>pos;
    while(scanf("%d",&num)==1)
    {
        if(num==0)
        {
            break;
        }
        sum=0;
        for(int i=0;i<num;i++)
        {
            scanf("%d",&nums);
            if(nums>0)
            {
                pos.push_back(nums);
            }
            sum+=nums;
        }
        if(sum==0)
        {
            printf("0\n");
        }
        else
        {
            printf("%d",pos[0]);
            for(int i=1;i<pos.size();i++)
            {
                printf(" %d",pos[i]);
            }
        }
        printf("\n");
        pos.clear();
    }
    return 0;
}
