#include <bits/stdc++.h>
using namespace std;
#define ll long
#define maxi 150000
ll arr[maxi+100];
ll arr2[maxi+100];
ll seg[3*maxi+100];
ll tes,n,q;
void cle()
{
    for(ll i=0; i<=maxi; i++)
    {
        arr[i]=0;
        arr2[i]=0;
    }
}
void build(ll node,ll b,ll e)
{
    if(b==e)
    {
        seg[node]=arr2[b];
        //cout<<"node "<<node<<" b "<<b<<" e "<<e<<" seg[node] "<<seg[node]<<endl;
        return ;
    }
    build(node*2,b,((long)((b+e)/2)));
    build(node*2+1,((long)((b+e)/2)+1),e);
    seg[node]=seg[node*2]+seg[node*2+1];
    //cout<<"node "<<node<<" b "<<b<<" e "<<e<<" seg[node] "<<seg[node]<<endl;
}
void update(ll node,ll b,ll e,ll pos)
{
    if (pos > e || pos < b)
    {
        return;
    }
    if (b >= pos && e <= pos)
    {
        seg[node] = arr2[pos];
        return;
    }
    update(node*2,b,((long)((b+e)/2)),pos);
    update(node*2+1,((long)((b+e)/2)+1),e,pos);
    seg[node]=seg[node*2]+seg[node*2+1];
}
ll query(ll node,ll b,ll e,ll value)
{
    if(b==e)
    {
        return b;
    }
    if(value<=seg[node*2])
    {
        return query(node*2,b,((long)((b+e)/2)),value);
    }
    else if(value>seg[node*2])
    {
        return query(node*2+1,((long)((b+e)/2))+1,e,value-seg[node*2]);
    }
}
void in_numbers()
{
    for(ll j=1; j<=n; j++)
    {
        scanf("%ld",&arr[j]);
        arr2[j]=1;
    }
}
void in_queries()
{
    char c,c1;
    ll add_num,index;
    for(ll j=1; j<=q; j++)
    {
       // cout<<"j "<<j<<endl;
        getchar();
        scanf("%c %ld",&c,&add_num);
        ///cout<<"c "<<c<<endl;
        //cout<<"add num "<<add_num<<endl;
        if(c=='a')
        {
            n++;
            arr[n]=add_num;
            arr2[n]=1;
            update(1,1,maxi,n);
            ///cout<<"seg[1] "<<seg[1]<<endl;
        }
        else if(c=='c')
        {
            ///cout<<"add_num"<<" "<<add_num<<"seg[1] "<<seg[1]<<endl;
            if(add_num>seg[1])
            {
                printf("none\n");
            }
            else
            {
                index=query(1,1,maxi,add_num);
                //cout<<"index "<<index<<endl;
                printf("%ld\n",arr[index]);
                arr2[index]=0;
                update(1,1,maxi,index);
            }
        }
    }
}
int main()
{
    scanf("%ld",&tes);
    for(ll i=1; i<=tes; i++)
    {
        cle();
        scanf("%ld%ld",&n,&q);
        printf("Case %ld:\n", i);
        in_numbers();
        build(1,1,maxi);
        //cout<<"build kaj korse "<<endl;
        in_queries();
        for(ll j=0;j<=n;j++)
        {
            arr2[j]=0;
        }
        build(1,1,maxi);
    }
    return 0;
}
