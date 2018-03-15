#include <bits/stdc++.h>
using namespace std;
int main()
{
    int tes,n,sec_bes,tot,first_bes,bes;
    int arr[1004];
    scanf("%d",&tes);
    for(int i=1;i<=tes;i++)
    {
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            scanf("%d",&arr[i]);
        }
        sort(arr,arr+n);
        for(int i=0;i<n;i++)
        {
            printf("%d ",arr[i]);
        }
        printf("\n\n");
        if(n%2==0)
        {
            sec_bes=((n/2)+((n/2)-1))*arr[1];
            first_bes=((n/2)-1)*arr[0];
            bes=0;
            for(int i=3;i<n;i+=2)
            {
                bes+=arr[i];
            }
            tot=sec_bes+first_bes+bes;
            printf("%d\n",tot);
            int count1=n-2;
            for(int i=1;i<=((n/2)-1);i++)
            {
                printf("%d %d\n",arr[0],arr[1]);
                printf("%d\n",arr[0]);
                printf("%d %d\n",arr[count1],arr[count1+1]);
                printf("%d\n",arr[1]);
                count1-=2;
            }
            printf("%d %d\n",arr[0],arr[1]);
        }
        if(n%2==1)
        {
            sec_bes=(((n-1)/2)+(((n-1)/2)-1))*arr[1];
            first_bes=((n-1)/2)*arr[0];
            bes=0;
            for(int i=2;i<n;i+=2)
            {
                bes+=arr[i];
            }
            tot=sec_bes+first_bes+bes;
            printf("%d\n",tot);
            int count1=n-2;
            for(int i=1;i<=(((n-1)/2)-1);i++)
            {
                printf("%d %d\n",arr[0],arr[1]);
                printf("%d\n",arr[0]);
                printf("%d %d\n",arr[count1],arr[count1+1]);
                printf("%d %d\n",arr[1]);
                count1-=2;
            }
            printf("%d %d\n",arr[0],arr[1]);
            printf("%d\n",arr[0]);
            printf("%d %d\n",arr[0],arr[2]);
        }
    }
    return 0;
}
