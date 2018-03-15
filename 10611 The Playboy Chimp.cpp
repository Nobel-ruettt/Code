#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll chimp,la_champ[50005],q,bun_height,maxi=0,mini=LLONG_MAX;
    scanf("%lld",&chimp);
    for(int i=0;i<chimp;i++)
    {
        scanf("%lld",&la_champ[i]);
        if(la_champ[i]>maxi)
        {
            maxi=la_champ[i];
        }
        if(mini>la_champ[i])
        {
            mini=la_champ[i];
        }
    }
    scanf("%lld",&q);
    ll ans1,ans2,index,begin,end,mid,keys;
    for(int i=0;i<q;i++)
    {
        scanf("%lld",&bun_height);
        if(bun_height==maxi)
        {
            index=-1,begin,mid,end;
            keys=maxi;
            begin=0;
            end=chimp-1;
            while(begin<=end)
            {
                mid=(begin+end)/2;
                if(la_champ[mid]==keys)
                {
                    index=mid;
                    end=mid-1;
                }
                else if(keys>la_champ[mid])
                {
                    begin=mid+1;
                }
                else if(keys<la_champ[mid])
                {
                    end=mid-1;
                }
            }
            printf("%lld X\n",la_champ[index-1]);
        }
        else if(bun_height>maxi)
        {
            ans1=maxi;
            ans2=-1;
            printf("%lld X\n",ans1);
        }
        else if(bun_height<mini)
        {
            ans1=-1;
            ans2=mini;
            printf("X %lld\n",ans2);
        }
        else if(bun_height==mini)
        {
            index=-1;
            begin=0;
            end=chimp-1;
            keys=mini;
            while(begin<=end)
            {
                mid=(begin+end)/2;
                if(la_champ[mid]==keys)
                {
                    index=mid;
                    begin=mid+1;
                }
                else if(keys>la_champ[mid])
                {
                    begin=mid+1;
                }
                else if(keys<la_champ[mid])
                {
                    end=mid-1;
                }
            }
            ans1=-1;
            ans2=la_champ[index+1];
            printf("X %lld\n",ans2);
        }
        else if(bun_height>mini && bun_height<maxi)
        {
            index=-1;//lower bound
            begin=0;
            end=chimp-1;
            keys=bun_height;
            ///printf("maintate dhukse\n");
            while(begin<=end)
            {
                mid=(begin+end)/2;
                if(la_champ[mid]==keys)
                {
                    index=mid;
                    end=mid-1;
                }
                else if(keys>la_champ[mid])
                {
                    begin=mid+1;
                }
                else if(keys<la_champ[mid])
                {
                    end=mid-1;
                }
            }
            if(index==-1)
            {
                ans1=la_champ[begin-1];
                ans2=la_champ[begin];
                printf("%lld %lld\n",ans1,ans2);
            }
            else if(index!=-1)
            {
                ///printf("maintar maintate dhukse\n");
                ans1=la_champ[index-1];
                index=-1;
                begin=0;
                end=chimp-1;
                keys=bun_height;
                while(begin<=end)
                {
                    mid=(begin+end)/2;
                    if(la_champ[mid]==keys)
                    {
                        index=mid;
                        begin=mid+1;
                    }
                    else if(keys>la_champ[mid])
                    {
                        begin=mid+1;
                    }
                    else if(keys<la_champ[mid])
                    {
                        end=mid-1;
                    }
                }
                ans2=la_champ[index+1];
                printf("%lld %lld\n",ans1,ans2);
            }
        }
    }
    return 0;
}
