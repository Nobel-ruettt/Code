#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define max1 65600
ll digit[max1+1];
void cumsum()
{
    digit[0]=0;
    for(ll i=1;i<=max1;i++)
    {
        digit[i]=digit[i-1]+i;
    }
   /// cout<<"3"<<"    "<<digit[3]<<endl;
    /*for(ll i=0;i<=max1;i++)
    {
        printf("index : %lld ase : %lld\n",i,digit[i]);
    }*/
}
int main()
{
    cumsum();
    ll tes,di,begin,end,index,key,mid;
    scanf("%lld",&tes);
    for(int i=1;i<=tes;i++)
    {
        scanf("%lld",&di);
        di+=1;
        if(di==1)
        {
            printf("1\n");
        }
        begin=0;
        end=max1;
        index=-1;
        key=di;
        while(begin<=end)
        {
            mid=(begin+end)/2;
            if(key==digit[mid])
            {
                index=mid;
                end=mid-1;
            }
            if(key>digit[mid])
            {
                begin=mid+1;
            }
            else if(key<digit[mid])
            {
                end=mid-1;
            }
        }
        printf("Begin %lld\n",begin);
    }
    return 0;
}
