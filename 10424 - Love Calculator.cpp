#include<bits/stdc++.h>
using namespace std;
int main()
{
    char a[30],b[30];
    int add1,add2,val,sum1,main_add1;
    double result;
    while(gets(a))
    {
        gets(b);
        add1=0;
        for(int i=0; i<strlen(a); i++)
        {
            if(a[i]>='A' && a[i]<='Z')
            {
                val=a[i]-64;
            }
            else if(a[i]>='a'&&a[i]<='z')
            {
                val=a[i]-96;
            }
            else
            {
                val=0;
            }
            add1+=val;
        }
        while(add1>9)
        {
            sum1=add1;
            main_add1=0;
            while(sum1!=0)
            {
                main_add1+=sum1%10;
                sum1/=10;
            }
            add1=main_add1;
        }
        add2=0;
        for(int i=0; i<strlen(b); i++)
        {
            if(b[i]>='A' && b[i]<='Z')
            {
                val=b[i]-64;
            }
            else if(b[i]>='a'&&b[i]<='z')
            {
                val=b[i]-96;
            }
            else
            {
                val=0;
            }
            add2+=val;
        }
        while(add2>9)
        {
            sum1=add2;
            main_add1=0;
            while(sum1!=0)
            {
                main_add1+=sum1%10;
                sum1/=10;
            }
            add2=main_add1;
        }
        if(add1>add2)
            result = ((double)add2*100.00)/(double)add1;
        else
            result = ((double)add1*100.00)/(double)add2;
        printf("%0.2lf%%\n",result);
    }
    return 0;
}
