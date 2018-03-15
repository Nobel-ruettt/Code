#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll q,depth,kth_ball,node,toggle,obosta;
    scanf("%lld",&q);
    for(int i=0; i<=q; i++)
    {
        scanf("%lld",&depth);
        if(depth==-1)
        {
            break;
        }
        scanf("%lld",&kth_ball);
        ///first how many toggling did the first node had
        node=1;
        toggle=kth_ball-1;
        obosta=(toggle)%2;
        if(obosta==1)
        {
            node=node*2+1;
            toggle=(long long)(toggle/2);
        }
        else if(obosta==0)
        {
            node=node*2;
            if(toggle%2==1)
            {
                toggle=((long long)(toggle/2))+1;
            }
            else if(toggle%2==0)
            {
                toggle=toggle/2;
            }
        }
        ///printf("toggle %lld node %lld\n",toggle,node);
        for(int k=2; k<depth; k++)
        {
            obosta=(toggle)%2;
            if(obosta==1)
            {
                node=node*2+1;
                toggle=(long long)(toggle/2);
            }
            else if(obosta==0)
            {
                node=node*2;
                if(toggle%2==1)
                {
                    toggle=((long long)(toggle/2))+1;
                }
                else if(toggle%2==0)
                {
                    toggle=toggle/2;
                }
            }
            ///printf("toggle %lld node %lld\n",toggle,node);
        }
        printf("%lld\n",node);
    }
    return 0;
}
