#include <bits/stdc++.h>
#include <string>
using namespace std;
int bi[20];
int h;
int n;
string str;
vector<string>all;
void solve(int start,int pos)
{
    if(pos==h)
    {
        str="";
        for(int i=0; i<n; i++)
        {
            if(bi[i]==0)
            {
                str+="0";
            }
            else if(bi[i]==1)
            {
                str+="1";
            }
        }
        ///cout<<str<<endl;
        all.push_back(str);
        return ;
    }
    else
    {
        for(int i=start; i<n; i++)
        {
            if(bi[i]==0)
            {
                bi[i]=1;
                solve(i+1,pos+1);
                bi[i]=0;
            }
        }
    }
}
int main()
{
    int tes;
    scanf("%d",&tes);
    for(int i=1;i<=tes;i++)
    {
        scanf("%d%d",&n,&h);
        for(int i=0;i<=n;i++)
        {
            bi[i]=0;
        }
        solve(0,0);
        reverse(all.begin(),all.end());
        for(int i=0;i<all.size();i++)
        {
            cout<<all[i]<<endl;
        }
        all.clear();
    }
    return 0;
}
