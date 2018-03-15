#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll heights[10010];
int main()
{
    ll width,height,maxi,sum,next;
    while(scanf("%lld%lld",&height,&width)==2)
    {
        if(width==0&&height==0)
        {
            break;
        }
        for(ll i=0;i<width;i++)
        {
            scanf("%lld",&heights[i]);
        }
        if(width==1)
        {
            cout<<height-heights[0]<<endl;
            continue;
        }
        maxi=0;
        sum=0;
        if(heights[1]>heights[0])
        {
            sum+=(heights[1]-heights[0]);
            next=0;
            if(heights[0]>maxi)
            {
                maxi=heights[0];
            }
        }
        else if(heights[1]<heights[0])
        {
            sum+=heights[0]-heights[1];
            next=heights[0]-heights[1];
            if(heights[0]>maxi)
            {
                maxi=heights[0];
            }
        }
        else if(heights[1]==heights[0])
        {
            next=0;
            if(maxi<heights[0])
            {
                maxi=heights[0];
            }
        }
        //cout<<sum<<" "<<next<<" "<<maxi<<endl;
        ll i;
        for(i=1;i<width-1;i++)
        {
            if(heights[i+1]>heights[i])
            {
                if(next>=(heights[i+1]-heights[i]))
                {
                    next=next-(heights[i+1]-heights[i]);
                }
                else if(next<(heights[i+1]-heights[i]))
                {
                    sum+=(heights[i+1]-heights[i]-next);
                    next=0;
                }
            }
            else if(heights[i+1]<heights[i])
            {
                sum+=(heights[i]-heights[i+1]);
                next=next+(heights[i]-heights[i+1]);

            }
            else if(heights[i+1]==heights[i])
            {
                next=next;
            }
            if(heights[i]>maxi)
            {
                maxi=heights[i];
            }
            //cout<<sum<<" "<<next<<" "<<maxi<<endl;
        }
        if(maxi<heights[i])
        {
            maxi=heights[i];
        }
        if(maxi<=height)
        {
            sum+=height-maxi;
        }
      cout<<sum<<endl;
    }
    return 0;
}
