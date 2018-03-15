#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll mass[12];
ll chambers[6][2];
int main()
{
    ll cham,mas,count1=1,sum,count2,cmi,count3,mas_count,cham_count;
    double averag,sums,dif,cmi_2;
    int i,j;
    while(scanf("%lld%lld",&cham,&mas)!=EOF)
    {
        sum=0;
        for(i=0; i<mas; i++)
        {
            scanf("%lld",&mass[i]);
            sum+=mass[i];
        }
        averag=(double)(sum)/(double)(cham);
        ///printf("average %lf\n",averag);
        sort(mass,mass+mas);
        printf("Set #%lld\n",count1);
        if(mas<cham || mas==cham)
        {
            count2=mas;
            count3=0;
            sums=0.00;
            while(1)
            {
                if(count2==0)
                {
                    break;
                }
                chambers[count3][0]=mass[count2-1];
                cmi_2=(double)(mass[count2-1]);
                dif=fabs(cmi_2-averag);
                sums+=dif;
                printf("%lld: %lld\n",count3,mass[count2-1]);
                count3++;
                count2--;
            }
            if(count3-1!=cham-1)
            {
                while(1)
                {
                    if(count3==cham)
                    {
                        break;
                    }
                     printf("%lld: \n",count3);
                     sums+=averag;
                     count3++;
                }
            }
            printf("IMBALANCE = %0.5lf\n",sums);
        }
        else if(mas==cham*2)
        {
            count2=0;
            sums=0.00;
            for(i=0,j=mas-1;i<j;i++,j--)
            {
                printf("%lld: %lld %lld\n",count2,mass[i],mass[j]);
                cmi=mass[i]+mass[j];
                cmi_2=double(cmi);
                dif=fabs(averag-cmi_2);
                sums=sums+dif;
                count2++;
            }
            printf("IMBALANCE = %0.5lf\n",sums);
        }
        else if(mas>cham && mas<cham*2)
        {
            mas_count=mas;
            cham_count=cham;
            count2=0;
            sums=0.00;
            while(1)
            {
                if(cham_count*2==mas_count)
                {
                    break;
                }
                printf("%lld: %lld\n",count2,mass[mas_count-1]);
                cmi_2=(double)(mass[mas_count-1]);
                dif=fabs(averag-cmi_2);
                sums+=dif;
                mas_count--;
                cham_count--;
                count2++;
            }
          ///  printf("mas_count %lld cham_count %lld count2 %lld\n",mas_count,cham_count,count2);
            for(i=0,j=mas_count-1;i<j;i++,j--)
            {
                  printf("%lld: %lld %lld\n",count2,mass[i],mass[j]);
                  cmi=mass[i]+mass[j];
                  cmi_2=(double)(cmi);
                  dif=fabs(averag-cmi_2);
                  sums+=dif;
                  count2++;
            }
            printf("IMBALANCE = %0.5lf\n",sums);
        }
        count1++;
        printf("\n");
    }
    return 0;
}
