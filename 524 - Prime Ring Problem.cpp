#include <bits/stdc++.h>
using namespace std;
map<int ,int>prime;
int taken[40];
int number;
void primes()
{
     prime[2]=1;
     prime[3]=1;
     prime[5]=1;
     prime[7]=1;
     prime[11]=1;
     prime[13]=1;
     prime[17]=1;
     prime[19]=1;
     prime[23]=1;
     prime[29]=1;
     prime[31]=1;
     prime[37]=1;
     prime[41]=1;
}
vector<int>ans;
void solve()
{
    if(ans.size()==number && prime[ans[ans.size()-1]+1]==1)
    {
        printf("%d",ans[0]);
        for(int i=1;i<ans.size();i++)
        {
            printf(" %d",ans[i]);
        }
        printf("\n");
    }
    for(int i=1;i<=number;i++)
    {
         if(taken[i]==0 && prime[ans[ans.size()-1]+i]==1)
         {
             taken[i]=1;
             ans.push_back(i);
             solve();
             ans.pop_back();
             taken[i]=0;
         }
    }
}
 int main()
 {
    int cases=1;
    primes();
    ans.push_back(1);
    taken[1]=1;
    while(cin>>number)
    {
        printf("Case %d:\n",cases);
        solve();
        cases++;
        printf("\n");
    }
    return 0;
 }
