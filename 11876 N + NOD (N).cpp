#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll N = 1010;
ll status[1010];
ll prime[1010];
void sieve()
{
    ll i, j,count1=0;
    for( i = 2; i <= N; i++ )
    {
        if( status[i] == 0 )
        {
            for( j = 2 * i; j <= N; j += i )
                status[j] = 1;
        }
    }#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll N = 1010;
ll status[1010];
ll prime[1010];
void sieve()
{
    ll i, j,count1=0;
    for( i = 2; i <= N; i++ )
    {
        if( status[i] == 0 )
        {
            for( j = 2 * i; j <= N; j += i )
                status[j] = 1;
        }
    }
    for( i = 2; i <= N; i++ )
    {
        if( status[i] == 0 )
        {
            prime[count1]=i;
            count1++;
        }
    }
}
ll div(ll number)
{
    ll num=number;
    ll power;
    ll pow=1;
    ll sq=sqrt(num);
    for(int i=0; prime[i]<=sq; i++)
    {
        if(num%prime[i]==0)
        {
            power=0;
            while(num%prime[i]==0)
            {
                num=num/prime[i];
                power++;
            }
            power++;
            pow=pow*power;
        }
    }
    if(num!=1)
    {
        power=2;
        pow=pow*power;
    }
    return pow;
}
int main()
{
    sieve();
    ll nod[64726];
    nod[0]=1;
    nod[1]=2;
    int count2=2;
    while(1)
    {
        nod[count2]=nod[count2-1]+div(nod[count2-1]);
        ///printf("count2 %d nod %lld\n",count2,nod[count2]);
        if(nod[count2]> 1000000)
        {
            break;
        }
        count2++;
    }
    ll tes,A,B,begin,end,mid,key,index,up,low;
    cin>>tes;
    for(int i=1; i<=tes; i++)
    {
        cin>>A>>B;
        begin=0;
        end=count2;
        index=-1;
        key=A;
        while(begin<=end)
        {
            mid=(begin+end)/2;
            if(nod[mid]==key)
            {
                index=mid;
                begin=mid+1;
            }
            else if(key>nod[mid])
            {
                begin=mid+1;
            }
            else if(key<nod[mid])
            {
                end=mid-1;
            }
        }
        if(index!=-1)
        {
            up=index;
        }
        else if(index==-1)
        {
            up=begin;
        }
        ///printf("up at %lld\n",up);
        begin=0;
        end=count2;
        index=-1;
        key=B;
        while(begin<=end)
        {
            mid=(begin+end)/2;
            if(nod[mid]==key)
            {
                index=mid;
                end=mid-1;
            }
            else if(key>nod[mid])
            {
                begin=mid+1;
            }
            else if(key<nod[mid])
            {
                end=mid-1;
            }
        }
        if(index!=-1)
        {
            low=index;
        }
        else if(index==-1)
        {
            low=end;
        }
        printf("Case %d: %lld\n",i,low-up+1);
    }
    return 0;
}

    for( i = 2; i <= N; i++ )
    {
        if( status[i] == 0 )
        {
            prime[count1]=i;
            count1++;
        }
    }
}
ll div(ll number)
{
    ll num=number;
    ll power;
    ll pow=1;
    ll sq=sqrt(num);
    for(int i=0; prime[i]<=sq; i++)
    {
        if(num%prime[i]==0)
        {
            power=0;
            while(num%prime[i]==0)
            {
                num=num/prime[i];
                power++;
            }
            power++;
            pow=pow*power;
        }
    }
    if(num!=1)
    {
        power=2;
        pow=pow*power;
    }
    return pow;
}
int main()
{
    sieve();
    ll nod[64726];
    nod[0]=1;
    nod[1]=2;
    int count2=2;
    while(1)
    {
        nod[count2]=nod[count2-1]+div(nod[count2-1]);
        if(nod[count2]> 1000000)
        {
            break;
        }
        count2++;
    }
    ll tes,A,B,begin,end,mid,key,index,up,low;
    cin>>tes;
    for(int i=1; i<=tes; i++)
    {
        cin>>A>>B;
        begin=0;
        end=count2;
        index=-1;
        key=A;
        while(begin<=end)
        {
            mid=(begin+end)/2;
            if(nod[mid]==key)
            {
                index=mid;
                begin=mid+1;
            }
            else if(key>nod[mid])
            {
                begin=mid+1;
            }
            else if(key<nod[mid])
            {
                end=mid-1;
            }
        }
        if(index!=-1)
        {
            up=index;
        }
        else if(index==-1)
        {
            up=begin;
        }
        begin=0;
        end=count2;
        index=-1;
        key=B;
        while(begin<=end)
        {
            mid=(begin+end)/2;
            if(nod[mid]==key)
            {
                index=mid;
                end=mid-1;
            }
            else if(key>nod[mid])
            {
                begin=mid+1;
            }
            else if(key<nod[mid])
            {
                end=mid-1;
            }
        }
        if(index!=-1)
        {
            low=index;
        }
        else if(index==-1)
        {
            low=end;
        }
        printf("Case %d: %lld\n",i,low-up+1);
    }
    return 0;
}
