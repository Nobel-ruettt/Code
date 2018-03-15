#include <stdio.h>
int main()
{
    long long n,x,r,rm,dv,p,c;
    scanf("%lld",&n);
    x=n;
    c=0;
    dv=1;
    while (dv!=0)
    {
        c++;
        p = dv;
        dv =(long long)x/10;
        x = (long long)x/10;
    }
    if (c==1){p=n+0; r=p%10; rm=p+1;}
    else if (c==2) { p=n+10; r=p%10; rm=p-r;}
    else if (c==3) { p=n+100; r=p%100;  rm=p-r; }
    else if (c==4) { p=n+1000; r=p%1000;  rm=p-r; }
    else if (c==5) { p=n+10000; r=p%10000;  rm=p-r; }
    else if (c==6) { p=n+100000;  r=p%100000;  rm=p-r;}
    else if (c==7) { p=n+1000000; r = p%1000000; rm=p-r;}
    else if (c==8) { p=n+10000000; r=p%10000000;  rm=p-r;}
    else if (c==9) { p=n+100000000; r=p%100000000; rm=p-r;}
    else if (c==10) { p=n+100000000; r=p%100000000;  rm=p-r;}

    printf("%lld",rm-n);
    return 0;
}
